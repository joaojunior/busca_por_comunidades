all : clean
	latex Tp.tex
	bibtex Tp.aux
	latex Tp.tex
	latex Tp.tex
	rm -f *.log *.aux *.aut *.inx *.blg
	
pdf : clean
	pdflatex Tp.tex
	bibtex Tp.aux
	pdflatex Tp.tex
	pdflatex Tp.tex
	rm -f *.dvi *.log *.aux *.aut *.inx *.blg

clean :
	rm -f *.dvi *.log *.aux *.aut *.inx *.blg Tp.pdf
