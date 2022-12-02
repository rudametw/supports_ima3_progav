#!/usr/bin/env python
import sys
from pyPdf import PdfFileWriter, PdfFileReader
output = PdfFileWriter()
output_page_number = 0
alignment = 2           # to align on even pages
for filename in sys.argv[1:]:
    # This code is executed for every file in turn
    input = PdfFileReader(open(filename))
    for p in [input.getPage(i) for i in range(0,input.getNumPages())]:
        # This code is executed for every input page in turn
        output.addPage(p)
        output_page_number += 1
    while output_page_number % alignment != 0:
        output.addBlankPage()
        output_page_number += 1
output.write(sys.stdout)

