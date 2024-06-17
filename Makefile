##########################################################
#
##########################################################

# The directories in which your files reside.
SRCDIR = ./src
OBJDIR = ./build
INCDIR = ./include
LIBDIR = ./lib
BINDIR = ./bin

# The executable file name. Must be specified.
PROGRAM := 

# The path of the executable file.
TARGET  := $(BINDIR)/$(PROGRAM)

# C program compilers.
CC      := gcc

# The options used in linking as well as in any direct use of ld.
LDFLAGS := -L$(LIBDIR)

# The libary options, e.g. "-lmysqlclient".
LIBS    := 

# Specify the macro definition that needs to be compiled, e.g. "-DDEBUG".
DEFINES := 

# Find the source files in source dirs.
SOURCES  := $(wildcard $(SRCDIR)/*.c)

# Specify the include dirs, e.g. "-I/usr/include/mysql -I./include -I/usr/include -I/usr/local/include".
INCLUDES := -I$(INCDIR)

# The generating object files (.o).
OBJS    := $(patsubst %.c,$(OBJ)/%.o,$(notdir $(SOURCES)))

# The compiler options.
CFLAGS  := -g -Wall

# The phony targets.
.PHONY : all clean

# The command used to compile when one directory contains multiple programs.
all : $(TARGET)

# The command used to delete file.
RM = rm -f

clean :
	$(RM) $(OBJS) $(TARGET)

# Rules for generating the executable.
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)

# Rules for generating object files (.o).
objs : $(OBJS)

%.o: %.c
	$(CC) $(INCLUDES) $(DEFINES) -c $(CFLAGS) $< -o $@
