FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

COPY requirements.txt ./requirements.txt

RUN apt-get update -y \
&& apt-get install --no-install-recommends -y \
# Development tools
build-essential \
git \
pkg-config \
autoconf \
bison \
libtool \
flex \
ksh \
# Debian build utilities
quilt \
d-shlibs \
debhelper \
fakeroot \
# Option glut
freeglut3-dev \
# Option gts
libgts-dev \
# Option swig
swig \
# Command lefty
libxaw7-dev \
# Command smyra
libgtkglext1-dev \
libglade2-dev \
# Command gvedit
libqt5gui5 \
qt5-qmake \
qt5-default \
# Plugin library devil
libdevil-dev \
# Plugin library gd
libgd-dev \
# Documentation
ghostscript \
# Plugin library ghostscipt
libgs-dev \
# Plugin library lasi
liblasi-dev \
# Plugin library poppler
libpoppler-dev \
libpoppler-glib-dev \
# Plugin library rsvg
librsvg2-dev \
# Plugin library webp
libwebp-dev \
# Language extension gv_sharp & gv_ruby
ruby \
# Language extension gv_go
golang-go \
# Language extension gv_guile
guile-2.2 \
guile-2.2-dev \
# Language extension gv_lua
lua5.3 \
liblua5.3-dev \
# Language extension gv_ocaml
ocaml \
# Language extension gv_perl
libperl-dev \
# Language extension gv_php
php-dev \
libsodium-dev \
libargon2-0-dev \
# Language extension gv_python & gv_python2
python2.7-dev \
# Language extension gv_python3
libpython3-dev \
# Language extension gv_ruby
ruby-dev \
# Language extension gv_tcl
tcl-dev \
# Test utilities
python3-pip \
python3-setuptools \
# install Python dependencies
&& python3 -m pip install --user --upgrade pip \
&& python3 -m pip install --user --requirement requirements.txt \
# Clean up
&& rm -rf /var/lib/apt/lists/*
