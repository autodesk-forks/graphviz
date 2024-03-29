## Process this file with automake to produce Makefile.in

SUBDIRS = demo

# tclhandle still needed for gd
TCLHANDLE_INCLUDES=-I$(top_srcdir)/tclpkg/tclhandle
TCLHANDLE_LIBS=$(top_builddir)/tclpkg/tclhandle/libtclhandle_C.la
if WITH_LIBGD
GDTCLFT_LIBS = $(top_builddir)/tclpkg/gdtclft/libgdtclft_C.la
endif

pdfdir = $(pkgdatadir)/doc/pdf
htmldir = $(pkgdatadir)/doc/html

pkgtcldir = $(pkglibdir)/tcl

AM_CPPFLAGS = \
	-I$(top_srcdir)/lib \
	-I$(top_srcdir)/lib/gvc \
	-I$(top_srcdir)/lib/common \
	-I$(top_srcdir)/lib/cgraph \
	-I$(top_srcdir)/lib/cdt \
	-I$(top_srcdir)/lib/pathplan $(TCLHANDLE_INCLUDES) $(GDLIB_CFLAGS) $(TCL_INCLUDES)

LIBS = -lc

AM_CFLAGS = $(TCL_CFLAGS)

man = tcldot.3tcl
if ENABLE_MAN_PDFS
if HAVE_PS2PDF
pdf = tcldot.3tcl.pdf
else
pdf = ERROR_NO_PS2PDF
endif
else
pdf =
endif
html = tcldot.html

if WITH_TCL
noinst_HEADERS = tcldot.h
pkgtcl_LTLIBRARIES = libtcldot.la libtcldot_builtin.la

man_MANS = $(man)
if ENABLE_MAN_PDFS
pdf_DATA = tcldot.3tcl.pdf
endif
html_DATA = $(html)
endif

libtcldot_la_SOURCES = \
	tcldot.c \
	tcldot-graphcmd.c \
	tcldot-nodecmd.c \
	tcldot-edgecmd.c \
	tcldot-util.c \
	tcldot-id.c \
	tcldot-io.c \
	no_builtins.c $(GDTCLFT)
libtcldot_la_CPPFLAGS = $(AM_CPPFLAGS) -DDEMAND_LOADING=1
libtcldot_la_LDFLAGS = -no-undefined 

libtcldot_la_LIBADD = $(TCLHANDLE_LIBS) $(GDTCLFT_LIBS) \
	$(top_builddir)/tclpkg/tclstubs/libtclstubs_C.la  \
	$(top_builddir)/lib/cdt/libcdt.la \
	$(top_builddir)/lib/cgraph/libcgraph.la \
	$(top_builddir)/lib/pathplan/libpathplan_C.la \
	$(top_builddir)/lib/gvc/libgvc.la 

libtcldot_la_DEPENDENCIES =  $(top_builddir)/lib/gvc/libgvc.la

# GDTCLFT requires gd libs to be builtin
if WITH_LIBGD
libtcldot_la_LIBADD += $(GDLIB_LIBS)
endif

libtcldot_la_LIBADD += $(MATH_LIBS)

libtcldot_builtin_la_SOURCES = \
	tcldot.c \
	tcldot-graphcmd.c \
	tcldot-nodecmd.c \
	tcldot-edgecmd.c \
	tcldot-util.c \
	tcldot-id.c \
	tcldot-io.c \
	tcldot_builtins.c $(GDTCLFT)
libtcldot_builtin_la_CPPFLAGS = $(AM_CPPFLAGS) -DDEMAND_LOADING=1
libtcldot_builtin_la_LDFLAGS =

libtcldot_builtin_la_LIBADD = $(TCLHANDLE_LIBS) \
	$(top_builddir)/plugin/dot_layout/libgvplugin_dot_layout_C.la \
	$(top_builddir)/plugin/neato_layout/libgvplugin_neato_layout_C.la \
	$(top_builddir)/plugin/core/libgvplugin_core_C.la \
	$(top_builddir)/lib/gvc/libgvc_C.la \
	$(top_builddir)/lib/cgraph/libcgraph_C.la \
	$(top_builddir)/lib/cdt/libcdt_C.la \
	$(top_builddir)/lib/pathplan/libpathplan_C.la \
	$(top_builddir)/tclpkg/tclstubs/libtclstubs_C.la $(GTS_LIBS)

if WITH_PANGOCAIRO
libtcldot_builtin_la_LIBADD += $(top_builddir)/plugin/pango/libgvplugin_pango_C.la $(PANGOCAIRO_LIBS) $(PANGOFT2_LIBS)
endif

if WITH_LIBGD
libtcldot_builtin_la_LIBADD += $(top_builddir)/plugin/gd/libgvplugin_gd_C.la
libtcldot_builtin_la_LIBADD += $(GD_LIBS)
endif

libtcldot_builtin_la_LIBADD += $(EXPAT_LIBS) $(SOCKET_LIBS) $(IPSEPCOLA_LIBS) $(MATH_LIBS)

# add a non-existent C++ source to force the C++ compiler to be used for
# linking, so the C++ standard library is included for our C++ dependencies
nodist_EXTRA_libtcldot_builtin_la_SOURCES = fake.cxx

if WITH_TCL
all-local: pkgIndex.tcl

pkgIndex.tcl: libtcldot.la
	sh $(top_srcdir)/tclpkg/mkpkgindex.sh libtcldot.la Tcldot $(VERSION)
endif

if ENABLE_MAN_PDFS
if HAVE_PS2PDF
tcldot.3tcl.pdf: tcldot.3tcl.ps
	@PS2PDF@ $<

tcldot.3tcl.ps: $(srcdir)/tcldot.3tcl
	@GROFF@ -Tps -man $< >$@
endif
endif

EXTRA_DIST = $(man) $(pdf) $(html) README README.Tkspline

CLEANFILES = pkgIndex.tcl

DISTCLEANFILES = $(pdf) tcldot.3tcl.ps
