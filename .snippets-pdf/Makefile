.PHONY: build
build: snippets.tex
	if which xelatex.exe > /dev/null; then \
		xelatex.exe snippets.tex; \
	else \
		xelatex snippets.tex; \
	fi

.PHONY: extract
extract: extract-files.py ../cpp.snippets
	python extract-files.py -s ../cpp.snippets -o cod/

