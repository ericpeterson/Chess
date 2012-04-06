################################################################################
# CS 240 Chess Project Makefile
#
# INSTRUCTIONS: This is a starting makefile for the chess project. You are to 
# keep this up-to-date as you add source files. In addition to keeping it 
# up-to-date with new files you create, you need to make the following changes 
# to this makefile:
# 
#	- compile the object files associated with the View into a shared library, 
#	- add pseudo-targets for the different run modes (namely "runhh", "runhc",
#		"runch", and "runcc"),
#	- add a "test" pseudo-target (you will probably want to make a new executable
#		for this with its own main method),
#	- add a "lib" pseudo-target,
#	- edit the command associated with the memcheck pseudo-target (i.e.,
#		the valgrind command. See the note above it for details).
# 
# NOTES: 
# 1. All the code for the GUI side of this project is provided for you. As a 
# result, there are some things in this makefile which you do not need to alter.
# Such items will be clearly marked with comments.
# 2. Out-of-the-box, without making any changes to this initial makefile, 
# running "make run" will compile the code and bring up an empty GUI. 
################################################################################

 
############### --- BEGIN UNTOUCHABLE SECTION - Do Not Edit --- ################
# Macros for GUI libraries.
GTKMM = gtkmm-2.4
SIGC = sigc++-2.0
LIBGLADE = libglademm-2.4

# TODO Re-phrase: CFLAGS are the -I values needed to compile files using the 
# GTKMM, SIGC, and LIBGLADE libraries
CFLAGS = `pkg-config $(GTKMM) $(SIGC) $(LIBGLADE) --cflags`
# TODO Re-phrase: LIBS are the paths to the static libraries for GTKMM, SIGC,
# and LIBGLADE needed for linking
LIBS   = `pkg-config $(GTKMM) $(SIGC) $(LIBGLADE) --libs`
####################### --- END UNTOUCHABLE SECTION --- ########################


# TODO Re-phrase: Macros for directory tree locations
MODEL_SRC = model/src/
MODEL_INC = model/inc/
MODEL_OBJ = model/obj/
MODEL_DEP = model/dep/make.dep
VIEW_SRC = view/src/
VIEW_INC = view/inc/
VIEW_OBJ = view/obj/
CONT_SRC = controller/src/
CONT_INC = controller/inc/
CONT_OBJ = controller/obj/
CONT_DEP = controller/dep/make.dep
TEST_DRIVER_SRC = test/src/
TEST_DRIVER_OBJ = test/obj/
TEST_DRIVER_DEP = test/dep/make.dep
UTILS_INC = utils/include/
EXE = bin/chess			# normal executable
MEXE = bin/mchess			# executable for memory testing
TEST_DRIVER_EXE = bin/test-driver


# Macros for compilation flags
INCLUDES = -I$(MODEL_INC) -I$(VIEW_INC) -I$(CONT_INC) -I$(UTILS_INC)
DEBUG = -g # Uncomment this if you want to compile with debug info

# Uncomment the flag on this next line to turn off the logging messages from the
# GUI
LOG_FLAG = #'-DLOG_LEVEL_HIDE_MASK=(G_LOG_LEVEL_DEBUG|G_LOG_LEVEL_INFO)'


# There are two different main.o files. One is for memory testing.
MAIN_O = $(CONT_OBJ)main.o
MEMMAIN_O = $(CONT_OBJ)memcheck_main.o

# Test driver .o file
TEST_DRIVER_O = $(TEST_DRIVER_OBJ)TestDriver.o

# This macro should be used to store all of the object files created 
# from *your* source files
MY_OBJS = $(CONT_OBJ)ChessController.o $(MODEL_OBJ)Board.o\
  $(MODEL_OBJ)BoardPosition.o $(MODEL_OBJ)Square.o

# Test driver object files 
TEST_DRIVER_OBJS = $(TEST_DRIVER_O) $(MODEL_SRC)*.cpp

# These are all the object files that go into the library
LIB_OBJS = $(VIEW_OBJ)ChessView.o \
      $(VIEW_OBJ)ChessGuiBoardCell.o \
      $(VIEW_OBJ)ChessGuiBoard.o \
      $(VIEW_OBJ)ChessGui.o \
      $(VIEW_OBJ)ChessGuiImages.o \
      $(VIEW_OBJ)SelectDialog.o





################################################################################
# Pseudo-targets

runhc: $(EXE)
	@export LD_LIBRARY_PATH="/users/guest/p/peter2/cs240/Chess/source/lib:\
	/home/eric/School/Chess/source/lib"; $(EXE) 1

runch: $(EXE)
	@export LD_LIBRARY_PATH="/users/guest/p/peter2/cs240/Chess/source/lib:\
	/home/eric/School/Chess/source/lib"; $(EXE) 2

runhh: $(EXE)
	@export LD_LIBRARY_PATH="/users/guest/p/peter2/cs240/Chess/source/lib:\
	/home/eric/School/Chess/source/lib"; $(EXE) 3

runcc: $(EXE)
	@export LD_LIBRARY_PATH="/users/guest/p/peter2/cs240/Chess/source/lib:\
	/home/eric/School/Chess/source/lib"; $(EXE) 4

bin: $(EXE)

test: $(TEST_DRIVER_EXE)
	$(TEST_DRIVER_EXE)


# Run the executable for memory testing
# Instructions: Edit the command below so that it runs the  
# memory-check executable in Human-Human mode (i.e., add necessary command  
# line arguments to the end of valgrind the command below).	
memcheck: $(MEXE)
	valgrind --tool=memcheck --leak-check=yes --max-stackframe=5000000 --show-reachable=yes --suppressions=string.supp $(MEXE) #command-line args go here

LIB = ./lib/libchessgui.so

lib: $(LIB)


# Clean removes all of the .o files, libraries, and executables
clean:
	@rm -f $(MODEL_OBJ)*.o
	@rm -f $(VIEW_OBJ)*.o
	@rm -f $(CONT_OBJ)*.o
	@rm -f $(TEST_DRIVER_OBJ)*.o
	@rm -f $(EXE)
	@rm -f $(MEXE)
	@rm -f $(TEST_DRIVER_EXE)
	@rm -f $(LIB)

clean-dep:
	@rm -f $(MODEL_DEP)
	@rm -f $(CONT_DEP)
	@rm -f $(TEST_DRIVER_DEP)

.PHONY: runhc runch runhh runcc bin test memcheck lib clean 

################################################################################
# Targets for executables and main object files

# Explanation: There are two different executables, with two different main 
# object files, because main.cpp needs to be built differently depending on 
# whether you are doing memory testing or not. This is because the GTK library,
# and other GUI tools, have memory leaks that we cannot figure out how to 
# suppress. Therefore, when building an executable for memory testing, we use a
# macro (MEMCHECK) to tell the compiler to not include the code that builds the
# GUI. So when we check for memory leaks during passoff, we don't have to use
# the GUI.

LFLAGS = -L./lib -lchessgui

# Main executable
# Note: Once you have added the ability to make a library out of the View files, 
# the executable should be dependent on, and link in the library file, not the 
# .o files! That means, instead of linking in $(LIB_OBJS) below, you should link
# in the actual library file.
$(EXE): $(MAIN_O) $(MY_OBJS) $(LIB)
	@# Re-link executable. Again, this should link the library file, not the .o's
	g++ $(INCLUDES) -o $(EXE) $(MAIN_O) $(MY_OBJS) $(CFLAGS) $(LFLAGS) $(LIBS) 
	chmod ugo+x $(EXE)

# Executable for memory testing
$(MEXE): $(MEMMAIN_O) $(MY_OBJS) $(LIB)
	@# Re-link executable. Again, this should link the library file, not the .o's
	g++ $(INCLUDES) -o $(MEXE) $(MEMMAIN_O) $(MY_OBJS) $(CFLAGS) $(LFLAGS) $(LIBS)
	chmod ugo+x $(MEXE)
	

EFLAGS = -Wall -Werror

# Main object file
$(MAIN_O): $(CONT_SRC)main.cpp $(VIEW_INC)ChessGuiImages.h $(VIEW_INC)ChessView.h
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(MAIN_O) -c $(EFLAGS) $(LOG_FLAG) $(CONT_SRC)main.cpp

# Main .o for memory testing
$(MEMMAIN_O): $(CONT_SRC)main.cpp $(VIEW_INC)ChessGuiImages.h $(VIEW_INC)ChessView.h
	g++ -DMEMCHECK $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(MEMMAIN_O) -c $(EFLAGS) $(LOG_FLAG) $(CONT_SRC)main.cpp



################################################################################
# Targets for YOUR object files...

SHARED = -shared

$(LIB): $(LIB_OBJS)
	g++ $(SHARED) -o $(LIB) $(LIB_OBJS)

MY_CFLAGS = -c $(EFLAGS)


$(TEST_DRIVER_EXE): $(TEST_DRIVER_OBJS)
	g++ $(INCLUDES) -o $@ $^

$(MODEL_OBJ)%.o:
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) $(LOG_FLAG) $(MY_CFLAGS) -o $@ $<

$(CONT_OBJ)%.o:
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) $(LOG_FLAG) $(MY_CFLAGS) -o $@ $<

$(TEST_DRIVER_OBJ)%.o:
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) $(LOG_FLAG) $(MY_CFLAGS) -o $@ $< 


################################################################################
# Targets for GUI-related object files
# Instructions: These will have to be recompiled as position-independent code, 
# so that they can be put into a shared library.

# compile as position independent code
PIC = -fPIC

$(VIEW_OBJ)ChessView.o: $(VIEW_SRC)ChessView.cpp $(VIEW_INC)SelectDialog.h $(VIEW_INC)ChessView.h $(CONT_INC)IChessController.h
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(VIEW_OBJ)ChessView.o -c $(EFLAGS) $(PIC) $(LOG_FLAG) $(VIEW_SRC)ChessView.cpp

$(VIEW_OBJ)ChessGuiBoardCell.o: $(VIEW_SRC)ChessGuiBoardCell.cpp $(VIEW_INC)ChessGuiBoardCell.h $(VIEW_INC)ChessGuiImages.h
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(VIEW_OBJ)ChessGuiBoardCell.o -c $(EFLAGS) $(PIC) $(VIEW_SRC)ChessGuiBoardCell.cpp

$(VIEW_OBJ)ChessGuiBoard.o: $(VIEW_SRC)ChessGuiBoard.cpp $(VIEW_INC)ChessGuiBoard.h $(VIEW_INC)ChessGui.h $(VIEW_INC)ChessGuiImages.h
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(VIEW_OBJ)ChessGuiBoard.o -c $(EFLAGS) $(PIC) $(VIEW_SRC)ChessGuiBoard.cpp

$(VIEW_OBJ)ChessGui.o: $(VIEW_SRC)ChessGui.cpp $(VIEW_INC)ChessGui.h $(VIEW_INC)ChessGuiImages.h $(VIEW_INC)SelectDialog.h
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(VIEW_OBJ)ChessGui.o -c $(EFLAGS) $(PIC) $(VIEW_SRC)ChessGui.cpp

$(VIEW_OBJ)ChessGuiImages.o: $(VIEW_SRC)ChessGuiImages.cpp $(VIEW_INC)ChessGuiImages.h $(VIEW_INC)Inline.h
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(VIEW_OBJ)ChessGuiImages.o -c $(EFLAGS) $(PIC) $(VIEW_SRC)ChessGuiImages.cpp

$(VIEW_OBJ)SelectDialog.o: $(VIEW_SRC)SelectDialog.cpp
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(VIEW_OBJ)SelectDialog.o -c $(EFLAGS) $(PIC) $(VIEW_SRC)SelectDialog.cpp


# Make dependencies
$(MODEL_DEP):
	@for CPP_FILE in $(MODEL_SRC)*.cpp; do\
	   CPP_BASE=$$(basename $$CPP_FILE);\
	   CPP_BASE_NO_EXT=$${CPP_BASE%%\.*};\
	   g++ $(INCLUDES) -MT $(MODEL_OBJ)$${CPP_BASE_NO_EXT}.o -MM $$CPP_FILE;\
	 done > $(MODEL_DEP)

$(CONT_DEP):
	@for CPP_FILE in $(CONT_SRC)*.cpp; do\
	   CPP_BASE=$$(basename $$CPP_FILE);\
	   CPP_BASE_NO_EXT=$${CPP_BASE%%\.*};\
	   g++ $(INCLUDES) -MT $(CONT_OBJ)$${CPP_BASE_NO_EXT}.o -MM $$CPP_FILE;\
	 done > $(CONT_DEP)

$(TEST_DRIVER_DEP):
	@for CPP_FILE in $(TEST_DRIVER_SRC)*.cpp; do\
	   CPP_BASE=$$(basename $$CPP_FILE);\
	   CPP_BASE_NO_EXT=$${CPP_BASE%%\.*};\
	   g++ $(INCLUDES) -MT $(TEST_DRIVER_OBJ)$${CPP_BASE_NO_EXT}.o -MM $$CPP_FILE;\
	 done > $(TEST_DRIVER_DEP)


include $(MODEL_DEP)
include $(CONT_DEP)
include $(TEST_DRIVER_DEP)
