# file      : tests/xml/makefile
# copyright : Copyright (c) 2009-2013 Code Synthesis Tools CC
# license   : MIT; see accompanying LICENSE file

include $(dir $(lastword $(MAKEFILE_LIST)))../../build/bootstrap.make

tests := parser serializer roundtrip

default   := $(out_base)/
test      := $(out_base)/.test
clean     := $(out_base)/.clean

$(default): $(addprefix $(out_base)/,$(addsuffix /,$(tests)))
$(test): $(addprefix $(out_base)/,$(addsuffix /.test,$(tests)))
$(clean): $(addprefix $(out_base)/,$(addsuffix /.clean,$(tests)))

$(foreach t,$(tests),$(call import,$(src_base)/$t/makefile))
