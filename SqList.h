#define _CRT_SECURE_NO_WARNINGS 1
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10


#include <stdlib.h>
#include <stdbool.h>


typedef struct SqList {
	int *elem; //动态数组
	int length; //当前顺序表的长度
	int listsize; //当前顺序表分配的存储容量
}SqList;

//初始化顺序表
void InitList(SqList* sqList);

/*
* 将元素插入到顺序表中
* 插入成功返回true，否使返回false
* 在元素的第i个位置插入新的元素e
*/
void Put(SqList* sqList, int elem);

int GetElem(SqList* sqList, int i);

bool InsertElem(SqList* sqList, int i, int e);

int DeleteElem(SqList* sqList, int i);

void ClearList(SqList* sqList);

bool isEmpty(SqList* sqList);

int LocateElem(SqList* sqList, int e);

void DestroyList(SqList* sqList);

