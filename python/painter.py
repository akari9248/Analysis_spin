import enum
import uuid
import numpy as np
from ROOT import TFile, TCanvas, TPad, gPad, TH1D, TF1, gStyle, TLegend, TPaveText, EColor, ETextAlign, EColorPalette, TGraphErrors, TH1D, TH2D, TH3D,TLatex,TMath


# def get_colors(num_colors=20, palette_type=EColorPalette.kBird):
# palette = gStyle.GetColorPalette(palette_type)
def get_colors():
    return [
        # EColor.kBlack,
        # EColor.kRed - 4,
        # EColor.kBlue - 4 ,
        # EColor.kMagenta + 1,
        # EColor.kOrange - 4,
        # EColor.kGreen - 3,
        # EColor.kSpring,
        # EColor.kTeal,
        # EColor.kGreen,
        # EColor.kCyan,
        # EColor.kAzure,
        # EColor.kPink,
        # EColor.kGray,
        # EColor.kViolet,

        EColor.kGray + 3,

        EColor.kRed - 7,
        EColor.kBlue - 7 ,
        EColor.kMagenta - 7,
        EColor.kGreen - 6,
        EColor.kYellow - 6,

        # EColor.kRed + 1,
        # EColor.kBlue + 2 ,
        # EColor.kMagenta + 2,
        # EColor.kCyan + 2 ,
        # EColor.kGreen - 2,
        # EColor.kYellow + 1,

        EColor.kRed - 9,
        EColor.kBlue - 10 ,
        EColor.kMagenta - 10,
        EColor.kCyan - 8 ,
        EColor.kGreen - 8,
        EColor.kYellow - 8,

        EColor.kOrange - 4,
        # EColor.kSpring,
        EColor.kTeal,
        # EColor.kCyan,
        EColor.kAzure,
        # EColor.kPink,
        EColor.kGray,
        EColor.kViolet,
    ]


def get_pt_ranges(idx_begin=1, datatype="SimPT"):
    pt_ranges = [
        "15to30", "30to50", "50to80", "80to120", "120to170", "170to300",
        "300to470", "470to600", "600to800", "800to1000", "1000to1400",
        "1400to1800", "1800to2400", "2400to3200", "3200toInf"
    ]
    if datatype == "SimHT":
        pt_ranges = [
            "50to100", "100to200", "200to300", "300to500", "500to700",
            "700to1000", "1000to1500", "1500to2000", "2000toInf"
        ]
    return pt_ranges[idx_begin:]


def get_pt_bins(idx_begin=0, delimiter="to"):
    pt_bins = [56, 97, 220, 330, 468, 638, 846, 1101, 1410, 1784, 2238]
    pt_bins_str = [
        "{}{}{}".format(pt_bins[i], delimiter, pt_bins[i + 1])
        for i in range(len(pt_bins) - 1)
    ]
    return pt_bins[idx_begin:], pt_bins_str[idx_begin:]


def get_fit_ranges(range_type="short", logged=True):
    short_fit_ranges = [[-0.8, -0.56], [-0.9, -0.56], [-1.1, -0.56],
                        [-1.3, -0.56], [-1.5, -0.56], [-1.5, -0.56],
                        [-1.5, -0.56], [-1.5, -0.56], [-1.5, -0.56],
                        [-1.5, -0.56]]
    long_fit_ranges = [[-1.3, -0.6], [-1.5, -0.6], [-1.5, -0.6], [-1.7, -0.6],
                       [-1.7, -0.6], [-2.0, -0.6], [-2.0, -0.6], [-2.0, -0.6],
                       [-2.0, -0.6], [-2.0, -0.6]]
    if not logged:
        short_fit_ranges = np.power(10, short_fit_ranges)
        long_fit_ranges = np.power(10, long_fit_ranges)
    return long_fit_ranges if range_type == "long" else short_fit_ranges


def get_draw_ranges(logged=True, overflow=0.01):
    # draw_ranges = np.array([[0.179, 0.234], [0.137, 0.234], [0.08, 0.234],
    #                [0.06, 0.234], [0.04, 0.234], [0.04, 0.234], [0.04, 0.234],
    #                [0.04, 0.234], [0.04, 0.234], [0.04, 0.234]], float)
    draw_ranges = np.array([[0.179, 0.234], [0.137, 0.234], [0.08, 0.234],
                   [0.06, 0.234], [0.04, 0.234], [0.04, 0.234], [0.04, 0.234],
                   [0.02, 0.234], [0.02, 0.234], [0.02, 0.234]], float)
    if logged:
        draw_ranges = np.log10(draw_ranges)
    draw_ranges[:, 0] = draw_ranges[:, 0] * (1-overflow)
    draw_ranges[:, 1] = draw_ranges[:, 1] * (1+overflow)
    return draw_ranges

def paint_systematics_lines(hists, diffs, ibegin=3):
    for i in range(len(hists)):
        if i < ibegin: continue 
        # systematics
        color = get_colors()[(i+ibegin)//2]
        hists[i].SetLineColor(color)
        diffs[i].SetLineColor(color)
        if i%2 == 0: #i = 4, 6, 8... SysDn in dashline
            hists[i].SetLineStyle(7)
            diffs[i].SetLineStyle(7)


def get_dr_bins(dr_type="cms", loc_type="edge", log10=False):
    # drbins = np.array([
    #     0.0002, 0.0128, 0.02225, 0.0317, 0.0435125, 0.0568016, 0.0700906,
    #     0.080888, 0.093035, 0.105182, 0.115052, 0.126155, 0.135176, 0.171966,
    #     0.279954, 0.474984, 0.8
    # ])
    drbins = []
    if dr_type == "cms":
        drbins = np.array([
            0, 0.0002, 0.02, 0.04, 0.06, 0.08, 0.1, 0.12, 0.137, 0.157, 0.179,
            0.205, 0.234, 0.268, 0.306, 0.35, 0.4, 0.8
        ])
    elif dr_type == "newcms":
        drbins = np.array([
            0, 0.0002, 0.001, 0.002, 0.005, 0.01, 0.02, 0.04, 0.06, 0.08, 0.1,
            0.12, 0.137, 0.157, 0.179, 0.205, 0.234, 0.268, 0.306, 0.35, 0.4,
            0.8
        ])
    if log10:
        drbins[0] = 0.00002
        drbins = np.log10(drbins)
    if loc_type == "center":
        drbins = np.array([(drbins[i + 1] + drbins[i]) / 2
                           for i in range(len(drbins) - 1)])
    return drbins


def add_hists(hists, base_idx=0, random_token = False):
    result = hists[base_idx].Clone()
    if random_token: result.SetName(result.GetName() + "_" + uuid.uuid4().hex)
    for i in range(0, len(hists)):
        if i == base_idx: continue
        result.Add(hists[i])
    return result


def get_normalized_hist(hist, binwidth=True):
    hist.Scale(1.0 / hist.Integral(0, hist.GetNbinsX() + 1))
    if not binwidth: return hist
    for i in range(hist.GetNbinsX() + 1):
        width = hist.GetBinWidth(i)
        val = hist.GetBinContent(i)
        err = hist.GetBinError(i)
        hist.SetBinContent(i, val / width)
        hist.SetBinError(i, err / width)
    return hist


def get_normalized_hists(hists, divide_bin_width=False, divide_logbin_width=False):
    old_shape = hists.shape if isinstance(hists, np.ndarray) else [len(hists)]
    flatten_shape = hists.flatten().shape if isinstance(hists, np.ndarray) else [len(hists)]
    results = np.empty(flatten_shape, object)
    for i, _ in enumerate(results):
        results[i] = hists.flatten()[i].Clone() if isinstance(hists, np.ndarray) else hists[i].Clone()
    assert divide_bin_width + divide_logbin_width != 2, "only one of divide bin width could be enable"
    for i, hist in enumerate(results):
        hist.Scale(1.0 / hist.Integral(0, hist.GetNbinsX() + 1))
        if divide_bin_width or divide_logbin_width:
            for ibin in range(1, hist.GetNbinsX() + 1):
                content = hist.GetBinContent(ibin)
                error = hist.GetBinError(ibin)
                low = hist.GetBinLowEdge(ibin)
                high = hist.GetBinLowEdge(ibin+1)
                binWidth = high - low if divide_bin_width else 10**high - 10**low
                hist.SetBinContent(ibin, content / binWidth)
                hist.SetBinError(ibin, error / binWidth)
                # print(content, hist.GetBinContent(ibin))
    return results.reshape(old_shape)


def get_standard_ratios(hists,
                        idiff=0,
                        diff_range=0.1,
                        show_unity=True,
                        setx=[],
                        sety=[]):
    diffs = [
        TH1D(hists[i]) for i in range(len(hists))
        if show_unity or (not show_unity and i != idiff)
    ]
    _ = [d.Divide(hists[idiff]) for d in diffs]
    for i, diff in enumerate(diffs):
        xtitle = diff.GetXaxis().GetTitle()
        if len(setx) != 0: diff.GetXaxis().SetRangeUser(setx[0], setx[1])
        # diff.SetTitleSize(0.10)
        diff.GetYaxis().SetRangeUser(1.0 - diff_range, 1.0 + diff_range)
    cooked_diffs = np.empty([len(diffs)], object)
    for i, diff in enumerate(diffs):
        cooked_diffs[i] = diff
    return cooked_diffs


def get_ratio(eeecs, eecs, fit_ranges):
    _, pt_bins_str = get_pt_bins(0)
    assert len(eeecs) == len(eecs) == len(pt_bins_str)
    nbin = len(eeecs)
    ratio = []
    for i in range(nbin):
        ratioi = eeecs[i].Clone()
        ratioi.SetDirectory(0)  # do not delete when the directory is closed
        ratioi.Divide(eecs[i])
        ratioi.SetName("Ratio" + str(i))
        ratioi.SetYTitle("EEEC / EEC Ratio, Jet pT {}".format(pt_bins_str[i]))
        ratioi.SetXTitle("log_{10}#DeltaR")
        ratio.append(ratioi)
    fit_val, fit_err = get_fits(ratio, fit_ranges)
    return ratio, fit_val, fit_err

def get_ratios(e3cs, e2cs, titles=[], ytitle="E3C/E2C", mode="divide"):
    assert e3cs.shape == e2cs.shape
    old_shape = e3cs.shape
    ntotal = e3cs.flatten().shape[0]
    if len(titles) > 0:
        assert len(titles) == ntotal
    ratios = np.empty([ntotal], object)
    for i in range(ntotal):
        ratios[i] = e3cs.flatten()[i].Clone()
        if mode == "divide":
            ratios[i].Divide(e2cs.flatten()[i])
        elif mode == "multiply":
            ratios[i].Multiply(e2cs.flatten()[i])
        ratios[i].GetYaxis().SetTitle(ytitle)
        if len(titles) > 0:
            ratios[i].SetTitle(titles[i])
    return ratios.reshape(old_shape)

def get_ratios_with_hist(hists, hist, titles=[], ytitle=""):
    demonimators = np.empty(hists.flatten.shape, object)
    for i in range(hists.flatten.shape[0]):
        demonimators[i] = hist.Clone()
    demonimators = demonimators.reshape(hists.shape)
    return get_ratios(hists, demonimators, titles, ytitle)


def get_eec_eeec_ratio(filename, pswgt_idx=-1, quite=False):
    if not quite: print("reading file:", filename)
    file = TFile(filename)
    total_names = np.array([k.GetName() for k in file.GetListOfKeys()])
    enc_names = [
        n for n in total_names
        if n.startswith("EEC") or n.startswith("EEEC") or n.startswith("Ratio")
    ]
    nbin = int(len(enc_names) / 3)
    eec, eeec, ratio = [], [], []
    _, pt_bins_str = get_pt_bins()
    segments = filename.split("/")[-1].split("_")
    for i in range(int(nbin)):
        tag = "_".join(segments[:4] + [pt_bins_str[i]])
        eeci = file.Get("EEC" + str(i)) if pswgt_idx == -1 else file.Get(
            "PSWeight{}_EEC{}".format(pswgt_idx, i))
        eeci.SetTitle(tag)
        eeci.SetDirectory(0)  # do not delete when the directory is closed
        eec.append(eeci)
        eeeci = file.Get("EEEC" + str(i)) if pswgt_idx == -1 else file.Get(
            "PSWeight{}_EEEC{}".format(pswgt_idx, i))
        eeeci.SetTitle(tag)
        eeeci.SetDirectory(0)  # do not delete when the directory is closed
        eeec.append(eeeci)
        ratioi = file.Get("Ratio" + str(i)) if pswgt_idx == -1 else file.Get(
            "PSWeight{}_Ratio{}".format(pswgt_idx, i))
        ratioi.SetDirectory(0)  # do not delete when the directory is closed
        ratioi.SetYTitle("EEEC / EEC Ratio")
        ratioi.SetXTitle("log_{10}#DeltaR")
        ratio.append(ratioi)
    file.Close()
    return eec, eeec, ratio


def get_combined_eec_eeec_ratio(filenames,
                                fit_ranges,
                                pswgt_idx=-1,
                                quite=False,
                                mode="combine"):
    # the 1st index is different file
    # the 2nd index is different pt range
    if not quite: print(filenames[0])
    file = TFile(filenames[0])
    total_names = np.array([k.GetName() for k in file.GetListOfKeys()])
    enc_names = [
        n for n in total_names
        if n.startswith("EEC") or n.startswith("EEEC") or n.startswith("Ratio")
    ]
    nbin = int(len(enc_names) / 3)
    eec_raw, eeec_raw = np.empty([len(filenames), nbin],
                                 TH1D), np.empty([len(filenames), nbin], TH1D)
    for i in range(len(filenames)):
        # sub-range eec is a list of different pt ranges
        # we need to add them all
        eec_raw[i], eeec_raw[i], _ = get_eec_eeec_ratio(filenames[i],
                                                        pswgt_idx,
                                                        quite=quite)
    # add to get an combined eec, eeec
    eec, eeec = [], []
    if mode == "combine":
        eec = [add_hists(eec_raw.T[i]) for i in range(nbin)]
        eeec = [add_hists(eeec_raw.T[i]) for i in range(nbin)]
    elif mode == "single":
        filename_index = [1, 3, 4, 5, 6, 7, 8, 9, 10, 11]
        for i in range(nbin):
            eec.append(eec_raw[filename_index[i], i])
            eeec.append(eeec_raw[filename_index[i], i])
    else:
        raise Exception(f"unsupport enc reading mode: {mode}")
    ratio, fit_val, fit_err = get_ratio(eeec, eec, fit_ranges)
    # ratio = []
    # for i in range(nbin):
    #     ratioi = TH1D(eeec[i])
    #     ratioi.SetDirectory(0)  # do not delete when the directory is closed
    #     ratioi.Divide(eec[i])
    #     ratioi.SetYTitle("EEEC / EEC Ratio")
    #     ratioi.SetXTitle("log_{10}#DeltaR")
    #     ratio.append(ratioi)
    # fit_val, fit_err = get_fits(ratio, fit_ranges)
    return eec, eeec, ratio, fit_val, fit_err


def get_single_eec_eeec_ratio(filenames,
                                fit_ranges,
                                pswgt_idx=-1,
                                quite=False):
    # the 1st index is different file
    # the 2nd index is different pt range
    if not quite: print(filenames[0])
    file = TFile(filenames[0])
    total_names = np.array([k.GetName() for k in file.GetListOfKeys()])
    enc_names = [
        n for n in total_names
        if n.startswith("EEC") or n.startswith("EEEC") or n.startswith("Ratio")
    ]
    nbin = int(len(enc_names) / 3)
    eec_raw, eeec_raw = np.empty([len(filenames), nbin],
                                 TH1D), np.empty([len(filenames), nbin], TH1D)
    for i in range(len(filenames)):
        # sub-range eec is a list of different pt ranges
        # we need to add them all
        eec_raw[i], eeec_raw[i], _ = get_eec_eeec_ratio(filenames[i],
                                                        pswgt_idx,
                                                        quite=quite)
    eec, eeec = [], []
    for i in range(nbin):
        if i < 2:
            eec.append(eec_raw[3, i]) # 120to170
            eeec.append(eeec_raw[3, i]) # 120to170
        if 2 <= i < 5:
            eec.append(eec_raw[6, i]) # 470to600
            eeec.append(eeec_raw[6, i]) # 470to600
        if 5 <= i < 7:
            eec.append(eec_raw[8, i]) # 800to1000
            eeec.append(eeec_raw[8, i]) # 800to1000
        if i == 7:
            eec.append(eec_raw[9, i]) # 1000to1400
            eeec.append(eeec_raw[9, i]) # 1000to1400
        if i == 8:
            eec.append(eec_raw[10, i]) # 1400to1800
            eeec.append(eeec_raw[10, i]) # 1400to1800
        if i == 9:
            eec.append(eec_raw[11, i]) # 1400to1800
            eeec.append(eeec_raw[11, i]) # 1400to1800
    ratio, fit_val, fit_err = get_ratio(eeec, eec, fit_ranges)
    return eec, eeec, ratio, fit_val, fit_err


def get_combined_eecs_eeecs_ratios(filenames, tags):
    fit_ranges = get_fit_ranges()
    assert len(filenames) == len(tags)
    eecs = np.empty([filenames.shape[0], len(fit_ranges)], object)
    eeecs = np.empty([filenames.shape[0], len(fit_ranges)], object)
    ratios = np.empty([filenames.shape[0], len(fit_ranges)], object)
    fit_vals = np.zeros([filenames.shape[0], len(fit_ranges)], float)
    fit_errs = np.zeros([filenames.shape[0], len(fit_ranges)], float)
    for i in range(filenames.shape[0]):
        eecs[i], eeecs[i], ratios[i], fit_vals[i], fit_errs[
            i] = get_combined_eec_eeec_ratio(filenames[i], fit_ranges)
    return eecs, eeecs, ratios, fit_vals, fit_errs


def get_combined_eecs_eeecs_ratios_with_pswgts(filenames, tags, pswgt_idxs):
    fit_ranges = get_fit_ranges()
    assert len(filenames) == len(tags)
    eecs = np.empty([len(pswgt_idxs), filenames.shape[0],
                     len(fit_ranges)], object)
    eeecs = np.empty([len(pswgt_idxs), filenames.shape[0],
                      len(fit_ranges)], object)
    ratios = np.empty([len(pswgt_idxs), filenames.shape[0],
                       len(fit_ranges)], object)
    fit_vals = np.zeros([len(pswgt_idxs), filenames.shape[0],
                         len(fit_ranges)], float)
    fit_errs = np.zeros([len(pswgt_idxs), filenames.shape[0],
                         len(fit_ranges)], float)
    for iwgt, wgt in enumerate(pswgt_idxs):
        for iset in range(filenames.shape[0]):
            eecs[iwgt][iset], eeecs[iwgt][iset], ratios[iwgt][iset], fit_vals[
                iwgt][iset], fit_errs[iwgt][
                    iset] = get_combined_eec_eeec_ratio(
                        filenames[iset], fit_ranges, wgt)
    return eecs, eeecs, ratios, fit_vals, fit_errs


def get_xye(hist, begin=1, end=-1, with_flows=False):
    """
    Include both begin and end, i.e. [begin, end]
    """
    if isinstance(hist, TH1D):
        nx = hist.GetNbinsX()
        xs, ys, es = np.zeros([nx+2]), np.zeros([nx+2]), np.zeros([nx+2])
        if end < 0: end = hist.GetNbinsX()
        if with_flows:
            # index is according to ROOT
            begin = 0
            end = hist.GetNbinsX() + 1
        for i in range(begin, end+1): # shift 1 in python
            x = hist.GetBinCenter(i)
            e = hist.GetBinError(i)
            y = hist.GetBinContent(i)
            xs[i] = x
            ys[i] = y
            es[i] = e
        return xs, ys, es
    elif isinstance(hist, TH2D):
        # todo: fix end arg is not functional
        nx = hist.GetNbinsX()
        ny = hist.GetNbinsY()
        if with_flows:
            begin = 0
            nx = nx + 2
            ny = ny + 2
        xs, ys, es = np.zeros([nx, ny, 2]), np.zeros([nx, ny]), np.zeros([nx, ny])
        for i in range(begin, nx + begin):
            for j in range(begin, ny + begin):
                ii = i if with_flows else i-1
                jj = j if with_flows else j-1
                xs[ii, jj, 0] = hist.GetXaxis().GetBinCenter(i)
                xs[ii, jj, 1] = hist.GetYaxis().GetBinCenter(j)
                ys[ii, jj] = hist.GetBinContent(i, j)
                es[ii, jj] = hist.GetBinError(i, j)
        return xs, ys, es
    else:
        # todo: fix end arg is not functional
        nx = hist.GetNbinsX()
        ny = hist.GetNbinsY()
        nz = hist.GetNbinsZ()
        if with_flows:
            begin = 0
            nx = nx + 2
            ny = ny + 2
            nz = nz + 2
        xs, ys, es = np.zeros([nx, ny, nz, 3]), np.zeros([nx, ny, nz]), np.zeros([nx, ny, nz])
        for i in range(begin, nx+begin):
            for j in range(begin, ny+begin):
                for k in range(begin, nz+begin):
                    ii = i if with_flows else i-1
                    jj = j if with_flows else j-1
                    kk = k if with_flows else k-1
                    xs[ii, jj, kk, 0] = hist.GetXaxis().GetBinCenter(i)
                    xs[ii, jj, kk, 1] = hist.GetYaxis().GetBinCenter(j)
                    xs[ii, jj, kk, 2] = hist.GetZaxis().GetBinCenter(k)
                    ys[ii, jj, kk] = hist.GetBinContent(i, j, k)
                    es[ii, jj, kk] = hist.GetBinError(i, j, k)
        return xs, ys, es

def get_edges(hist, with_under_overflow=False):
    nbin = hist.GetNbinsX() + 2 if with_under_overflow else hist.GetNbinsX()
    nbin += 1 # bin edge have additional value
    array = np.zeros([nbin], float)
    for i in range(nbin):
        ii = i if with_under_overflow else i + 1
        array[i] = hist.GetBinLowEdge(ii)
    return array

def get_hist_array(hist, with_under_overflow=False):
    nbin = hist.GetNbinsX() + 2 if with_under_overflow else hist.GetNbinsX()
    if type(hist) == TH1D:
        array = np.zeros((nbin, 3))
        for i in range(nbin):
            ii = i if with_under_overflow else i + 1
            array[i, 0] = hist.GetXaxis().GetBinCenter(ii)
            array[i, 1] = hist.GetBinContent(ii)
            array[i, 2] = hist.GetBinError(ii)
        return array
    elif type(hist) == TH3D:
        array = np.zeros((nbin, nbin, nbin, 5))
        for i in range(nbin):
            ii = i if with_under_overflow else i + 1
            for j in range(nbin):
                jj = j if with_under_overflow else j + 1
                for k in range(nbin):
                    kk = k if with_under_overflow else k + 1
                    ibin = hist.GetBin(ii, jj, kk)
                    array[i, j, k, 0] = hist.GetXaxis().GetBinCenter(ii)
                    array[i, j, k, 1] = hist.GetYaxis().GetBinCenter(jj)
                    array[i, j, k, 2] = hist.GetZaxis().GetBinCenter(kk)
                    array[i, j, k, 3] = hist.GetBinContent(ibin)
                    array[i, j, k, 4] = hist.GetBinError(ibin)
        return array
    else:
        print('type not supported')

def get_hist_from_file(filename, histname):
    tfile = TFile(filename)
    hist = tfile.Get(histname)
    hist.SetDirectory(0)
    return hist

def get_hists_from_file(filename, histnames):
    results = np.empty(len(histnames), object)
    for i in range(len(results)):
        results[i] = get_hist_from_file(filename, histnames[i])
    return results

def create_ratio(eec, eeec, ytitle="") -> TH1D:
    result = TH1D(eeec)
    result.Divide(eec)
    result.GetYaxis().SetRangeUser(0.0, 3.5)
    if ytitle == "": ytitle = "EEEC / EEC Ratio"
    result.SetYTitle(ytitle)
    result.SetXTitle("#DeltaR")
    return result


def create_fit(ratio, fit_range, logged=False, show_fit=True) -> TF1:
    new_range = [0.0, 0.0]
    new_range[0] = ratio.GetBinLowEdge(ratio.FindBin(fit_range[0]) + 1)
    new_range[1] = ratio.GetBinLowEdge(ratio.FindBin(fit_range[1]))
    canvas = TCanvas()
    func = "[0]+[1]*log10(x)" if logged else "[0]+[1]*x"
    fit = TF1("fit", func, new_range[0], new_range[1])
    ratio.Fit(fit, "RQ") if show_fit else ratio.Fit(fit, "RQN")
    # print(fit.GetParameter(1), fit.GetParError(1))
    del canvas
    return fit


def get_fit(ratio, fit_range, logged=False, show_fit=False):
    fit = create_fit(ratio, fit_range, logged, show_fit)
    return fit.GetParameter(1), fit.GetParError(1)


def get_fits(ratios, fit_ranges, loggged=False, show_fit=False):
    fits = [
        create_fit(v, fit_ranges[j], show_fit=show_fit)
        for j, v in enumerate(ratios)
    ]
    fit_vals = [f.GetParameter(1) for f in fits]
    fit_errs = [f.GetParError(1) for f in fits]
    return fit_vals, fit_errs


def create_log10_fit(ratio, fit_range) -> TF1:
    canvas = TCanvas()
    fit = TF1("fit", "[0]+[1]*log10(x)", fit_range[0], fit_range[1])
    ratio.Fit(fit, "RQ")
    print(fit.GetParameter(1), fit.GetParError(1))
    del canvas
    return fit


# def create_slope_graph(graph, xis, vals, errs) -> None:
#     name = "PythiaAlphaS"
#     title = "Jet #alpha_{S} slope, pp with #sqrt{s} = 13TeV"
#     graph.SetNameTitle(name, title)
#     graph.GetXaxis().SetTitle("pT")
#     graph.GetYaxis().SetTitle("Fit Slope of EEEC/EEC")
#     graph.SetMarkerStyle(20)
#     graph.SetMarkerSize(0.6)
#     for i in range(len(vals)):
#         graph.SetPoint(i, 1.0 * xis[i], vals[i])
#         graph.SetPointError(i, 0.0, errs[i])
#     graph.GetYaxis().SetRangeUser(0.0, 1.2)


def create_slope(hist, xis, vals, errs) -> None:
    name = "PythiaAlphaS"
    title = "Jet #alpha_{S} slope, pp with #sqrt{s} = 13TeV"
    gStyle.SetOptStat(0)
    # gStyle.SetErrorX(0.0)  # we do not need x error bar
    hist.SetNameTitle(name, title)
    hist.GetXaxis().SetTitle("pT")
    hist.GetYaxis().SetTitle("Fit Slope of EEEC/EEC")
    hist.GetYaxis().SetRangeUser(0.0, 1.2)
    hist.GetXaxis().SetRangeUser(xis[0], xis[-1])
    hist.SetMarkerStyle(20)
    hist.SetMarkerSize(0.6)
    hist.SetBins(len(vals), np.array(xis, float))  # array is needed
    # hist index: 0 is underflow, index: -1 is overflow
    for i in range(1, len(vals) + 1):
        hist.SetBinContent(i, vals[i - 1])
        hist.SetBinError(i, errs[i - 1])


def create_slope_and_return(xis, vals, errs) -> TH1D:
    hist = TH1D()
    create_slope(hist, xis, vals, errs)
    return hist


def create_standard_canvas(name=""):
    cvs = TCanvas(name) if name else TCanvas()
    cvs.SetCanvasSize(800, 600)
    gStyle.SetOptStat(0)
    gStyle.SetOptTitle(0)
    gStyle.SetPalette(EColorPalette.kCMYK)
    # set canvas margin
    cvs.SetLeftMargin(0.12)
    cvs.SetBottomMargin(0.12)
    cvs.SetRightMargin(0.04)
    cvs.SetTopMargin(0.04)
    # set ticks at top and right
    cvs.SetTickx(1)
    cvs.SetTicky(1)
    return cvs


def create_cms_canvas(name=""):
    cvs = TCanvas(name) if name else TCanvas()
    cvs.SetCanvasSize(600, 600)
    gStyle.SetOptStat(0)
    gStyle.SetOptTitle(0)
    gStyle.SetPalette(EColorPalette.kCMYK)
    # set canvas margin
    cvs.SetLeftMargin(0.12)
    cvs.SetBottomMargin(0.12)
    cvs.SetRightMargin(0.04)
    cvs.SetTopMargin(0.08)
    # set ticks at top and right
    cvs.SetTickx(1)
    cvs.SetTicky(1)
    return cvs


def create_standard_legend(xlow=0.16,
                           xup=0.56,
                           ylow=0.72,
                           yup=0.88,
                           tsize=0.03):
    lgd = TLegend(xlow, ylow, xup, yup)
    lgd.SetTextSize(tsize)
    # lgd.SetBorderSize(0)
    return lgd


def create_standard_text(xlow=0.16, xup=0.56, ylow=0.72, yup=0.88, tsize=0.03):
    text = TPaveText(xlow, ylow, xup, yup, "NB NDC")
    text.SetBorderSize(0)
    text.SetTextSize(tsize)
    text.SetFillColor(EColor.kWhite)
    text.SetTextAlign(ETextAlign.kHAlignLeft + ETextAlign.kVAlignTop)
    return text


def create_cms_text(contents=""):
    text = TPaveText(.14, .8, .45, .9, "NB NDC")
    text.SetTextSize(0.04)
    text.SetFillColor(EColor.kWhite)
    text.SetTextAlign(ETextAlign.kHAlignLeft + ETextAlign.kVAlignTop)
    if contents:
        if type(contents) == list:
            _ = [text.AddText(content) for content in contents]
        else:
            text.AddText(contents)
    return text


def build_standard_legend(xlow=0.16, xup=0.56, ylow=0.72, yup=0.88):
    lgd = gPad.BuildLegend(xlow, ylow, xup, yup)
    lgd.SetTextSize(0.03)
    lgd.SetBorderSize(0)
    return lgd


def set_standard_hist(hist):
    pass


def create_standard_canvas_with_hists(hists,
                                      tags,
                                      setx=[],
                                      sety=[],
                                      logx=False,
                                      logy=False,
                                      xtitle="",
                                      ytitle="",
                                      show_legend=True,
                                      draw=False,
                                      normalize=False,
                                      cms_cvs=True,
                                      colors=[]):
    if not colors: colors = get_colors()
    assert len(hists) == len(
        tags), "slopes size should be equal to legend tag size"
    if type(hists) == np.ndarray: hists = hists.reshape(-1)
    cvs = create_cms_canvas() if cms_cvs else create_standard_canvas()
    lgd = TLegend(.24, .64, .72, .88)
    lgd.SetTextSize(0.04)
    lgd.SetBorderSize(0)
    for i, hist in enumerate(hists):
        if normalize:
            hist.Scale(1 / hist.Integral(0, hist.GetNbinsX() + 1))
        if len(sety) == 0: # fix some peak overflow the legend
            ys = list(hists[0])
            sety = [min(ys), max(ys)*1.2]
        if len(setx) != 0: hist.GetXaxis().SetRangeUser(setx[0], setx[1])
        if len(sety) != 0: hist.GetYaxis().SetRangeUser(sety[0], sety[1])
        if xtitle: hist.GetXaxis().SetTitle(xtitle)
        if ytitle: hist.GetYaxis().SetTitle(ytitle)
        hist.GetXaxis().SetLabelSize(0.04)
        hist.GetXaxis().SetTitleSize(0.04)
        hist.GetYaxis().SetLabelSize(0.04)
        hist.GetYaxis().SetTitleSize(0.04)
        hist.GetXaxis().SetTitleOffset(1.2)
        hist.GetYaxis().SetTitleOffset(1.4)
        hist.SetMarkerColor(colors[i])
        hist.SetLineColor(colors[i])
        hist.SetLineWidth(4)
        lgd.AddEntry(hist, tags[i])
    if logx: cvs.SetLogx()
    if logy: cvs.SetLogy()
    [hist.Draw("SAME") if not normalize else hist.Draw("SAME") for hist in hists]
    if show_legend: lgd.Draw("SAME")
    if draw: cvs.Draw()
    # we must return legend, otherwise canvas draw cannot find it when drawing
    return cvs, lgd


def create_standard_canvas_with_diff(hists,
                                     idiff,
                                     tags,
                                     diff_range=0.3,
                                     setx=[],
                                     sety=[],
                                     logx=False,
                                     logy=False,
                                     xtitle="",
                                     ytitle="",
                                     show_unity=True,
                                     show_legend=True,
                                     show_error=True,
                                     draw=False,
                                     normalize=False,
                                     smooth=False,
                                     cms_cvs=True,
                                     colors=[],
                                     legend_position=[.24, .64, .72, .88]):
    if not colors: colors = get_colors()
    assert len(hists) == len(
        tags), "slopes size should be equal to legend tag size"
    if type(hists) == np.ndarray: hists = hists.reshape(-1)
    cvs = create_cms_canvas() if cms_cvs else create_standard_canvas()
    lgd = TLegend(legend_position[0], legend_position[1], legend_position[2], legend_position[3])
    lgd.SetTextSize(0.04 / 0.6)
    lgd.SetBorderSize(0)
    # setup upper and lower pad
    upper = TPad("upper", "", 0, 0.4, 1, 1)
    lower = TPad("lower", "", 0, 0.0, 1, 0.4)

    if cms_cvs:
        upper.SetMargin(0.12, 0.04, 0.04, 0.14)  # left, right, bottom, top
        lower.SetMargin(0.12, 0.04, 0.28, 0.04)
    else:
        upper.SetLeftMargin(0.12)
        lower.SetLeftMargin(0.12)
        upper.SetBottomMargin(0.04)
        lower.SetTopMargin(0.04)
        lower.SetBottomMargin(0.24)

    if logx: upper.SetLogx()
    if logy: upper.SetLogy()
    if logx: lower.SetLogx()
    upper.Draw()
    lower.Draw()
    # setup upper slopes
    for i, hist in enumerate(hists):
        if normalize:
            hist.Scale(1 / hist.Integral(0, hist.GetNbinsX() + 1))
        if len(sety) == 0: # fix some peak overflow the legend
            ys = np.array(list(hists[idiff]))
            if len(setx) != 0:
                idx_begin = hists[idiff].FindBin(setx[0])
                idx_end = hists[idiff].FindBin(setx[1])
                ys = ys[idx_begin - 1 : idx_end - 1]
            if len(ys) != 0: sety = [min(ys), max(ys)*1.2]
        if len(setx) != 0:
            if smooth:
                xl = hist.GetXaxis().GetBinCenter(hist.GetXaxis().FindBin(setx[0]) - 1)
                xh = hist.GetXaxis().GetBinCenter(hist.GetXaxis().FindBin(setx[1]) + 1)
                # print(xl, xh)
                hist.GetXaxis().SetRangeUser(xl, xh)
                hist.Smooth(2, "R")
            hist.GetXaxis().SetRangeUser(setx[0], setx[1])
        if len(sety) != 0: hist.GetYaxis().SetRangeUser(sety[0], sety[1])
        if xtitle: hist.GetXaxis().SetTitle(xtitle)
        if ytitle: hist.GetYaxis().SetTitle(ytitle)
        hist.GetXaxis().SetLabelSize(0)
        hist.GetXaxis().SetTitleSize(0)
        hist.GetYaxis().SetLabelSize(0.04 / 0.6 * 0.78)
        hist.GetYaxis().SetTitleSize(0.04 / 0.6)
        hist.GetYaxis().SetTitleOffset(0.8)
        hist.SetMarkerColor(colors[i])
        hist.SetLineColor(colors[i])
        hist.SetLineWidth(4)
        # hist.Sumw2()
        lgd.AddEntry(hist, tags[i])
    # create diff hists
    diffs = [
        TH1D(hists[i]) for i in range(len(hists))
        if show_unity or (not show_unity and i != idiff)
    ]
    _ = [d.Divide(hists[idiff]) for d in diffs]
    for i, diff in enumerate(diffs):
        xtitle = diff.GetXaxis().GetTitle()
        if len(setx) != 0: diff.GetXaxis().SetRangeUser(setx[0], setx[1])
        if not show_error: diff.SetMarkerStyle(8)
        if not show_error: diff.SetMarkerSize(0.6)
        diff.SetTitleSize(0.10)
        diff.GetXaxis().SetLabelSize(0.04 / 0.4)
        diff.GetXaxis().SetTitleOffset(1.2)
        if type(diff_range) == list:
            diff.GetYaxis().SetRangeUser(diff_range[0], diff_range[1])
        else:
            diff.GetYaxis().SetRangeUser(1.0 - diff_range, 1.0 + diff_range)
        diff.GetYaxis().SetLabelSize(0.04 / 0.4 * 0.8)
        diff.GetYaxis().SetTitle("")

    # draw hists into upper and diffs into lower
    upper.cd()
    # [hist.Draw("SAME") if show_error else hist.Draw("p HIST SAME") for hist in hists]
    [hist.Draw("E SAME") if show_error else hist.Draw("HIST SAME") for hist in hists]
    if show_legend: lgd.Draw("SAME")
        
    lower.cd()
    [
        diff.Draw("E SAME") if show_error else diff.Draw("HIST SAME")
        for diff in diffs
    ]
    upper.cd()  # cd to upper by default
    if draw: cvs.Draw()
    lgd.SetFillColorAlpha(EColor.kWhite, 0)
    # we must return legend, otherwise canvas draw cannot find it when drawing
    return cvs, lgd, diffs


def create_ratio_canvas(ratios, fits, tags, show_fits=True):
    colors = get_colors()
    assert len(ratios) == len(
        tags), "ratios size should be equal to legend tag size"
    # cvs = TCanvas()
    cvs = create_standard_canvas()
    gStyle.SetOptStat(0)
    # todo: fit legend not drawing
    lgd = TLegend(.16, .72, .64, .88)
    lgd.SetTextSize(0.02)
    lgd.SetBorderSize(0)
    for i, ratio in enumerate(ratios):
        ratio.SetTitle("Jet EEEC/EEC ratios")
        ratio.GetYaxis().SetRangeUser(0.5, 2)
        ratio.SetMarkerColor(colors[i])
        ratio.SetLineColor(colors[i])
        lgd.AddEntry(ratio, tags[i])
        fits[i].SetLineColor(colors[i])
        ratio.Draw("HIST SAME")
        if show_fits: fits[i].Draw("SAME")
    lgd.Draw("SAME")
    # we must return legend, otherwise canvas draw cannot find it when drawing
    return cvs, lgd


# def create_slope_canvas_graph(slopes, tags):
#     colors = get_colors()
#     assert len(slopes) == len(
#         tags), "slopes size should be equal to legend tag size"
#     cvs = TCanvas()
#     gStyle.SetOptStat(0)
#     # todo: fit legend not drawing
#     lgd = TLegend(.15, .65, .85, .85)
#     lgd.SetTextSize(0.02)
#     lgd.SetBorderSize(0)
#     for i, slope in enumerate(slopes):
#         slope.GetYaxis().SetRangeUser(0.0, 1.2)
#         slope.SetMarkerColor(colors[i])
#         slope.SetLineColor(colors[i])
#         lgd.AddEntry(slope, tags[i])
#     slopes[0].Draw("AP")  # draw axis first
#     # draw all slope hist
#     [slope.Draw("P SAME") for slope in slopes]
#     lgd.Draw("SAME")
#     # we must return legend, otherwise canvas draw cannot find it when drawing
#     return cvs, lgd


def create_slope_canvas(slopes, tags):
    colors = get_colors()
    assert len(slopes) == len(
        tags), "slopes size should be equal to legend tag size"
    cvs = create_standard_canvas()
    gStyle.SetOptStat(0)
    # gStyle.SetErrorX(0.0)  # we do not need x error bar
    # todo: fit legend not drawing
    lgd = TLegend(.16, .72, .88, .88)
    lgd.SetTextSize(0.02)
    lgd.SetBorderSize(0)
    for i, slope in enumerate(slopes):
        slope.SetTitle(tags[i])
        slope.GetYaxis().SetRangeUser(0.0, 1.2)
        slope.SetMarkerStyle(20)
        slope.SetMarkerSize(0.6)
        slope.SetMarkerColor(colors[i])
        slope.SetLineColor(colors[i])
        slope.SetLineWidth(4)
        lgd.AddEntry(slope, tags[i])
    # slopes[0].Draw("AP")  # draw axis first
    # draw all slope hist
    [slope.Draw("SAME") for slope in slopes]
    lgd.Draw("SAME")
    # we must return legend, otherwise canvas draw cannot find it when drawing
    return cvs, lgd


def create_slope_canvas_with_diff(slopes,
                                  diffs,
                                  tags,
                                  diff_range=0.3,
                                  show_legend=True,
                                  draw=False):
    colors = get_colors()
    assert len(slopes) == len(
        tags), "slopes size should be equal to legend tag size"
    # cvs = TCanvas()
    cvs = create_standard_canvas()
    # gStyle.SetOptStat(0)
    # gStyle.SetErrorX(0.0)  # we do not need x error bar
    # setup legend
    lgd = TLegend(.24, .64, .72, .88)
    lgd.SetTextSize(0.05)
    lgd.SetBorderSize(0)
    # setup upper and lower pad
    upper = TPad("upper", "", 0, 0.4, 1, 1)
    lower = TPad("lower", "", 0, 0.0, 1, 0.4)
    upper.SetBottomMargin(0.0)
    lower.SetTopMargin(0.0)
    lower.SetBottomMargin(0.24)
    upper.Draw()
    lower.Draw()
    # setup upper slopes
    for i, hist in enumerate(slopes):
        hist.GetYaxis().SetRangeUser(0.0, 1.2)
        hist.GetYaxis().SetTitleSize(0.056)
        hist.SetMarkerStyle(20)
        hist.SetMarkerSize(0.6)
        hist.SetMarkerColor(colors[i])
        hist.SetLineColor(colors[i])
        lgd.AddEntry(hist, tags[i])
    # setup lower slopes
    for i, diff in enumerate(diffs):
        diff.SetTitle("")
        diff.GetXaxis().SetLabelSize(0.07)
        diff.GetYaxis().SetRangeUser(1.0 - diff_range, 1.0 + diff_range)
        diff.GetYaxis().SetLabelSize(0.056)
        # diffs should keep same color as original hist
        # we will increase color index here
        # diff.SetMarkerColor(colors[i+1])
        # diff.SetLineColor(colors[i+1])
        diff.GetYaxis().SetTitle("")
        diff.SetMarkerSize(0.8)

    # draw hists into upper and diffs into lower
    upper.cd()
    [slope.Draw("SAME") for slope in slopes]
    if show_legend: lgd.Draw("SAME")
    lower.cd()
    [slope.Draw("SAME") for slope in diffs]
    upper.cd()  # cd to upper by default
    if draw: cvs.Draw()
    # we must return legend, otherwise canvas draw cannot find it when drawing
    return cvs, lgd


def create_graph(xs, ys, es=[], random_token=True):
    graph = TGraphErrors()
    if random_token: graph.SetName(uuid.uuid4().hex)
    graph.SetMarkerStyle(20)
    graph.SetMarkerSize(1.2)
    for i, v in enumerate(ys):
        graph.SetPoint(i, float(xs[i]), v)
        if len(es) > 0:
            graph.SetPointError(i, 0.0, es[i])
    return graph


def create_hist(name, title, xs, ys, es=[]):
    if not isinstance(xs[0], float):
        xs = np.array(xs, float)
    if len(es) == 0: es = np.full(len(ys), 1e-9, float)
    hist = TH1D(name, title, len(xs) - 1, xs)
    for i in range(hist.GetNbinsX()):
        hist.SetBinContent(i + 1, ys[i])
        hist.SetBinError(i + 1, es[i])
    return hist


def DrawTree(chain,drawstr,selectstr,filename,nbins=500,binbegin=0,binend=TMath.Pi(),spinon="(spin==1)",spinoff="(spin==0)",rebin_num=50,average_symmetric=True,):
    print(f'{drawstr}>>h_phi_spinon',f"{spinon}{selectstr}")
    print(f'{drawstr}>>h_phi_spinoff',f"{spinoff}{selectstr}")
    h_phi_spinon = TH1D('h_phi_spinon', 'Phi Distribution', nbins, binbegin, binend)
    h_phi_spinoff = TH1D('h_phi_spinoff', 'Phi Distribution', nbins, binbegin, binend)
    chain.Draw(f'{drawstr}>>h_phi_spinon',f"{spinon}{selectstr}")
    chain.Draw(f'{drawstr}>>h_phi_spinoff',f"{spinoff}{selectstr}")
    plot_normalized_histograms(h_spinon=h_phi_spinon,h_spinoff=h_phi_spinoff,filename="plots/"+filename+".pdf",rebin_num=rebin_num,comment=selectstr,average_symmetric=average_symmetric)
    f = TFile("plots/"+filename+f".root","recreate")
    h_phi_spinon.Write()
    h_phi_spinoff.Write()
    f.Close()
def max_diff(hists):
    hist1_clone=hists[0].Clone()
    hist2_clone=hists[1].Clone()
    hist2_clone.Divide(hist1_clone)
    max_difference = 0
    max_bin_index = -1

    # 获得 bin 的数量
    n_bins = hist2_clone.GetNbinsX()

    # 遍历所有的 bin
    for i in range(1, n_bins + 1):
        bin_content = hist2_clone.GetBinContent(i)

        # 只有当 bin 的内容不为 0 时，我们才考虑这个 bin
        if bin_content != 0:
            difference = abs(bin_content - 1)

            # 检查这个差异是否是目前遇到的最大的
            if difference > max_difference:
                max_difference = difference
                max_bin_index = i
    return max_difference

def plot_normalized_histograms(h_spinon, h_spinoff, filename, rebin_num =10,suffix="",comment="",average_symmetric = True):
    # Clone the histograms to avoid modifying the originals
    h_spinonn_clone = h_spinon.Clone()
    h_spinoff_clone = h_spinoff.Clone()
    
    # Rebin the histograms
    h_spinonn_clone.Rebin(rebin_num)
    h_spinoff_clone.Rebin(rebin_num)
    if(average_symmetric):
        average_symmetric_bins(h_spinonn_clone)
        average_symmetric_bins(h_spinoff_clone)
    # Check if the integral is zero to avoid division by zero
    if h_spinonn_clone.Integral() == 0 or h_spinoff_clone.Integral() == 0:
        return
    
    # Normalize the histograms
    h_spinonn_clone.Scale(1.0 / h_spinonn_clone.Integral())
    h_spinoff_clone.Scale(1.0 / h_spinoff_clone.Integral())
    
    # Prepare the histograms and tags for plotting
    hists = [h_spinonn_clone, h_spinoff_clone]
    tags = ["spin on", "spin off"]
    
    # Create canvas and legend, and get the histograms' differences using the provided `painter` object
    cvs, lgd, diffs = create_standard_canvas_with_diff(hists=hists, idiff=1, tags=tags,diff_range=max_diff(hists)*1.2,legend_position=[.24, .24, .62, .48])
    
    # Draw some additional text on the canvas using TLatex
    latex = TLatex()
    latex.SetTextSize(0.06) # Set text size
    latex.SetTextAlign(13)  # Set text alignment: left and top aligned
    latex.SetNDC(True)      # Use normalized coordinates
    latex.DrawLatex(0.48, 0.40, comment)  # Draw the text
    cvs.Update()
    cvs.Draw()
    cvs.SaveAs(f"{filename}"+suffix+".pdf")
def average_symmetric_bins(histogram):
    n_bins = histogram.GetNbinsX()
    for i in range(1, n_bins // 2 + 1):
        first_bin_content = histogram.GetBinContent(i)
        symmetric_bin_content = histogram.GetBinContent(n_bins - i + 1)
        average_content = (first_bin_content + symmetric_bin_content) / 2.0
        histogram.SetBinContent(i, average_content)
        histogram.SetBinContent(n_bins - i + 1, average_content)