# Makefile taken from Wikipedia.org

NAME = game

# Default build type
TYPE = release
#TYPE = beta
#TYPE = tools
#TYPE = debug
#TYPE = preprocessor

# Which libraries are linked
LIBRARIES = vuengine $(COMPONENTS)

# engine's home
VUENGINE_HOME = $(VBDE)libs/vuengine

# My home
MY_HOME = $(shell pwd)

# output dir
BUILD_DIR = build

# linked engine's home
LIBRARIES_PATH = $(BUILD_DIR)/

# Where to preprocess source files
PREPROCESSOR_WORKING_FOLDER = $(BUILD_DIR)/working

# All the modules
MODULES = $(NAME) $(LIBRARIES)

# Add directories to the include and library paths
INCLUDE_PATHS = $(shell find $(PREPROCESSOR_WORKING_FOLDER)/headers -type d -print)

# target's needed steps
ALL_TARGET_PREREQUISITES = dirs $(TARGET).vb $(PAD) $(DUMP_TARGET)
#ALL_TARGET_PREREQUISITES = portToNewSyntax dirs

# compiler
COMPILER_VERSION = 4.7
COMPILER_OUTPUT = c
COMPILER_NAME = v810

GCC = $(COMPILER_NAME)-gcc
AS = $(COMPILER_NAME)-as
LD = $(COMPILER_NAME)-ld
OBJCOPY = $(COMPILER_NAME)-objcopy
OBJDUMP = $(COMPILER_NAME)-objdump


# Small data sections' usage
MSDA_SIZE                       = 0
MEMORY_POOL_SECTION             =
NON_INITIALIZED_DATA_SECTION    =
INITIALIZED_DATA_SECTION        =
STATIC_SINGLETONS_DATA_SECTION  =
VIRTUAL_TABLES_DATA_SECTION     =

MEMORY_POOL_SECTION_ATTRIBUTE               = __MEMORY_POOL_SECTION_ATTRIBUTE=
NON_INITIALIZED_DATA_SECTION_ATTRIBUTE      = __NON_INITIALIZED_DATA_SECTION_ATTRIBUTE=
INITIALIZED_DATA_SECTION_ATTRIBUTE          = __INITIALIZED_DATA_SECTION_ATTRIBUTE=
STATIC_SINGLETONS_DATA_SECTION_ATTRIBUTE    = __STATIC_SINGLETONS_DATA_SECTION_ATTRIBUTE=
VIRTUAL_TABLES_DATA_SECTION_ATTRIBUTE       = __VIRTUAL_TABLES_DATA_SECTION_ATTRIBUTE=


# include overrides
CONFIG_MAKE_FILE = $(shell pwd)/config.make
include $(CONFIG_MAKE_FILE)

ifneq ($(BUILD_MODE),)
TYPE = $(BUILD_MODE)
endif

OPTIMIZATION_OPTION = -O0
ifneq ($(OPTIMIZATION),)
OPTIMIZATION_OPTION = -$(OPTIMIZATION)
endif

PEDANTIC_WARNINGS_FLAG =
ifeq ($(PRINT_PEDANTIC_WARNINGS), 1)
PEDANTIC_WARNINGS_FLAG = -pedantic
endif

DUMP_TARGET =
ifeq ($(DUMP_ELF), 1)
DUMP_TARGET = dump
endif

PAD =
ifeq ($(PAD_ROM), 1)
PAD = pad
endif

STORE_SUFFIX =
PROLOG_FUNCTIONS_FLAG =
ifeq ($(USE_PROLOG_FUNCTIONS), 1)
PROLOG_FUNCTIONS_FLAG = -mprolog-function
STORE_SUFFIX = -pf
endif

FRAME_POINTER_USAGE_FLAG = -fomit-frame-pointer
ifeq ($(USE_FRAME_POINTER), 1)
FRAME_POINTER_USAGE_FLAG = -fno-omit-frame-pointer
endif

USE_CUSTOM_LINKER_SCRIPT =

ifneq ($(MEMORY_POOL_SECTION),)
MEMORY_POOL_SECTION_ATTRIBUTE = __MEMORY_POOL_SECTION_ATTRIBUTE="__attribute__((section(\"$(MEMORY_POOL_SECTION)\")))"
USE_CUSTOM_LINKER_SCRIPT = 1
endif

ifneq ($(NON_INITIALIZED_DATA_SECTION),)
NON_INITIALIZED_DATA_SECTION_ATTRIBUTE = __NON_INITIALIZED_DATA_SECTION_ATTRIBUTE="__attribute__((section(\"$(NON_INITIALIZED_DATA_SECTION)\")))"
USE_CUSTOM_LINKER_SCRIPT = 1
endif

ifneq ($(INITIALIZED_DATA_SECTION),)
INITIALIZED_DATA_SECTION_ATTRIBUTE = __INITIALIZED_DATA_SECTION_ATTRIBUTE="__attribute__((section(\"$(INITIALIZED_DATA_SECTION)\")))"
USE_CUSTOM_LINKER_SCRIPT = 1
endif

ifneq ($(STATIC_SINGLETONS_DATA_SECTION),)
STATIC_SINGLETONS_DATA_SECTION_ATTRIBUTE = __STATIC_SINGLETONS_DATA_SECTION_ATTRIBUTE="__attribute__((section(\"$(STATIC_SINGLETONS_DATA_SECTION)\")))"
USE_CUSTOM_LINKER_SCRIPT = 1
endif

ifneq ($(VIRTUAL_TABLES_DATA_SECTION),)
VIRTUAL_TABLES_DATA_SECTION_ATTRIBUTE = __VIRTUAL_TABLES_DATA_SECTION_ATTRIBUTE="__attribute__((section(\"$(VIRTUAL_TABLES_DATA_SECTION)\")))"
USE_CUSTOM_LINKER_SCRIPT = 1
endif

DATA_SECTION_ATTRIBUTES = $(MEMORY_POOL_SECTION_ATTRIBUTE) $(NON_INITIALIZED_DATA_SECTION_ATTRIBUTE) $(INITIALIZED_DATA_SECTION_ATTRIBUTE) $(STATIC_SINGLETONS_DATA_SECTION_ATTRIBUTE) $(VIRTUAL_TABLES_DATA_SECTION_ATTRIBUTE)

# linker script
LINKER_SCRIPT = $(VUENGINE_HOME)/lib/compiler/linker/vb.ld
ifneq ($(USE_CUSTOM_LINKER_SCRIPT),)
LINKER_SCRIPT = $(shell pwd)/lib/compiler/linker/vb.ld
endif

# Where to store object and dependency files.
STORE = $(BUILD_DIR)/$(TYPE)$(STORE_SUFFIX)

# Which directories contain source files
SOURCES_DIRS = $(shell find source assets -type d -print)
HEADERS_DIRS = $(shell find source -type d -print)

# Obligatory headers
CONFIG_FILE =       $(shell pwd)/source/config.h
ESSENTIAL_HEADERS = -include $(CONFIG_FILE) \
					-include $(VUENGINE_HOME)/source/libvuengine.h

# Common macros for all build types
COMMON_MACROS = $(DATA_SECTION_ATTRIBUTES)

# The next blocks changes some variables depending on the build type
ifeq ($(TYPE),debug)
LD_PARAMS = -T$(LINKER_SCRIPT) -lm
C_PARAMS = $(ESSENTIAL_HEADERS) $(PROLOG_FUNCTIONS_FLAG) $(FRAME_POINTER_USAGE_FLAG) $(PEDANTIC_WARNINGS_FLAG) $(OPTIMIZATION_OPTION) -std=gnu99 -mv810 -nodefaultlibs -Wall -Wextra -finline-functions -Winline
MACROS = __DEBUG __TOOLS $(COMMON_MACROS)
endif

ifeq ($(TYPE), release)
LD_PARAMS = -T$(LINKER_SCRIPT) -lm
C_PARAMS = $(ESSENTIAL_HEADERS) $(PROLOG_FUNCTIONS_FLAG) $(FRAME_POINTER_USAGE_FLAG) $(PEDANTIC_WARNINGS_FLAG) $(OPTIMIZATION_OPTION) -std=gnu99 -mv810 -nodefaultlibs -Wall -Wextra -finline-functions -Winline
MACROS = __RELEASE $(COMMON_MACROS)
endif

ifeq ($(TYPE), beta)
LD_PARAMS = -T$(LINKER_SCRIPT) -lm
C_PARAMS = $(ESSENTIAL_HEADERS) $(PROLOG_FUNCTIONS_FLAG) $(FRAME_POINTER_USAGE_FLAG) $(PEDANTIC_WARNINGS_FLAG) $(OPTIMIZATION_OPTION) -std=gnu99 -mv810 -nodefaultlibs -Wall -Wextra -finline-functions -Winline
MACROS = __BETA $(COMMON_MACROS)
endif

ifeq ($(TYPE), tools)
LD_PARAMS = -T$(LINKER_SCRIPT) -lm
C_PARAMS = $(ESSENTIAL_HEADERS) $(PROLOG_FUNCTIONS_FLAG) $(FRAME_POINTER_USAGE_FLAG) $(PEDANTIC_WARNINGS_FLAG) $(OPTIMIZATION_OPTION) -std=gnu99 -mv810 -nodefaultlibs -Wall -Wextra -finline-functions -Winline
MACROS = __TOOLS $(COMMON_MACROS)
endif

ifeq ($(TYPE),preprocessor)
ALL_TARGET_PREREQUISITES = dirs $(VUENGINE) $(C_OBJECTS) printPostPreprocessorInfo
LD_PARAMS =
C_PARAMS = -std=gnu99 -mv810 -nodefaultlibs -Wall -Wextra -E
MACROS = $(COMMON_MACROS)
endif

# Makefs a list of the source (.c) files.
C_SOURCE = $(foreach DIR,$(SOURCES_DIRS),$(wildcard $(DIR)/*.c))

# Makes a list of the source (.s) files.
ASSEMBLY_SOURCE = $(foreach DIR,$(SOURCES_DIRS),$(wildcard $(DIR)/*.s))

# List of header files.
HEADERS = $(foreach DIR,$(HEADERS_DIRS),$(wildcard $(DIR)/*.h))

# Makes a list of the header files that will have to be created.
H_FILES = $(addprefix $(PREPROCESSOR_WORKING_FOLDER)/headers/$(NAME)/, $(HEADERS:.h=.h))

# Makes a list of the object files that will have to be created.
C_OBJECTS = $(addprefix $(STORE)/objects/$(NAME)/, $(C_SOURCE:.c=.o))
C_INTERMEDIATE_SOURCES = $(addprefix $(STORE)/sources/$(NAME)/, $(C_SOURCE:.c=.c))

# Makes a list of the object files that will have to be created.
ASSEMBLY_OBJECTS = $(addprefix $(STORE)/objects/$(NAME)/, $(ASSEMBLY_SOURCE:.s=.o))

# Same for the .d (dependency) files.
D_FILES = $(addprefix $(STORE)/,$(C_SOURCE:.c=.d))

HELPERS_PREFIX = $(NAME)

# Class setup file
SETUP_CLASSES = $(HELPERS_PREFIX)SetupClasses
SETUP_CLASSES_OBJECT = $(STORE)/objects/$(NAME)/$(SETUP_CLASSES)
FINAL_SETUP_CLASSES = setupClasses
FINAL_SETUP_CLASSES_OBJECT = $(STORE)/objects/$(FINAL_SETUP_CLASSES)

# File that holds the classes hierarchy
CLASSES_HIERARCHY_FILE=$(PREPROCESSOR_WORKING_FOLDER)/$(HELPERS_PREFIX)ClassesHierarchy.txt

# Main target. The @ in front of a command prevents make from displaying it to the standard output.

# first build the engine
ENGINE = libvuengine.a

# the target file
TARGET_FILE = output
TARGET = $(STORE)/$(TARGET_FILE)-$(TYPE)

# define the engine
VUENGINE = $(BUILD_DIR)/libvuengine.a

all: printBuildingInfo $(ALL_TARGET_PREREQUISITES)

printBuildingInfo:
	@echo Building $(TARGET).vb
	@echo Build type: $(TYPE)
	@echo Compiler: $(COMPILER_NAME) $(COMPILER_VERSION)
	@echo Compiler\'s output: $(COMPILER_OUTPUT)

portToNewSyntax: dirs
	@sh $(VUENGINE_HOME)/lib/compiler/preprocessor/cleanSyntax.sh $(VUENGINE_HOME) $(MY_HOME)/source $(PREPROCESSOR_WORKING_FOLDER)

printPostPreprocessorInfo:
	@echo Done compiling in $(TYPE) mode with GCC $(COMPILER_VERSION)

dump: $(TARGET).elf
	@echo Dumping elf
	@$(OBJDUMP) -t $(TARGET).elf > $(STORE)/sections-$(TYPE).txt
	@$(OBJDUMP) -S $(TARGET).elf > $(STORE)/machine-$(TYPE).asm
	@echo Dumping elf done

pad: $(TARGET).vb
	@echo Padding $(BUILD_DIR)/$(TARGET_FILE).vb
	@$(VUENGINE_HOME)/lib/utilities/padder $(BUILD_DIR)/$(TARGET_FILE).vb 3
	@echo " "

$(TARGET).vb: $(TARGET).elf
	@echo Creating $@
	@$(OBJCOPY) -O binary $(TARGET).elf $@
	@cp $(TARGET).vb $(BUILD_DIR)/$(TARGET_FILE).vb
	@echo Done creating $(BUILD_DIR)/$(TARGET_FILE).vb in $(TYPE) mode with GCC $(COMPILER_VERSION)

$(TARGET).elf: $(H_FILES) libraries $(C_OBJECTS) $(C_INTERMEDIATE_SOURCES) $(ASSEMBLY_OBJECTS) $(SETUP_CLASSES_OBJECT).o $(FINAL_SETUP_CLASSES_OBJECT).o
	@echo Linking $(TARGET).elf
	@$(GCC) -o $@ -nostartfiles $(C_OBJECTS) $(ASSEMBLY_OBJECTS) $(FINAL_SETUP_CLASSES_OBJECT).o $(SETUP_CLASSES_OBJECT).o $(LD_PARAMS) \
		$(foreach LIBRARY, $(LIBRARIES),-l$(shell sed -e "s@.*/@@" <<< $(LIBRARY))) $(foreach LIB,$(LIBRARIES_PATH),-L$(LIB)) -Wl,-Map=$(TARGET).map

$(SETUP_CLASSES_OBJECT).o: $(PREPROCESSOR_WORKING_FOLDER)/$(SETUP_CLASSES).c
	@echo -n "Compiling "
	@sed -e 's#'"$(STORE)"/sources/$(NAME)/'##g' <<< $<
	@$(GCC) -Wp,-MD,$*.dd $(foreach INC,$(INCLUDE_PATHS),-I$(INC))\
        $(foreach MACRO,$(MACROS),-D$(MACRO)) $(C_PARAMS) -$(COMPILER_OUTPUT) $< -o $@
	@sed -e '1s/^\(.*\)$$/$(subst /,\/,$(dir $@))\1/' $*.dd > $*.d
	@rm -f $*.dd

$(PREPROCESSOR_WORKING_FOLDER)/$(SETUP_CLASSES).c: $(H_FILES)
	@sh $(VUENGINE_HOME)/lib/compiler/preprocessor/setupClasses.sh -c $(CLASSES_HIERARCHY_FILE) -o $(SETUP_CLASSES).c -w $(PREPROCESSOR_WORKING_FOLDER)

$(FINAL_SETUP_CLASSES_OBJECT).o: $(PREPROCESSOR_WORKING_FOLDER)/$(FINAL_SETUP_CLASSES).c
	@echo -n "Compiling "
	@sed -e 's#'"$(STORE)"/sources/$(NAME)/'##g' <<< $<
	@$(GCC) -Wp,-MD,$*.dd $(foreach INC,$(INCLUDE_PATHS),-I$(INC))\
        $(foreach MACRO,$(MACROS),-D$(MACRO)) $(C_PARAMS) -$(COMPILER_OUTPUT) $< -o $@
	@sed -e '1s/^\(.*\)$$/$(subst /,\/,$(dir $@))\1/' $*.dd > $*.d
	@rm -f $*.dd

# Rule for creating object file and .d file, the sed magic is to add the object path at the start of the file
# because the files gcc outputs assume it will be in the same dir as the source file.
$(STORE)/objects/$(NAME)/%.o: $(STORE)/sources/$(NAME)/%.c
	@echo -n "Compiling "
	@sed -e 's#'"$(STORE)"/sources/$(NAME)/'##g' <<< $<
	@$(GCC) -Wp,-MD,$(STORE)/objects/$(NAME)/$*.dd $(foreach INC,$(INCLUDE_PATHS),-I$(INC))\
        $(foreach MACRO,$(MACROS),-D$(MACRO)) $(C_PARAMS) -$(COMPILER_OUTPUT) $< -o $@
	@sed -e '1s/^\(.*\)$$/$(subst /,\/,$(dir $@))\1/' $(STORE)/objects/$(NAME)/$*.dd > $(STORE)/objects/$(NAME)/$*.d
	@rm -f $(STORE)/objects/$(NAME)/$*.dd

$(STORE)/sources/$(NAME)/%.c: %.c
	@sh $(VUENGINE_HOME)/lib/compiler/preprocessor/processSourceFile.sh -i $< -o $@ -d -w $(PREPROCESSOR_WORKING_FOLDER) -c $(CLASSES_HIERARCHY_FILE) -p $(MODULES)

$(STORE)/objects/$(NAME)/%.o: %.s
	@echo Creating object file for $*
	@$(AS) -o $@ $<

$(PREPROCESSOR_WORKING_FOLDER)/headers/$(NAME)/%.h: %.h
	@echo Preprocessing $<
	@sh $(VUENGINE_HOME)/lib/compiler/preprocessor/processHeaderFile.sh -i $< -o $@ -w $(PREPROCESSOR_WORKING_FOLDER) -c $(CLASSES_HIERARCHY_FILE) -p $(HELPERS_PREFIX)

libraries: deleteLibraries
	@-$(foreach LIBRARY, $(LIBRARIES), echo; 																							\
		echo Building $(LIBRARY);																										\
		$(MAKE) all -f $(VBDE)libs/$(LIBRARY)/makefile $(BUILD_DIR)/lib$(shell sed -e "s@.*/@@" <<< $(LIBRARY)).a 						\
				-e TYPE=$(TYPE) 																										\
				-e CONFIG_FILE=$(CONFIG_FILE) 																							\
				-e CONFIG_MAKE_FILE=$(CONFIG_MAKE_FILE) 																				\
				-e COMPONENTS= 																				\
				-e GAME_HOME=$(MY_HOME);																								\
	)

deleteLibraries:
	-$(foreach LIBRARY, $(LIBRARIES), $(shell rm -f $(LIBRARIES_PATH)/$(LIBRARY)))


# Empty rule to prevent problems when a header is deleted.
%.h: ;

# Cleans up the objects, .d files and executables.
clean:
	@echo Cleaning $(TYPE)...$(STORE)
#	@find $(BUILD_DIR) -maxdepth 1 -type f -exec rm -f {} \;
	@rm -Rf $(STORE)
	@echo Cleaning done.

# Create necessary directories
dirs:
	@echo Checking working dirs..
	@-if [ ! -e $(PREPROCESSOR_WORKING_FOLDER)/headers/$(NAME) ]; then mkdir -p $(PREPROCESSOR_WORKING_FOLDER)/headers/$(NAME); fi;
	@-$(foreach DIR,$(HEADERS_DIRS), if [ ! -e $(PREPROCESSOR_WORKING_FOLDER)/headers/$(NAME)/$(DIR) ]; \
         then mkdir -p $(PREPROCESSOR_WORKING_FOLDER)/headers/$(NAME)/$(DIR); fi; )
	@-if [ ! -e $(STORE)/sources/$(NAME) ]; then mkdir -p $(STORE)/sources/$(NAME); fi;
	@-$(foreach DIR,$(SOURCES_DIRS), if [ ! -e $(STORE)/sources/$(NAME)/$(DIR) ]; \
         then mkdir -p $(STORE)/sources/$(NAME)/$(DIR); fi; )
	@-if [ ! -e $(STORE)/objects/$(NAME) ]; then mkdir -p $(STORE)/objects/$(NAME); fi;
	@-$(foreach DIR,$(SOURCES_DIRS), if [ ! -e $(STORE)/objects/$(NAME)/$(DIR) ]; \
         then mkdir -p $(STORE)/objects/$(NAME)/$(DIR); fi; )


# Includes the .d files so it knows the exact dependencies for every source
-include $(D_FILES)
