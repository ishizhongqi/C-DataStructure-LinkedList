/**
 * @file singly_linkedlist.c
 * @author Shizhongqi (ishizhongqi@outlook.com)
 * @brief 单链表的创建、增加、删除、查找、释放。
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024 Shizhongqi
 *
 */

#include "singly_linkedlist.h"

bool SLinkedList_Create(SLinkedList* list) {
    *list = (SNode*)malloc(sizeof(SNode));
    if (*list == NULL) {
        return false;
    }

    (*list)->next = NULL;

    return true;
}

void SLinkedList_Free(SLinkedList* list) {
    if (SLinkedList_Clear(list)) {
        return;
    }

    free(*list);
    *list = NULL;
}

bool SLinkedList_Clear(SLinkedList* list) {
    if (*list == NULL) {
        return false;
    }

    SNode* node = *list;
    SNode* next;
    while (node->next != NULL) {
        next = node->next;
        node->next = next->next;
        free(next);
        next = NULL;
    }

    return true;
}

int SLinkedList_GetLength(SLinkedList list) {
    int length = 0;
    if (list == NULL) {
        return -1;
    }

    SNode* node = list->next;
    while (node != NULL) {
        node = node->next;
        length++;
    }
    return length;
}

bool SLinkedList_AddAfter(SLinkedList* list, SNode* node, Element data) {
    if (*list == NULL || node == NULL) {
        return false;
    }

    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    if (newNode == NULL) {
        return false;
    }

    newNode->data = data;
    newNode->next = node->next;
    node->next = newNode;

    node = node->next;

    return true;
}

bool SLinkedList_AddBefore(SLinkedList* list, SNode* node, Element data) {
    if (list == NULL || (*list)->next == NULL || node == NULL) {
        return false;
    }

    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    if (newNode == NULL) {
        return false;
    }

    newNode->next = node->next;
    node->next = newNode;
    newNode->data = node->data;
    node->data = data;

    return true;
}

bool SLinkedList_AddFirst(SLinkedList* list, Element data) {
    return SLinkedList_AddAfter(list, *list, data);
}

bool SLinkedList_AddLast(SLinkedList* list, Element data) {
    if (*list != NULL && (*list)->next == NULL) {
        return SLinkedList_AddFirst(list, data);
    }

    return SLinkedList_AddAfter(list, SLinkedList_GetLast(*list), data);
}

bool SLinkedList_AddByIndex(SLinkedList* list, Element data, int index) {
    if (*list == NULL || index < 1) {
        return false;
    }

    SNode* node = *list;
    int nodeIndex = 0;

    while (node != NULL && nodeIndex < index - 1) {
        node = node->next;
        nodeIndex++;
    }

    return SLinkedList_AddAfter(list, node, data);
}

bool SLinkedList_RemoveNode(SLinkedList* list, SNode* node) {
    if (*list == NULL || (*list)->next == NULL || node == NULL) {
        return false;
    }

    if (node->next == NULL) {
        SNode* prev;
        if (node == (*list)->next) {
            prev = *list;
        } else {
            prev = SLinkedList_GetByIndex(*list, SLinkedList_GetLength(*list) - 1);
        }
        prev->next = NULL;
        free(node);
        node = NULL;
    } else {
        SNode* next = node->next;
        node->data = node->next->data;
        node->next = next->next;
        node = node->next;
        free(node);
        node = NULL;
    }

    return true;
}

bool SLinkedList_RemoveFirst(SLinkedList* list) {
    if (*list == NULL || (*list)->next == NULL) {
        return false;
    }

    SNode* node = (*list)->next;
    return SLinkedList_RemoveNode(list, node);
}

bool SLinkedList_RemoveLast(SLinkedList* list) {
    if (*list == NULL || (*list)->next == NULL) {
        return false;
    }

    return SLinkedList_RemoveByIndex(list, SLinkedList_GetLength(*list));
}

bool SLinkedList_RemoveByIndex(SLinkedList* list, int index) {
    if (*list == NULL || index < 1) {
        return false;
    }

    SNode* node = *list;
    int nodeIndex = 0;

    while (node != NULL && nodeIndex < index - 1) {
        node = node->next;
        nodeIndex++;
    }

    if (node == NULL || node->next == NULL) {
        return false;
    }

    SNode* next = node->next;
    node->next = next->next;
    free(next);
    next = NULL;

    return true;
}

SNode* SLinkedList_GetAfter(SLinkedList list, SNode* node) {
    if (list == NULL || node == NULL || node->next == NULL) {
        return NULL;
    }

    return node->next;
}

SNode* SLinkedList_GetFirst(SLinkedList list) {
    if (list == NULL) {
        return NULL;
    }

    return list->next;
}

SNode* SLinkedList_GetLast(SLinkedList list) {
    if (list == NULL) {
        return NULL;
    }

    SNode* node = list->next;
    while (node != NULL && node->next != NULL) {
        node = node->next;
    }
    return node;
}

SNode* SLinkedList_GetByIndex(SLinkedList list, int index) {
    if (list == NULL || index < 1) {
        return NULL;
    }

    SNode* node = list;
    int nodeIndex = 0;

    while (node != NULL && nodeIndex < index) {
        node = node->next;
        nodeIndex++;
    }

    return node;
}

SNode* SLinkedList_FindNode(SLinkedList list, Element data, CompareElement compare) {
    if (list == NULL) {
        return NULL;
    }

    SNode* node = list->next;
    while (node != NULL && !compare(node->data, data)) {
        node = node->next;
    }
    return node;
}
