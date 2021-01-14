#use the C++17 standard
CPP_STANDARD					:= -std=c++17
#treat all warnings as errors
CPP_WARNINGS					:= -Wall -Werror -Wextra
#no optimisation
CPP_OPTIMISATION 			= -O0
#generate dependecies based off headers (exclude system files) 
CPP_DEPENDENCIES			= -MMD
#add a .PHONY target for each dependency
CPP_DEPENDENCIES 			+= -MP 
#specify the output file
CPP_DEPENDENCIES 			+= -MF"$(@:%.o=%.d)"
#add the .o file and .d file as target
CPP_DEPENDENCIES 			+= -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)"
#generate debug info
CPP_DEBUG_INFO 				= -ggdb
#link functions and data as separate sections
CPP_SECTIONS					= -ffunction-sections -fdata-sections
#any additional #defines
CPP_DEFINES						=
#include directories
CPP_INCLUDES					=
#any additional options
CPP_ADDITIONAL				=

CPP_OPTIONS 					= $(CPP_STANDARD) $(CPP_WARNINGS) $(CPP_OPTIMISATION) $(CPP_DEPENDENCIES) $(CPP_DEBUG_INFO) $(CPP_INCLUDES) $(CPP_SECTIONS) $(CPP_ADDITIONAL) $(CPP_DEFINES)

CPP_COMPILER					= g++

CPP										= $(CPP_COMPILER) $(CPP_OPTIONS)