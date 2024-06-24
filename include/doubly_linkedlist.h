/**
 * @file doubly_linkedlist.h
 * @author Shizhongqi (ishizhongqi@outlook.com)
 * @brief 双链表的创建、增加、删除、查找、释放。
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024 Shizhongqi
 *
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "list_common_definition.h"

 /**
  * @brief 含头结点的双链表，创建后请勿对头结点进行操作。
  *        头结点的index为0，含数据的结点从1开始。
  *        处理链表时用DLinkedList，处理结点时用DNode。
  *        当然DLinkedList本质上是DNode的指针，同理DLinkedList指针是DNode指针的指针。
  *   例：
  *        DLinkedList list; // 声明一个链表
  *        DNode *node;      // 声明一个结点指针
  */
typedef struct DNode {
    Element data;
    struct DNode* prev, * next;
} DNode, * DLinkedList;

/**
 * @brief 创建双链表
 * @param[in,out] list 链表
 * @retval true ：创建成功;
 *         false：创建失败。
 */
bool DLinkedList_Create(DLinkedList* list);

/**
 * @brief 释放双链表，创建过的双链表最后都需要释放。
 * @param[in] list 链表
 */
void DLinkedList_Free(DLinkedList* list);

/**
 * @brief 清空双链表，删除头结点以外的所有数据结点。
 * @param[in,out] list 链表
 * @retval true ：清空成功;
 *         false：清空失败。
 */
bool DLinkedList_Clear(DLinkedList* list);

/**
 * @brief 获取双链表头结点以外所有结点的个数。
 * @param[in] list 链表
 * @return 双链表头结点以外所有结点的个数
 */
int DLinkedList_GetLength(DLinkedList list);

/**
 * @brief 在指定结点（可指定头结点）后增加一个结点。
 * @param[in,out] list 链表。
 *                     实际这里没有对list进行操作，为了在使用函数时能够显目的表示你当前所使用的链表
 * @param[in,out] node 入参时为指定的结点，出参时为增加的新结点
 * @param[in] data 指定的结点后需要增加的结点数据
 * @retval true ：增加成功;
 *         false：增加失败。
 */
bool DLinkedList_AddAfter(DLinkedList* list, DNode* node, Element data);

/**
 * @brief 在指定数据结点（不可指定头结点）前增加一个结点。
 * @param[in,out] list 链表
 * @param[in] node 入参时为指定的结点，出参时为增加的新结点
 * @param[in] data 指定的结点前需要增加的结点数据
 * @retval true ：增加成功;
 *         false：增加失败。
 */
bool DLinkedList_AddBefore(DLinkedList* list, DNode* node, Element data);

/**
 * @brief 在第一个数据结点（即头结点后的第一个结点）前增加一个结点。
 * @param[in,out] list 链表
 * @param[in] data 需要增加的第一个数据结点的结点数据
 * @retval true ：增加成功;
 *         false：增加失败。
 */
bool DLinkedList_AddFirst(DLinkedList* list, Element data);

/**
 * @brief 在最后一个数据结点后增加一个结点。
 * @param[in,out] list 链表
 * @param[in] data 需要增加的最后一个数据结点的结点数据
 * @retval true ：增加成功;
 *         false：增加失败。
 */
bool DLinkedList_AddLast(DLinkedList* list, Element data);

/**
 * @brief 在指定位置（不可指定头结点的位置 index = 0）增加一个结点。
 * @param[in,out] list 链表
 * @param[in] data 需要增加的结点数据
 * @param[in] index 位置
 * @retval true ：增加成功;
 *         false：增加失败。
 */
bool DLinkedList_AddByIndex(DLinkedList* list, Element data, int index);

/**
 * @brief 删除指定数据结点。
 * @param[in,out] list 链表
 * @param[in,out] node 被删除的结点，删除后结点为NULL
 * @retval true ：删除成功;
 *         false：删除失败。
 */
bool DLinkedList_RemoveNode(DLinkedList* list, DNode* node);

/**
 * @brief 删除第一个数据结点（即头结点后的第一个结点）。
 * @param[in,out] list 链表
 * @retval true ：删除成功;
 *         false：删除失败。
 */
bool DLinkedList_RemoveFirst(DLinkedList* list);

/**
 * @brief 删除最后一个数据结点。
 * @param[in,out] list 链表
 * @retval true ：删除成功;
 *         false：删除失败。
 */
bool DLinkedList_RemoveLast(DLinkedList* list);

/**
 * @brief 删除指定位置（不可指定头结点的位置 index = 0）的数据结点。
 * @param[in,out] list 链表
 * @param[in] index 位置
 * @retval true ：删除成功;
 *         false：删除失败。
 */
bool DLinkedList_RemoveByIndex(DLinkedList* list, int index);

/**
 * @brief 获取指定节点（可指定头结点）的后一个结点。
 * @param[in] list 链表。
 *                 实际这里没有对list进行操作，为了在使用函数时能够显目的表示你当前所使用的链表
 * @param[in,out] node 入参和出参都为指定的结点
 * @return 指定节点的后一个结点
 * @note 也可以用 node = node->next;
 */
DNode* DLinkedList_GetAfter(DLinkedList list, DNode* node);

/**
 * @brief 获取指定节点（可指定头结点）的前一个结点。
 * @param[in] list 链表。
 *                 实际这里没有对list进行操作，为了在使用函数时能够显目的表示你当前所使用的链表
 * @param[in,out] node 入参和出参都为指定的结点
 * @return 指定节点的前一个结点
 * @note 也可以用 node = node->prev;
 */
DNode* DLinkedList_GetBefore(DLinkedList list, DNode* node);

/**
 * @brief 获取第一个数据结点（即头结点后的第一个结点）。
 * @param[in] list 链表
 * @return 第一个数据结点
 */
DNode* DLinkedList_GetFirst(DLinkedList list);

/**
 * @brief 获取最后一个数据结点。
 * @param[in] list 链表
 * @return 最后一个数据结点
 */
DNode* DLinkedList_GetLast(DLinkedList list);

/**
 * @brief 获取指定位置（不可指定头结点）的结点。
 * @param[in] list 链表
 * @param[in] index 位置
 * @return 指定位置的结点
 */
DNode* DLinkedList_GetByIndex(DLinkedList list, int index);

/**
 * @brief 查找第一个符合指定数据的结点。
 * @param[in] list 链表
 * @param[in] data 数据
 * @param[in] compare 自定义比较函数
 * @return 第一个符合指定数据的结点
 * @note 因为数据类型不确定，所以需要用到自定义比较函数，
 *         bool (*CompareElement)(Element, Element)，
 *         例如 bool CompareInts(Element a, Element b) { ... }
 */
DNode* DLinkedList_FindNode(DLinkedList list, Element data, CompareElement compare);

#endif
