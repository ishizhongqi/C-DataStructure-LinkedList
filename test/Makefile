# 设置编译器
# Set the compiler
CC = gcc

# 设定源文件目录
SRCDIR = .
# 设定源文件目录
INCDIR = ../include
# 设定对象文件目录
OBJDIR = .
# 设定库文件目录
LIBDIR = ../lib

# 源文件列表（所有.c文件）
# List of source files (.c files)
SRCS = $(wildcard $(SRCDIR)/*.c)

# 对象文件列表（从源文件列表生成）
# List of object files (generated from source file list)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

LIBS = -L$(LIBDIR) -llinkedlist

# 可执行文件名
# Executable file name
TARGET = test

# 默认目标
# Default target
all: $(TARGET)

# 编译规则：从.c文件生成.o文件
# Compilation rule: Generate .o files from .c files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ -I$(INCDIR) -I. -g -Wall

# 链接规则：从.o文件生成可执行文件
# Linking rule: Generate the executable file from .o files
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@

# 清理编译生成的文件
# Clean up compiled files
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

# 显示帮助信息
# Display help information
help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all    - Build the executable (default)"
	@echo "  clean  - Remove object files and the executable"
	@echo "  help   - Display this help message"

# 确保编译生成的可执行文件目录存在
# Ensure that the directory for the executable exists
$(shell mkdir -p $(OBJDIR) || true)

# 依赖关系，确保在编译之前对象文件目录存在
# Dependency to ensure the object file directory exists before compilation
$(OBJS): | $(OBJDIR)