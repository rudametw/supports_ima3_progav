# BASE PDF FILES

# Default rule
all: 1pp 4pp 6pp

base = CM0/CM0-Intro.pdf CM1/CM1-structures.pdf CM2/CM2-listes.pdf CM3/CM3-malloc.pdf CM4/CM4-recursivité.pdf CM5/CM5-fichiers.pdf CM6/CM6-Listes_variantes.pdf CM7/CM7-arbres.pdf CM8-Vincent_Aranega/CM8-pointeur-de-fonction.pdf
base: ${base}

CM%.pdf: CM%.tex common-images
	cd "$(shell dirname "$<")"; pdflatex -shell-escape "$(shell basename "$<")"
#Second run to fix the damn page numbers problem
	cd "$(shell dirname "$<")"; pdflatex -shell-escape "$(shell basename "$<")"

CM8-Vincent_Aranega/CM8-pointeur-de-fonction.pdf:
	wget http://dept-info.labri.fr/ENSEIGNEMENT/programmation1/cours/CM_14___Pointeur_de_fonction.pdf -O "$@"

# COMMON IMAGES

common-images: $(patsubst %.svg,%.pdf,$(wildcard common-images/*))

common-images/%.pdf: common-images/%.svg
	inkscape -A "$@" "$<"

# PDFs FOLDER

# 1 slide / page
1pp = $(addprefix PDFs/,$(filter %.pdf,$(subst /, ,${base})))
1pp: ${1pp}
# 4 slides / page
4pp: $(patsubst %.pdf,%-handouts-4pp.pdf,${1pp})
# 6 slides / page
6pp: $(patsubst %.pdf,%-handouts-6pp.pdf,${1pp})

# Where to search for PDF files in the following rules
vpath %.pdf $(wildcard CM*)

PDFs/CM%-handouts-4pp.pdf: CM%.pdf
	cd PDFs; pdflatex CM-handouts-4pp.tex "$(shell basename "$<")"
	mv PDFs/CM-handouts-4pp.pdf "$@"

PDFs/CM%-handouts-6pp.pdf: CM%.pdf
	cd PDFs; pdflatex CM-handouts-6pp.tex "$(shell basename "$<")"
	mv PDFs/CM-handouts-6pp.pdf "$@"

PDFs/CM%.pdf: CM%.pdf
	cp "$<" "$@"

fixPageNumbers:
	rm -fv CM[0-7]/CM*pdf

clean:
#	rm -f PDFs/*.pdf CM*/*.pdf *.log *.aux *_minted-* *.synctex.gz *.bbl *.blg *.nav *.out *.snm *.toc common-images/*.pdf
	rm -fv CM[0-9]/*.pdf CM[0-9]/*.log CM[0-9]/*.aux CM[0-9]/*.synctex.gz CM[0-9]/*.bbl CM[0-9]/*.blg CM[0-9]/*.nav CM[0-9]/*.out CM[0-9]/*.snm CM[0-9]/*.toc common-images/*.pdf
	rm -fv PDFs/*.pdf PDFs/*.log PDFs/*.aux
	echo Removing minted directories: CM*/*_minted-*
	rm -rf CM*/*_minted-*

# Rules that do not represent a file
.PHONY: base 1pp 4pp 6pp clean

