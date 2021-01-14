#run the help target if specified with no parameters
default: help

MAKEFILE_DIRECTORY := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

#standard linux command line tools
include make/commands.mk
#c++ build tools
include make/c++.mk
#environment variable (build directory, library directory, ...)
include make/env.mk
#linker build tools
include make/linker.mk
#help targets
include make/help.mk

CBUNIT_LIBRARY = $(BINARY_DIRECTORY)/cbunit.lib
CBUNIT_COMMAND = $(BINARY_DIRECTORY)/cbunit

#build targets
include make/targets.mk