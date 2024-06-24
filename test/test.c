#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "singly_linkedlist.h"

typedef struct Employee {
    int id;
    char name[50];
    double salary;
} Employee;

bool compareEmployee(Element a, Element b) {
    Employee* emp1 = (Employee*)a;
    Employee* emp2 = (Employee*)b;
    if (emp1->id == emp2->id && strcmp(emp1->name, emp2->name) == 0 && emp1->salary == emp2->salary) {
        return true;
    } else {
        return false;
    }
}

void test_SLinkedList_Create() {
    SLinkedList list;
    bool result = SLinkedList_Create(&list);
    assert(result == true);
    assert(list != NULL);
    SLinkedList_Free(&list);
}

void test_SLinkedList_AddFirst() {
    SLinkedList list;
    SLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    bool result = SLinkedList_AddFirst(&list, &emp);
    assert(result == true);
    assert(SLinkedList_GetLength(list) == 1);
    assert(SLinkedList_GetFirst(list)->data == &emp);
    SLinkedList_Free(&list);
}

void test_SLinkedList_AddLast() {
    SLinkedList list;
    SLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    bool result = SLinkedList_AddLast(&list, &emp);
    assert(result == true);
    assert(SLinkedList_GetLength(list) == 1);
    assert(SLinkedList_GetLast(list)->data == &emp);
    SLinkedList_Free(&list);
}

void test_SLinkedList_AddByIndex() {
    SLinkedList list;
    SLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    SLinkedList_AddFirst(&list, &emp);
    Employee emp2 = { 2, "Bob", 20000.0 };
    bool result = SLinkedList_AddByIndex(&list, &emp2, 1);
    assert(result == true);
    assert(SLinkedList_GetLength(list) == 2);
    assert(SLinkedList_GetByIndex(list, 1)->data == &emp2);
    SLinkedList_Free(&list);
}

void test_SLinkedList_RemoveFirst() {
    SLinkedList list;
    SLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    SLinkedList_AddFirst(&list, &emp);
    bool result = SLinkedList_RemoveFirst(&list);
    assert(result == true);
    assert(SLinkedList_GetLength(list) == 0);
    SLinkedList_Free(&list);
}

void test_SLinkedList_RemoveLast() {
    SLinkedList list;
    SLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    SLinkedList_AddFirst(&list, &emp);
    bool result = SLinkedList_RemoveLast(&list);
    assert(result == true);
    assert(SLinkedList_GetLength(list) == 0);
    SLinkedList_Free(&list);
}

void test_SLinkedList_RemoveByIndex() {
    SLinkedList list;
    SLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    SLinkedList_AddFirst(&list, &emp);
    bool result = SLinkedList_RemoveByIndex(&list, 1);
    assert(result == true);
    assert(SLinkedList_GetLength(list) == 0);
    SLinkedList_Free(&list);
}

void test_SLinkedList_GetLength() {
    SLinkedList list;
    SLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    SLinkedList_AddFirst(&list, &emp);
    int length = SLinkedList_GetLength(list);
    assert(length == 1);
    SLinkedList_Free(&list);
}

void test_SLinkedList_FindNode() {
    SLinkedList list;
    SLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    SLinkedList_AddFirst(&list, &emp);
    SNode* node = SLinkedList_FindNode(list, &emp, compareEmployee);
    assert(node != NULL);
    assert(node->data == &emp);
    SLinkedList_Free(&list);
}


#include "doubly_linkedlist.h"

void test_DLinkedList_Create() {
    DLinkedList list;
    bool result = DLinkedList_Create(&list);
    assert(result == true);
    assert(list != NULL);
    assert(list->prev == NULL);
    assert(list->next == NULL);
    DLinkedList_Free(&list);
}

void test_DLinkedList_AddFirst() {
    DLinkedList list;
    DLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    bool result = DLinkedList_AddFirst(&list, &emp);
    assert(result == true);
    assert(DLinkedList_GetFirst(list)->data == &emp);
    DLinkedList_Free(&list);
}

void test_DLinkedList_AddLast() {
    DLinkedList list;
    DLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    bool result = DLinkedList_AddLast(&list, &emp);
    assert(result == true);
    assert(DLinkedList_GetLast(list)->data == &emp);
    DLinkedList_Free(&list);
}

void test_DLinkedList_AddByIndex() {
    DLinkedList list;
    DLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    DLinkedList_AddFirst(&list, &emp);
    Employee emp2 = { 2,"Bob", 20000.0 };
    bool result = DLinkedList_AddByIndex(&list, &emp2, 1);
    assert(result == true);
    assert(DLinkedList_GetByIndex(list, 1)->data == &emp2);
    DLinkedList_Free(&list);
}

void test_DLinkedList_RemoveFirst() {
    DLinkedList list;
    DLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    DLinkedList_AddFirst(&list, &emp);
    bool result = DLinkedList_RemoveFirst(&list);
    assert(result == true);
    assert(DLinkedList_GetFirst(list) == NULL);
    DLinkedList_Free(&list);
}

void test_DLinkedList_RemoveLast() {
    DLinkedList list;
    DLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    DLinkedList_AddFirst(&list, &emp);
    bool result = DLinkedList_RemoveLast(&list);
    assert(result == true);
    assert(DLinkedList_GetLast(list) == NULL);
    DLinkedList_Free(&list);
}

void test_DLinkedList_RemoveByIndex() {
    DLinkedList list;
    DLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    DLinkedList_AddFirst(&list, &emp);
    bool result = DLinkedList_RemoveByIndex(&list, 1);
    assert(result == true);
    assert(DLinkedList_GetFirst(list) == NULL);
    DLinkedList_Free(&list);
}

void test_DLinkedList_GetLength() {
    DLinkedList list;
    DLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    DLinkedList_AddFirst(&list, &emp);
    int length = DLinkedList_GetLength(list);
    assert(length == 1);
    DLinkedList_Free(&list);
}

void test_DLinkedList_FindNode() {
    DLinkedList list;
    DLinkedList_Create(&list);
    Employee emp = { 1, "Alice", 10000.0 };
    DLinkedList_AddFirst(&list, &emp);
    DNode* node = DLinkedList_FindNode(list, &emp, compareEmployee);
    assert(node != NULL);
    assert(node->data == &emp);
    DLinkedList_Free(&list);
}


int main() {
    test_SLinkedList_Create();
    test_SLinkedList_AddFirst();
    test_SLinkedList_AddLast();
    test_SLinkedList_AddByIndex();
    test_SLinkedList_RemoveFirst();
    test_SLinkedList_RemoveLast();
    test_SLinkedList_RemoveByIndex();
    test_SLinkedList_GetLength();
    test_SLinkedList_FindNode();

    test_DLinkedList_Create();
    test_DLinkedList_AddFirst();
    test_DLinkedList_AddLast();
    test_DLinkedList_AddByIndex();
    test_DLinkedList_RemoveFirst();
    test_DLinkedList_RemoveLast();
    test_DLinkedList_RemoveByIndex();
    test_DLinkedList_GetLength();
    test_DLinkedList_FindNode();

    printf("All tests passed!\n");
    return 0;
}
