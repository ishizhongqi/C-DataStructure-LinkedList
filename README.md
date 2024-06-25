# Generic LinkedList In C (C语言通用类型链表)

## 前言
- 目前实现了单链表和双链表，后续会考虑循环链表和循环双链表。
- 单链表与双链表都是在包含头结点（哨兵结点）的基础上实现的， 头结点一般不存储任何数据，头结点的`next`指针指向链表的第一个节点（数据结点），这样做方便处理链表的头部操作，比如插入与删除等。
- 目前代码没有经过严格的测试，只是通过AI写了一个测试代码，可能存在一些bug，使用时请注意，后续我也会继续完善代码。
- 部分代码参考了[【王道计算机考研 数据结构】](https://www.bilibili.com/video/BV1b7411N798/?share_source=copy_web&vd_source=cabb03d513e5654744c0a35f6fdb5a0d)，并做了一些修改和优化，适配C语言。如果存在不懂的地方，可以去看视频，视频讲解的很详细。

## 示例
下面是一个示例代码，展示了如何使用单链表。
```c
#include "linkedlist.h" // 如果只会用到特地的链表，可以只用包含 singly_linkedlist.h

// 这里定义一个Employee结构体
typedef struct Employee {
    int id;
    char name[50];
    double salary;
} Employee;

int main() {
    SLinkedList list; // 声明链表
    bool ret = SLinkedList_Create(&list); // 创建链表
    if (!ret) {
        printf("创建链表失败\n");
        return -1;
    }

    // 往第一个结点插入数据
    Employee emp = {1, "Alice", 10000.0};
    ret = SLinkedList_AddFirst(&list, &emp);
    if (!ret) {
        printf("插入数据失败\n");
        return -1;
    }

    // 获取刚刚插入数据的结点
    SNode *node = SLinkedList_GetFirst(list); // 也可以直接使用 list->next
    if (node == NULL) {
        printf("获取结点失败\n");
        return -1;
    }

    // 遍历插入数据
    for (int i = 2; i <= 10; i++) {
        Employee emp = {i, "Employee", 20000.0 + i};
        ret = SLinkedList_AddAfter(&list, node, &emp);
        if (!ret) {
            printf("插入数据失败\n");
            return -1;
        }
    }

    // 删除最后一个结点
    ret = SLinkedList_RemoveLast(&list);
    if (!ret) {
        printf("删除数据失败\n");
        return -1;
    }

    // 销毁链表
    SLinkedList_Free(&list);

    return 0;
}
