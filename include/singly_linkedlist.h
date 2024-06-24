/**
 * @file singly_linkedlist.h
 * @author Shizhongqi (ishizhongqi@outlook.com)
 * @brief 单链表的创建、增加、删除、查找、释放。
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024 Shizhongqi
 *
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "list_common_definition.h"

 /**
  * @brief 含头结点的单链表，创建后请勿对头结点进行操作。
  *        头结点的index为0，含数据的结点从1开始。
  *        处理链表时用SLinkedList，处理结点时用SNode。
  *        当然SLinkedList本质上是SNode的指针，同理SLinkedList指针是SNode指针的指针。
  *   例：
  *        SLinkedList list; // 声明一个链表
  *        SNode *node;      // 声明一个结点指针
  */
typedef struct SNode {
    Element data;
    struct SNode* next;
} SNode, * SLinkedList;

/**
 * @brief 创建单链表
 * @param[in,out] list 链表
 * @retval true ：创建成功;
 *         false：创建失败。
 */
bool SLinkedList_Create(SLinkedList* list);

/**
 * @brief 释放单链表，创建过的单链表最后都需要释放。
 * @param[in] list 链表
 */
void SLinkedList_Free(SLinkedList* list);

/**
 * @brief 清空单链表，删除头结点以外的所有数据结点。
 * @param[in,out] list 链表
 * @retval true ：清空成功;
 *         false：清空失败。
 */
bool SLinkedList_Clear(SLinkedList* list);

/**
 * @brief 获取单链表头结点以外所有结点的个数。
 * @param[in] list 链表
 * @return 单链表头结点以外所有结点的个数，如果没有头结点，则为-1。
 */
int SLinkedList_GetLength(SLinkedList list);

/**
 * @brief 在指定结点（可指定头结点）后增加一个结点。
 * @param[in,out] list 链表。
 *                     实际这里没有对list进行操作，为了在使用函数时能够显目的表示你当前所使用的链表
 * @param[in,out] node 入参时为指定的结点，出参时为增加的新结点
 * @param[in] data 指定的结点后需要增加的结点数据
 * @retval true ：增加成功;
 *         false：增加失败。
 */
bool SLinkedList_AddAfter(SLinkedList* list, SNode* node, Element data);

/**
 * @brief 在指定数据结点（不可指定头结点）前增加一个结点。
 * @param[in,out] list 链表
 * @param[in] node 入参时为指定的结点，出参时为增加的新结点
 * @param[in] data 指定的结点前需要增加的结点数据
 * @retval true ：增加成功;
 *         false：增加失败。
 * @note 前增结点本质为后增后对调数据，所以参数node返回的还是当前结点，但数据为新数据。
 */
bool SLinkedList_AddBefore(SLinkedList* list, SNode* node, Element data);

/**
 * @brief 在第一个数据结点（即头结点后的第一个结点）前增加一个结点。
 * @param[in,out] list 链表
 * @param[in] data 需要增加的第一个数据结点的结点数据
 * @retval true ：增加成功;
 *         false：增加失败。
 */
bool SLinkedList_AddFirst(SLinkedList* list, Element data);

/**
 * @brief 在最后一个数据结点后增加一个结点。
 * @param[in,out] list 链表
 * @param[in] data 需要增加的最后一个数据结点的结点数据
 * @retval true ：增加成功;
 *         false：增加失败。
 * @note 不建议通过此函数来批量增加结点，因为每次都需要遍历才能找到尾节点，
 *       如果需要批量增加结点，建议使用SLinkedList_AddAfter函数，
 *       或者使用SLinkedList_AddFirst函数往第一个数据结点增加结点。
 */
bool SLinkedList_AddLast(SLinkedList* list, Element data);

/**
 * @brief 在指定位置（不可指定头结点的位置 index = 0）增加一个结点。
 * @param[in,out] list 链表
 * @param[in] data 需要增加的结点数据
 * @param[in] index 位置
 * @retval true ：增加成功;
 *         false：增加失败。
 */
bool SLinkedList_AddByIndex(SLinkedList* list, Element data, int index);

/**
 * @brief 删除指定数据结点。
 * @param[in,out] list 链表
 * @param[in,out] node 被删除的结点，删除后结点为NULL
 * @retval true ：删除成功;
 *         false：删除失败。
 */
bool SLinkedList_RemoveNode(SLinkedList* list, SNode* node);

/**
 * @brief 删除第一个数据结点（即头结点后的第一个结点）。
 * @param[in,out] list 链表
 * @retval true ：删除成功;
 *         false：删除失败。
 */
bool SLinkedList_RemoveFirst(SLinkedList* list);

/**
 * @brief 删除最后一个数据结点。
 * @param[in,out] list 链表
 * @retval true ：删除成功;
 *         false：删除失败。
 */
bool SLinkedList_RemoveLast(SLinkedList* list);

/**
 * @brief 删除指定位置（不可指定头结点的位置 index = 0）的数据结点。
 * @param[in,out] list 链表
 * @param[in] index 位置
 * @retval true ：删除成功;
 *         false：删除失败。
 */
bool SLinkedList_RemoveByIndex(SLinkedList* list, int index);

/**
 * @brief 获取指定节点（可指定头结点）的后一个结点。
 * @param[in] list 链表。
 *                 实际这里没有对list进行操作，为了在使用函数时能够显目的表示你当前所使用的链表
 * @param[in,out] node 入参和出参都为指定的结点
 * @return 指定节点的后一个结点
 * @note 也可以用 node = node->next;
 */
SNode* SLinkedList_GetAfter(SLinkedList list, SNode* node);

/**
 * @brief 获取第一个数据结点（即头结点后的第一个结点）。
 * @param[in] list 链表
 * @return 第一个数据结点
 */
SNode* SLinkedList_GetFirst(SLinkedList list);

/**
 * @brief 获取最后一个数据结点。
 * @param[in] list 链表
 * @return 最后一个数据结点
 */
SNode* SLinkedList_GetLast(SLinkedList list);

/**
 * @brief 获取指定位置（不可指定头结点）的结点。
 * @param[in] list 链表
 * @param[in] index 位置
 * @return 指定位置的结点
 */
SNode* SLinkedList_GetByIndex(SLinkedList list, int index);

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
SNode* SLinkedList_FindNode(SLinkedList list, Element data, CompareElement compare);

#endif
