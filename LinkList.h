#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, *LinkList;

//初始化单链表(带有头节点)
void InitLinkList(LinkList* head);

//往链表的末尾加上一个元素，成功返回true，否则返回false
bool add(LinkList linkList, int elem);

//销毁链表
bool destroyLinkList(LinkList L);

//清空链表
bool clearLinkList(LinkList L);

//判断链表是否为空
bool listIsEmpty(LinkList L);

//返回链表的长度
int listLength(LinkList L);

//在链表的第i个位置插入元素elem
bool linkListInsert(LinkList L, int i, int elem);

//获取第i个元素(1<= i <= list.length)，将第i个节点的值返回
int getLinkListElem(LinkList L, int i);

//返回某一个值的下标
int locateLinkListElem(LinkList L, int value);

//返回 当前链表值为value 的第一个节点的前驱
LinkList priorElem(LinkList L, int cur_value);

//返回 当前链表值为value 的第一个节点的后继
LinkList nextElem(LinkList L, int cur_value);

//删除链表中第i个节点，并返回该节点的值
int deleteLinkListElem(LinkList L, int i);

//遍历整个链表，并打印
void travelLinkList(LinkList L);
