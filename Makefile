# 设定编译器
CC = gcc

# 设定源文件目录
SRCDIR = src
# 设定源文件目录
INCDIR = include
# 设定对象文件目录
OBJDIR = build
# 设定库文件目录
LIBDIR = lib

# 设定源文件列表（假设所有.c文件都需要编译）
SRCS = $(wildcard $(SRCDIR)/*.c)

# 设定对象文件列表（从源文件列表生成）
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# 设定库文件名
LIB = $(LIBDIR)/liblinkedlist.a

# 默认目标
all: $(LIB)

# 编译规则，从.c文件生成.o文件
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ -I$(INCDIR) -g -Wall

# 创建库文件的规则
$(LIB): $(OBJS)
	ar rcs $@ $(OBJS)

# 清理编译生成的文件
clean:
	rm -f $(OBJDIR)/*.o $(LIB)

# 确保对象文件目录存在
$(shell mkdir -p $(OBJDIR) $(LIBDIR) || true)

# 依赖关系，确保在编译之前对象文件目录存在
$(OBJS): | $(OBJDIR)
