#define _CRT_SECURE_NO_WARNINGS 1


#include "SqList.h"




////����ֱ���滻�������Ǵ��Σ�������д���ʱ������Ҫʡ�Ա�Ҫ������
//#define SQUARE(X) (X)*(X)
//
//// #X ��ʾ "X" ��c��printf()�������ַ������Զ�ƴ��
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
//	strcpy(books[0].title, "��������");
//	strcpy(books[0].author,"�޹���");
//	strcpy(books[1].title, "��¥��");
//	strcpy(books[1].author, "��ѩ��");
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

// Ϊ˳�������
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
	//����һ���յ�˳�����̬����洢�ռ�
	sqList->elem = (int *)malloc(sizeof(int)*LIST_INIT_SIZE);
	//����ʧ�ܣ�ֱ���˳�
	if (!sqList->elem) exit(0);
	sqList->length = 0;
	sqList->listsize = LIST_INIT_SIZE; //˳����ʼ�洢����
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
	if (i < 0 || i > sqList->length) return false; //i��ֵ���Ϸ�
	if (sqList->length >= sqList->listsize) { //��ǰ�洢�ռ�������˳�������
		IncreaCapacity(sqList);
	}
	int *insertLoc = &(sqList->elem[i]); //�����λ��
	int * flag; //�ƶ��ı�ʶ�������һ��Ԫ�ؿ�ʼ
	for (flag = &(sqList->elem[sqList->length - 1]); flag >= insertLoc; --flag) {
		*(flag + 1) = *flag;
	}
	*insertLoc = e;
	++sqList->length;
	return true;
}


int DeleteElem(SqList *sqList, int i) {
	if (i < 0 || i > sqList->length) return -1;
	int temp = sqList->elem[i]; //�ݴ�Ҫɾ����Ԫ�ص�ֵ
	int *deleteElem; //Ҫɾ����Ԫ��
	for (deleteElem = &(sqList->elem[i]); deleteElem <= &(sqList->elem[sqList->length - 1]); ++deleteElem) {
		*deleteElem = *(deleteElem + 1);
	}
	sqList->length--;
	return temp;
}

/*
 *���˳���ֻ��Ҫ��˳���ĳ�����Ϊ0����
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

/*���ٴ�˳���*/
void DestroyList(SqList *sqList) {
	free(sqList->elem);
}


