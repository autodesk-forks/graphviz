## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = -I$(top_srcdir)/lib

noinst_HEADERS = ast.h error.h hashkey.h
noinst_LTLIBRARIES = libast_C.la

libast_C_la_SOURCES = pathpath.c sfstr.h chresc.c chrtoi.c error.c \
	fmtbuf.c fmtesc.c pathaccess.c pathbin.c pathcanon.c pathcat.c \
	pathexists.c pathfind.c pathgetlink.c \
	strcopy.c stresc.c strmatch.c

EXTRA_DIST = compat_unistd.h ast.vcxproj*
