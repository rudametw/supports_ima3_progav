#!/bin/bash
sed  's/\t/    /g' binary_heap.c | a2pdf --noperl-syntax --title "Binary Heap / Tas Binaire" --output binary_heap.pdf --margins 20 --font-size 15 --page-width 592 --page-height 842 ;  pdfjam --nup 2x1 binary_heap.pdf --outfile binary_heap.2pp.pdf --landscape --a4paper
