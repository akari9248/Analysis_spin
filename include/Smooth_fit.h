using namespace std;
class Chebyshev {
public: 
   Chebyshev(int n, double xmin, double xmax) : 
      fA(log(xmin)), fB(log(xmax)),
      fT(std::vector<double>(n) )  {}

   double operator() (const double * xx, const double *p) { 
      double x =-1+ 2.0 *( log(xx[0]) - fA)/(fB-fA);
      int order = fT.size(); 
      if (order == 0) return exp(p[0]); 
      if (order == 1) return exp(p[0] + x*p[1]); 
      // build the polynomials
      fT[0] = 1;
      fT[1] = x; 
      for (int i = 1; i< order-1; ++i) { 
         fT[i+1] =  2 *x * fT[i] - fT[i-1]; 
      }
      double sum = p[0]*fT[0]; 
      for (int i = 1; i<= order-1; ++i) { 
         sum += p[i] * fT[i]; 
      }
      return exp(sum); 
   }

private: 
   double fA; 
   double fB; 
   std::vector<double> fT; // polynomial
   std::vector<double> fC; // coefficients
};
TF1 * GetSmoothFit(TH1D *hist,double xmin,double xmax,int maxdegree=8,bool autoStop=true,double x2nmin=10000,TString options="Q0SNRE"){
  vector<double> pars;
  for(int i=0;i<maxdegree+3;i++){
    pars.push_back(1);
  }
  Chebyshev * cheb = new Chebyshev(maxdegree,xmin,xmax);
  TF1 *f = new TF1(hist->GetName()+TString::Format("smooth_fit"), cheb, xmin, xmax, maxdegree);
  cout<<hist->GetName()+TString::Format("smooth_fit")<<endl;
  double x2n = hist->GetNbinsX(), error = hist->GetNbinsX();
  int degree;
  for (degree = 2; degree <= maxdegree; degree++) {    
    for (int i = 0; i <= degree; ++i){
      f->ReleaseParameter(i);
      f->SetParameter(i, pars.at(i));
    }
    for (int i = degree+1; i < maxdegree; ++i)
      f->FixParameter(i, 0);
    TFitResultPtr r = hist->Fit(f, options);
    double chi2 = r->Chi2();
    if (!isnormal(chi2)) {
      //hist->Print("all");
      cerr << "Fit aborted (chi2 = " << chi2 << ")\n";
      continue;
    }
    double ndf = r->Ndf();
    int status = r->Status();
    if (status != 0) {
      //hist->Print("all");
      cerr << "Fit aborted (status = " << status << ")\n";
      continue;
    }
    for (int i = 0; i < degree; ++i)
      pars.at(i)=f->GetParameter(i);
    auto lastx2n = x2n;
    x2n = chi2 / ndf;
    error = sqrt(2. / ndf);
    cout << "\e[1m" << degree << ' ' << status << '\t' << chi2 << ' ' << ndf
         << '\t' << x2n << "\u00B1" << error << "\e[0m" << endl;
    if (ndf == 2)
      break;
    if (autoStop && x2n > lastx2n&&degree >2&&x2n<x2nmin) {
      cerr << "Chi2/ndf has increased -- stepping back and stopping!\n";
      f->FixParameter(degree, 0);
      --degree;
      hist->Fit(f, options);
      break;
    }
  }
  cout<<"End Fitting at degree ="<<TString::Format("%d",degree)<<endl;
  return f;
}
