## Process this file with automake to produce Makefile.in

SUBDIRS = demo

pkgtcldir = $(pkglibdir)/tcl
pdfdir = $(pkgdatadir)/doc/pdf

man = tkspline.3tk
if ENABLE_MAN_PDFS
if HAVE_PS2PDF
pdf = tkspline.3tk.pdf
else
pdf = ERROR_NO_PS2PDF
endif
else
pdf =
endif

# If all else fails there is a local copy of tkInt.h in tkstubs/
AM_CPPFLAGS = \
	-I@TK_SRC_DIR@/generic \
	-I@TCL_SRC_DIR@/generic \
	@TCL_INCLUDES@ @TCLINT_INCLUDES@ \
	@TK_INCLUDES@ @TKINT_INCLUDES@ -I$(top_srcdir)/tclpkg/tkstubs

AM_CFLAGS = @X_CFLAGS@ @TCL_CFLAGS@  @TK_CFLAGS@ @TK_DEFS@ \
	-UPACKAGE_NAME -UPACKAGE_STRING -UPACKAGE_TARNAME \
	-UPACKAGE_VERSION -UPACKAGE_BUGREPORT

if WITH_TK
pkgtcl_LTLIBRARIES = libtkspline.la
man_MANS = $(man)
if ENABLE_MAN_PDFS
pdf_DATA = tkspline.3tk.pdf
endif
endif

libtkspline_la_LDFLAGS = -no-undefined 
libtkspline_la_SOURCES = tkspline.c
libtkspline_la_LIBADD = \
	$(top_builddir)/tclpkg/tkstubs/libtkstubs_C.la \
	$(top_builddir)/tclpkg/tclstubs/libtclstubs_C.la @TK_LIB_SPEC@

if WITH_TK
all-local: pkgIndex.tcl

pkgIndex.tcl: libtkspline.la
	sh $(top_srcdir)/tclpkg/mkpkgindex.sh libtkspline.la Tkspline $(VERSION)
endif

if ENABLE_MAN_PDFS
if HAVE_PS2PDF
tkspline.3tk.pdf: tkspline.3tk.ps
	@PS2PDF@ $<

tkspline.3tk.ps: $(srcdir)/tkspline.3tk
	@GROFF@ -Tps -man $< >$@
endif
endif

EXTRA_DIST = $(man) $(pdf) dllEntry.c

CLEANFILES = pkgIndex.tcl

DISTCLEANFILES = $(pdf) tkspline.3tk.ps
