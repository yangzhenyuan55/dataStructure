#define _CRT_SECURE_NO_WARNINGS 1


#include "SqList.h"




////宏是直接替换，而不是传参，所以在写宏的时候尽量不要省略必要的括号
//#define SQUARE(X) (X)*(X)
//
//// #X 表示 "X" 在c中printf()函数里字符串会自动拼接
//#define PRINT(X) printf("the value of " #X " is %d\n", X)
//
//#define CAT(X, Y) X##Y
//
//#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
//
//
//int Min(int x, int y) {
//	return x < y ? x : y;
//}
//
//int main() {
//	int a = 1;
//	int b = 1;
//	printf("%d\n", MAX(a, b));
//
//	printf("%d\n", Min(1, 2));
//	
//
//	system("pause");
//	return 0;
//}


//struct book
//{
//	char title[100];
//	char author[100];
//};
//

//
//int main(void) {
//
//
//	struct book books[10];
//	strcpy(books[0].title, "三国演义");
//	strcpy(books[0].author,"罗贯中");
//	strcpy(books[1].title, "红楼梦");
//	strcpy(books[1].author, "曹雪芹");
//	int j;
//	for (j = 0; j < 2; j++)
//	{
//		printf("%s:%s\n", books[j].title, books[j].author);
//	}
//	system("pause");
//	return 0;
//}




/*
 *
 *
 **
*/

// 为顺序表扩容
void IncreaCapacity(SqList *sqList) {
	//int temp = sqList->elem[sqList->length - 1];
	int *newbase = (int *)realloc(sqList->elem, sizeof(int)*(sqList->listsize + LISTINCREMENT));
	if (!newbase) exit(0);
	sqList->elem = newbase;
	sqList->listsize += LISTINCREMENT;
	//sqList->elem[sqList->length - 1] = temp;
	return;
}




void InitList(SqList *sqList) {
	//构造一个空的顺序表，动态申请存储空间
	sqList->elem = (int *)malloc(sizeof(int)*LIST_INIT_SIZE);
	//申请失败，直接退出
	if (!sqList->elem) exit(0);
	sqList->length = 0;
	sqList->listsize = LIST_INIT_SIZE; //顺序表初始存储容量
}


void Put(SqList *sqList, int elem) {
	if (sqList->length >= sqList->listsize) {
		IncreaCapacity(sqList);
	}
	sqList->elem[sqList->length] = elem;
	sqList->length++;
}

int GetElem(SqList *sqList, int i) {
	if (i < 0 || i > sqList->length) return -1;
	return sqList->elem[i];
}


bool InsertElem(SqList *sqList, int i, int e){
	if (i < 0 || i > sqList->length) return false; //i的值不合法
	if (sqList->length >= sqList->listsize) { //当前存储空间已满，顺序表扩容
		IncreaCapacity(sqList);
	}
	int *insertLoc = &(sqList->elem[i]); //插入的位置
	int * flag; //移动的标识，从最后一个元素开始
	for (flag = &(sqList->elem[sqList->length - 1]); flag >= insertLoc; --flag) {
		*(flag + 1) = *flag;
	}
	*insertLoc = e;
	++sqList->length;
	return true;
}


int DeleteElem(SqList *sqList, int i) {
	if (i < 0 || i > sqList->length) return -1;
	int temp = sqList->elem[i]; //暂存要删除的元素的值
	int *deleteElem; //要删除的元素
	for (deleteElem = &(sqList->elem[i]); deleteElem <= &(sqList->elem[sqList->length - 1]); ++deleteElem) {
		*deleteElem = *(deleteElem + 1);
	}
	sqList->length--;
	return temp;
}

/*
 *清空顺序表只需要把顺序表的长度设为0即可
 *
*/
void ClearList(SqList *sqList) {
	sqList->length = 0;
}

bool isEmpty(SqList *sqList){
	if (!sqList) return false;
	if (sqList->length == 0) return true;
	else return false;
}


int LocateElem(SqList* sqList, int e) {
	int i;
	for ( i = 0; i < sqList->length; i++) {
		if (sqList->elem[i] == e) return i;
	}
	return -1;
}

/*销毁此顺序表*/
void DestroyList(SqList *sqList) {
	free(sqList->elem);
}


