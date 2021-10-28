#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, *LinkList;

//��ʼ��������(����ͷ�ڵ�)
void InitLinkList(LinkList* head);

//�������ĩβ����һ��Ԫ�أ��ɹ�����true�����򷵻�false
bool add(LinkList linkList, int elem);

//��������
bool destroyLinkList(LinkList L);

//�������
bool clearLinkList(LinkList L);

//�ж������Ƿ�Ϊ��
bool listIsEmpty(LinkList L);

//��������ĳ���
int listLength(LinkList L);

//������ĵ�i��λ�ò���Ԫ��elem
bool linkListInsert(LinkList L, int i, int elem);

//��ȡ��i��Ԫ��(1<= i <= list.length)������i���ڵ��ֵ����
int getLinkListElem(LinkList L, int i);

//����ĳһ��ֵ���±�
int locateLinkListElem(LinkList L, int value);

//���� ��ǰ����ֵΪvalue �ĵ�һ���ڵ��ǰ��
LinkList priorElem(LinkList L, int cur_value);

//���� ��ǰ����ֵΪvalue �ĵ�һ���ڵ�ĺ��
LinkList nextElem(LinkList L, int cur_value);

//ɾ�������е�i���ڵ㣬�����ظýڵ��ֵ
int deleteLinkListElem(LinkList L, int i);

//����������������ӡ
void travelLinkList(LinkList L);
