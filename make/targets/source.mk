SOURCE_FILES =				 				$(SOURCE_DIRECTORY)/main.cpp \
															$(SOURCE_DIRECTORY)/Describe.cpp \
															$(SOURCE_DIRECTORY)/DescribeItem.cpp \
															$(SOURCE_DIRECTORY)/It.cpp \
															$(SOURCE_DIRECTORY)/Skip.cpp \
															$(SOURCE_DIRECTORY)/BeforeEach.cpp \
															$(SOURCE_DIRECTORY)/AfterEach.cpp \
															$(SOURCE_DIRECTORY)/Before.cpp \
															$(SOURCE_DIRECTORY)/After.cpp \
															$(SOURCE_DIRECTORY)/TestRunner.cpp \
															$(SOURCE_DIRECTORY)/Error.cpp \
															$(SOURCE_DIRECTORY)/TestFailure.cpp \
															$(SOURCE_DIRECTORY)/FileLineInfo.cpp \
															$(SOURCE_DIRECTORY)/TestOutput.cpp \
															$(SOURCE_DIRECTORY)/TestOutputUser.cpp \
															$(SOURCE_DIRECTORY)/TestMonitor.cpp \

OBJECT_FILES = 				$(patsubst $(SOURCE_DIRECTORY)/%.cpp, $(BUILD_DIRECTORY)/%.o, $(SOURCE_FILES))

CPP_INCLUDES += -Iinclude
cbunit: $(CBUNIT_LIBRARY) $(CBUNIT_COMMAND)

$(BUILD_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.cpp
	$(MKDIR) $(@D)
	$(CPP) -c -o $@ $^

$(BUILD_DIRECTORY)/command/%.o: $(COMMAND_DIRECTORY)/%.cpp
	$(MKDIR) $(@D)
	$(CPP) -c -o $@ $^

$(CBUNIT_LIBRARY): $(OBJECT_FILES)
	$(MKDIR) $(@D)
	ar rcs $@ $^

$(CBUNIT_COMMAND): $(BUILD_DIRECTORY)/command/main.o
	$(MKDIR) $(@D)
	$(CPP) -o $@ $^

cbunit-clean:
	$(REMOVE) $(CBUNIT_LIBRARY) $(OBJECT_FILES)

cbunit-purge:
	$(REMOVE) $(CBUNIT_LIBRARY) $(BUILD_DIRECTORY)

