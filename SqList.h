#define _CRT_SECURE_NO_WARNINGS 1
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10


#include <stdlib.h>
#include <stdbool.h>


typedef struct SqList {
	int *elem; //��̬����
	int length; //��ǰ˳���ĳ���
	int listsize; //��ǰ˳������Ĵ洢����
}SqList;

//��ʼ��˳���
void InitList(SqList* sqList);

/*
* ��Ԫ�ز��뵽˳�����
* ����ɹ�����true����ʹ����false
* ��Ԫ�صĵ�i��λ�ò����µ�Ԫ��e
*/
void Put(SqList* sqList, int elem);

int GetElem(SqList* sqList, int i);

bool InsertElem(SqList* sqList, int i, int e);

int DeleteElem(SqList* sqList, int i);

void ClearList(SqList* sqList);

bool isEmpty(SqList* sqList);

int LocateElem(SqList* sqList, int e);

void DestroyList(SqList* sqList);

