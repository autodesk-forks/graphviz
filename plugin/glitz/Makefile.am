## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-I$(top_srcdir)/lib \
	-I$(top_srcdir)/lib/common \
	-I$(top_srcdir)/lib/pathplan \
	-I$(top_srcdir)/lib/gvc \
	-I$(top_srcdir)/lib/cgraph \
	-I$(top_srcdir)/lib/cdt \
	$(PANGOCAIRO_CFLAGS) $(GLITZ_CFLAGS)

if WITH_PANGOCAIRO
if WITH_GLITZ
noinst_LTLIBRARIES = libgvplugin_glitz_C.la
if WITH_WIN32
lib_LTLIBRARIES = libgvplugin_glitz.la
else
pkglib_LTLIBRARIES = libgvplugin_glitz.la
endif
endif
endif

libgvplugin_glitz_C_la_SOURCES = \
	gvplugin_glitz.c \
	gvdevice_glitz.c

libgvplugin_glitz_la_LDFLAGS = -version-info @GVPLUGIN_VERSION_INFO@
libgvplugin_glitz_la_SOURCES = $(libgvplugin_glitz_C_la_SOURCES)
libgvplugin_glitz_la_LIBADD = @PANGOCAIRO_LIBS@ @GLITZ_LIBS@

if WITH_WIN32
libgvplugin_glitz_la_LDFLAGS += -no-undefined
endif

if WITH_DARWIN9
libgvplugin_glitz_la_LDFLAGS += -Wl,-exported_symbol,_gvplugin_glitz_LTX_library
endif
