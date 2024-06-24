/**
 * @file doubly_linkedlist.c
 * @author Shizhongqi (ishizhongqi@outlook.com)
 * @brief 双链表的创建、增加、删除、查找、释放。
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024 Shizhongqi
 *
 */
#include "doubly_linkedlist.h"

bool DLinkedList_Create(DLinkedList* list) {
    *list = (DNode*)malloc(sizeof(DNode));
    if (*list == NULL) {
        return false;
    }

    (*list)->prev = NULL;
    (*list)->next = NULL;

    return true;
}

void DLinkedList_Free(DLinkedList* list) {
    DNode* node = *list;
    DLinkedList_Clear(list);
    free(node);
    node = NULL;
}

bool DLinkedList_Clear(DLinkedList* list) {
    if (*list == NULL) {
        return false;
    }

    DNode* node = *list;
    DNode* next;
    while (node->next != NULL) {
        next = node->next;
        node->next = next->next;
        if (next->next != NULL) {
            next->next->prev = node;
        }
        free(next);
        next = NULL;
    }

    return true;
}

int DLinkedList_GetLength(DLinkedList list) {
    int length = 0;
    DNode* node = list;
    while (node != NULL && node->next != NULL) {
        node = node->next;
        length++;
    }
    return length;
}

bool DLinkedList_AddAfter(DLinkedList* list, DNode* node, Element data) {
    if (*list == NULL || node == NULL) {
        return false;
    }

    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (newNode == NULL) {
        return false;
    }

    newNode->data = data;
    newNode->next = node->next;
    if (node->next != NULL) {
        node->next->prev = newNode;
    }
    newNode->prev = node;
    node->next = newNode;

    return true;
}

bool DLinkedList_AddBefore(DLinkedList* list, DNode* node, Element data) {
    if (*list == NULL || node == NULL || node->prev == NULL) {
        return false;
    }

    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (newNode == NULL) {
        return false;
    }

    newNode->data = data;
    newNode->prev = node->prev;
    node->prev->next = newNode;
    newNode->next = node;
    node->prev = newNode;

    return true;
}

bool DLinkedList_AddFirst(DLinkedList* list, Element data) {
    DNode* node = *list;
    return DLinkedList_AddAfter(list, node, data);
}

bool DLinkedList_AddLast(DLinkedList* list, Element data) {
    if ((*list) != NULL && (*list)->next == NULL) {
        return DLinkedList_AddFirst(list, data);
    }

    return DLinkedList_AddAfter(list, DLinkedList_GetLast(*list), data);
}

bool DLinkedList_AddByIndex(DLinkedList* list, Element data, int index) {
    if (*list == NULL || index < 1) {
        return false;
    }

    DNode* node = *list;
    int nodeIndex = 0;

    while (node != NULL && nodeIndex < index - 1) {
        node = node->next;
        nodeIndex++;
    }

    return DLinkedList_AddAfter(list, node, data);
}

bool DLinkedList_RemoveNode(DLinkedList* list, DNode* node) {
    if (*list == NULL || (*list)->next == NULL || node == NULL || node->prev == NULL) {
        return false;
    }

    node->prev->next = node->next;
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    free(node);
    node = NULL;

    return true;
}

bool DLinkedList_RemoveFirst(DLinkedList* list) {
    DNode* node = (*list)->next;
    return DLinkedList_RemoveNode(list, node);
}

bool DLinkedList_RemoveLast(DLinkedList* list) {
    DNode* node = DLinkedList_GetLast(*list);
    return DLinkedList_RemoveNode(list, node);
}

bool DLinkedList_RemoveByIndex(DLinkedList* list, int index) {
    if (*list == NULL || index < 1) {
        return false;
    }

    DNode* node = *list;
    int nodeIndex = 0;

    while (node != NULL && nodeIndex < index - 1) {
        node = node->next;
        nodeIndex++;
    }

    if (node == NULL || node->next == NULL) {
        return false;
    }

    DNode* next = node->next;
    node->next = next->next;
    if (next->next != NULL) {
        next->next->prev = node;
    }
    free(next);
    next = NULL;

    return true;
}

DNode* DLinkedList_GetAfter(DLinkedList list, DNode* node) {
    if (list == NULL || node == NULL || node->next == NULL) {
        return NULL;
    }

    return node->next;
}

DNode* DLinkedList_GetBefore(DLinkedList list, DNode* node) {
    if (list == NULL || node == NULL || node->prev == NULL) {
        return NULL;
    }

    return node->prev;
}

DNode* DLinkedList_GetFirst(DLinkedList list) {
    if (list == NULL) {
        return NULL;
    }

    return list->next;
}

DNode* DLinkedList_GetLast(DLinkedList list) {
    if (list == NULL) {
        return NULL;
    }

    DNode* node = list->next;
    while (node != NULL && node->next != NULL) {
        node = node->next;
    }
    return node;
}

DNode* DLinkedList_GetByIndex(DLinkedList list, int index) {
    if (list == NULL || index < 0) {
        return NULL;
    }

    DNode* node = list;
    int nodeIndex = 0;

    while (node != NULL && nodeIndex < index) {
        node = node->next;
        nodeIndex++;
    }

    return node;
}

DNode* DLinkedList_FindNode(DLinkedList list, Element data, CompareElement compare) {
    if (list == NULL) {
        return NULL;
    }

    DNode* node = list->next;
    while (node != NULL && !compare(node->data, data)) {
        node = node->next;
    }
    return node;
}
