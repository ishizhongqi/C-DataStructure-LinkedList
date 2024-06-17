# The template repository for Linux C

本模板仓库主要是为了方便在新建C语言项目的时创建所需目录结构和文件。  
下面是目录结构概览：

    ./Project name/
    ├── bin/
    │   ├── EXAMPLE
    │   └── ...
    ├── build/
    │   ├── example1.o
    │   ├── example2.o
    │   └── ...
    ├── doc/
    │   ├── example1.md
    │   ├── example2.txt
    │   └── ...
    ├── include/
    │   ├── example1.h
    │   ├── example2.h
    │   └── ...
    ├── lib/
    │   ├── example1.a
    │   ├── example2.so
    │   └── ...
    ├── src/
    │   ├── example1.c
    │   ├── example2.c
    │   └── ...
    ├── makefile
    └── README.MD

下面是对目录结构的说明：  

| 文件/文件夹 | 说明 |
| :-----| :---- | 
| **bin/** | 存放编译后的可执行文件 | 
| **build/** | 存放编译时产生的 .o 文件 | 
| **doc/** | 存放需求文档、设计文档、使用手册等 | 
| **include/** | 存放 .h 头文件 | 
| **lib/** | 存放 .a 静态库和 .so 动态库 | 
| **src/** | 存放 .c 源文件 | 
| **test/** | 存放测试代码 | 
| **makefile** | 用于编译的makefile文件 | 
| **README.MD** | 用于描述项目的信息，比如项目的目的、如何构建项目、如何运行项目等 | 

还未完成，后续还会对文件内容进行更新...
