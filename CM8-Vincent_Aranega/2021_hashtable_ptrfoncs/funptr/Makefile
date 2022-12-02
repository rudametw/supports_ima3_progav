TEMPLATES := ~/repo-git/asciidoctor-reveal.js/templates/slim

all:
		latexmk -bibtex -pdfdvi -use-make funptr

complement:
	asciidoctor -T ${TEMPLATES} complement.adoc

main:
	asciidoctor -T ${TEMPLATES} main.adoc

clean:
		latexmk -bibtex -C
		rm -f complement.html
