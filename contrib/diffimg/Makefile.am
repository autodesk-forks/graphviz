## Process this file with automake to produce Makefile.in

VERSION=0.2

AM_CPPFLAGS = @GDLIB_CFLAGS@

pdfdir = $(pkgdatadir)/doc/pdf

man_MANS = diffimg.1
if ENABLE_MAN_PDFS
pdf_DATA = diffimg.1.pdf

if HAVE_PS2PDF
pdf = $(pdf_DATA)
else
pdf = ERROR_NO_PS2PDF
endif
else
pdf =
endif

if WITH_LIBGD
bin_PROGRAMS = diffimg
endif

diffimg_SOURCES = diffimg.c

diffimg_LDADD = @GDLIB_LIBS@ @MATH_LIBS@

if ENABLE_MAN_PDFS
if HAVE_PS2PDF
diffimg.1.pdf: diffimg.1.ps
	@PS2PDF@ $<

diffimg.1.ps: $(srcdir)/diffimg.1
	@GROFF@ -Tps -man $< >$@
endif
endif

GRAPH = "digraph G { hello -> world }"

test: diffimg
	echo $(GRAPH) | dot -Tpng >hello1.png
	echo $(GRAPH) | dot -Tpng >hello2.png
	if `./diffimg hello1.png hello2.png >test1.png`;then echo same;else echo different;fi
	echo $(GRAPH) | dot -Grankdir=LR -Tpng >hello2.png
	if `./diffimg hello1.png hello2.png >test2.png`;then echo same;else echo different;fi

CLEANFILES = *.png
EXTRA_DIST = diffimg.vcxproj* diffimg.1 $(pdf)
DISTCLEANFILES = $(pdf) diffimg.1.ps
