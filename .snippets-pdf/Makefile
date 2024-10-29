.PHONY: build

build: snippets.tex
	if which pdflatex.exe > /dev/null; then \
		pdflatex.exe snippets.tex -interaction=nonstopmode; \
	else \
		pdflatex snippets.tex -interaction=nonstopmode; \
	fi

watch:
	nodemon -w snippets.tex -x make build

.PHONY: extract
extract: extract-files.py ../cpp.snippets
	python3 extract-files.py -s ../cpp.snippets -o cod/

