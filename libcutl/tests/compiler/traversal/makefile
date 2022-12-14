# file      : tests/compiler/traversal/makefile
# copyright : Copyright (c) 2009-2013 Code Synthesis Tools CC
# license   : MIT; see accompanying LICENSE file

include $(dir $(lastword $(MAKEFILE_LIST)))../../../build/bootstrap.make

cxx_tun := driver.cxx

#
#
cxx_obj  := $(addprefix $(out_base)/,$(cxx_tun:.cxx=.o))
cxx_od   := $(cxx_obj:.o=.o.d)

cutl.l             := $(out_root)/cutl/cutl.l
cutl.l.cpp-options := $(out_root)/cutl/cutl.l.cpp-options

driver   := $(out_base)/driver
test     := $(out_base)/.test
clean    := $(out_base)/.clean

# Build.
#
$(driver): $(cxx_obj) $(cutl.l)
$(cxx_obj) $(cxx_od): $(cutl.l.cpp-options)


$(call include-dep,$(cxx_od))


# Alias for default target.
#
$(out_base)/: $(driver)


# Test.
#
$(test): driver := $(driver)
$(test): $(driver) $(src_base)/output.std
	$(call message,test $$1,$$1 | diff -u $(src_base)/output.std -,$(driver))


# Clean.
#
$(clean):                            \
  $(driver).o.clean                  \
  $(addsuffix .cxx.clean,$(cxx_obj)) \
  $(addsuffix .cxx.clean,$(cxx_od))


# Generated .gitignore.
#
ifeq ($(out_base),$(src_base))
$(driver): | $(out_base)/.gitignore

$(out_base)/.gitignore: files := driver
$(clean): $(out_base)/.gitignore.clean

$(call include,$(bld_root)/git/gitignore.make)
endif


# How to.
#
$(call include,$(bld_root)/cxx/o-e.make)
$(call include,$(bld_root)/cxx/cxx-o.make)
$(call include,$(bld_root)/cxx/cxx-d.make)

# Dependencies.
#
$(call import,$(src_root)/cutl/makefile)
