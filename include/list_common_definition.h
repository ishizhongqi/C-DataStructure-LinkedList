/**
 *@file list_common_definition.h
 * @author Shizhongqi (ishizhongqi@outlook.com)
 * @brief 列表通用的声明和定义
 * @version 0.1
 * @date 2024-06-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LIST_COMMON_DEFINITION_H
#define LIST_COMMON_DEFINITION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void* Element;

typedef bool (*CompareElement)(Element, Element);

#endif
