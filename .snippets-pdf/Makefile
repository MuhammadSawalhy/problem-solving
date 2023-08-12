.PHONY: build
build: snippets.tex
	if which pdflatex.exe > /dev/null; then \
		pdflatex.exe snippets.tex -interaction=nonstopmode; \
	else \
		pdflatex snippets.tex -interaction=nonstopmode; \
	fi

.PHONY: extract
extract: extract-files.py ../cpp.snippets
	python extract-files.py -s ../cpp.snippets -o cod/

