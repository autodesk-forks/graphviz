## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-I$(top_srcdir)/lib \
        -I$(top_srcdir)/lib/common \
	-I$(top_srcdir)/lib/gvc \
	-I$(top_srcdir)/lib/pack \
	-I$(top_srcdir)/lib/pathplan \
	-I$(top_srcdir)/lib/cgraph \
	-I$(top_srcdir)/lib/cdt

noinst_HEADERS = patchwork.h tree_map.h
noinst_LTLIBRARIES = libpatchwork_C.la

libpatchwork_C_la_SOURCES = patchwork.c patchworkinit.c tree_map.c

EXTRA_DIST = gvpatchwork.vcxproj*
