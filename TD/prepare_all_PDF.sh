#!/bin/bash

#Prepare all similar TDs
pdftk TD1.pdf TD2.pdf TD3.pdf TD4-5.pdf TD6_alternative_FIFO-LIFO.pdf TD6.pdf cat output First_6_TDs_2021.pdf

#Whitespace trim
#pdfjam --nup 2x1 First_6_TDs_2021.pdf --outfile First_6_TDs_2021.pdf_2pp.pdf --landscape  --tidy --frame true --trim '35mm 30mm 35mm 40mm'  --twoside
pdfjam --nup 2x1 First_6_TDs_2021.pdf --outfile First_6_TDs_2021.pdf_2pp.pdf --landscape  --tidy --trim '30mm 30mm 25mm 30mm'  --twoside

#Get TD7 whitespace
#pdfjam --nup 2x1 TD7-Synthese-SD.pdf --outfile TD7-Synthese-SD_2pp.pdf --landscape  --tidy --frame true --trim '9mm 10mm 9mm 10mm'  --twoside
pdfjam --nup 2x1 TD7-Synthese-SD.pdf --outfile TD7-Synthese-SD_2pp.pdf --landscape  --tidy --trim '9mm 10mm 9mm 10mm'  --twoside

pdftk First_6_TDs_2021.pdf_2pp.pdf TD7-Synthese-SD_2pp.pdf cat output ALL_TDs_2021.pdf

