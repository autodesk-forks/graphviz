## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-I$(top_srcdir)/lib \
	-I$(top_srcdir)/lib/common \
	-I$(top_srcdir)/lib/cgraph \
    -I$(top_srcdir)/lib/cdt

noinst_HEADERS = xlabels.h index.h node.h rectangle.h split.q.h
noinst_LTLIBRARIES = liblabel_C.la

liblabel_C_la_SOURCES = xlabels.c index.c node.c rectangle.c split.q.c

EXTRA_DIST = nrtmain.c

