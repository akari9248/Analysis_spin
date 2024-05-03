import fitz
import os
import fitz
import os
import fitz
import os

def combine_pdfs_grid(output_pdf, input_pdf_grid):
    max_width = max_height = 0
    pdf_pages = []
    for row in input_pdf_grid:
        row_pages = []
        for pdf_path in row:
            if not os.path.isfile(pdf_path):
                print(f"File not found: {pdf_path}, skipping.")
                row_pages.append(None)
                continue
            pdf = fitz.open(pdf_path)
            page = pdf[0]
            max_width = max(max_width, page.rect.width)
            max_height = max(max_height, page.rect.height)
            row_pages.append((pdf, page))
        pdf_pages.append(row_pages)

    cols = max(len(row) for row in input_pdf_grid)
    rows = len(input_pdf_grid)
    page_width = cols * max_width
    page_height = rows * max_height

    new_pdf = fitz.open()
    new_page = new_pdf.new_page(-1, width=page_width, height=page_height)

    for row_index, row in enumerate(pdf_pages):
        for col_index, page_info in enumerate(row):
            if page_info is None:
                continue
            pdf, page = page_info
            x_offset = col_index * max_width
            y_offset = row_index * max_height
            page_rect = fitz.Rect(x_offset, y_offset, x_offset + max_width, y_offset + max_height)

            # Calculate scale factors to fit the page in max_width and max_height
            scale_x = max_width / page.rect.width
            scale_y = max_height / page.rect.height
            scale = min(scale_x, scale_y)  # Ensure aspect ratio is maintained

            mat = fitz.Matrix(scale, scale)  # Updated transformation matrix

            new_page.show_pdf_page(page_rect, pdf, page.number, mat)

    new_pdf.save(output_pdf)
    new_pdf.close()

    for row in pdf_pages:
        for page_info in row:
            if page_info is not None:
                pdf, _ = page_info
                pdf.close()