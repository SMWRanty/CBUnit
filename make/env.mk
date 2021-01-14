BUILD_DIRECTORY						:= build
BINARY_DIRECTORY					:= bin
SOURCE_DIRECTORY 					:= src
INCLUDE_DIRECTORY 				:= include
COMMAND_DIRECTORY 				:= cmd

SOURCE_FILES							=

$(BUILD_DIRECTORY)/%.o: %.cpp
	$(MKDIR) $(@D)
	$(CPP) -c -o $@ $<