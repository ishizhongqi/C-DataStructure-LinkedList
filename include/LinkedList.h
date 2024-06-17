#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/**
 * The following are the types of linked list:
 *   · Singly Linked list
 *   · Doubly Linked list
 *   · Circular Linked list
 *   · Doubly Circular Linked list
 */

/* Define a generic type for data in linked list */
typedef void *GenericType;

/* Singly Linked list */
typedef struct SNode
{
    GenericType data;
    struct SNode *next;
} SNode, *SLinkedList;

/* Doubly Linked list */
typedef struct DNode
{
    GenericType data;
    struct DNode *prev, *next;
} DNode, *DLinkedList;

/* Circular Linked list */
typedef struct CNode
{
    GenericType data;
    struct CNode *next;
} CNode, *CLinkedList;

/* Doubly Circular Linked list */
typedef struct DCNode
{
    GenericType data;
    struct DNode *prev, *next;
} DCNode, *DCLinkedList;

#endif
