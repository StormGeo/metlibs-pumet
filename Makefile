# includefile contains LOCALDIR-definition
include ../conf/$(OSTYPE).mk

LIBNAME=puMet
LOCALIDIR=$(LOCALDIR)/include/$(LIBNAME)

INCLUDE=-I../include -I$(LOCALDIR)/include
DEFINES=

LOCALOPTIONS=
include ../conf/targets.mk
