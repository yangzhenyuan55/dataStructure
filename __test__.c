#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "SqList.h"
#include "LinkList.h"
#include "Stack.h"




int main(){
	/*SqList sqList;
	InitList(&sqList);
	int i;
	for (i = 1; i < 7; i++) {
		Put(&sqList, i);
	}
	DeleteElem(&sqList, 1);
	for (i = 0; i < 6; i++) {
		printf("%d\n", sqList.elem[i]);
	}*/

	/*LinkList list;
	InitLinkList(&list);
	
	add(list, 1);
	add(list, 2);
	add(list, 20);
	add(list, 4);
	add(list, 5);
	travelLinkList(list);*/
	/*
	SqStack stack;
	initSqStack(&stack);
	if (sqStackIsEmpty(stack)) {
		printf("顺序表为空\n");
	} else printf("顺序表不为空\n");
	Push(&stack, 1);
	Push(&stack, 2);
	if (sqStackIsEmpty(stack)) {
		printf("顺序表为空\n");
	}
	else printf("顺序表不为空\n");
	int e;
	getTop(&stack, &e);
	printf("%d\n", e);*/

	/*
	SqStack stack;
	initSqStack(&stack);
	//数制转换算法
	int N = 0; //非负十进制数
	int d = 0; //将此数字转换成d进制
	printf("请输入一个非负十进制数:>");
	scanf("%d", &N);
	printf("请输入转换进制:>");
	scanf("%d", &d);
	while (N) {
		Push(&stack, N%d);
		N /= d;
	}

	printf("转成成%d进制为:>", d);
	while (!sqStackIsEmpty(stack)) {
		int e;
		Pop(&stack, &e);
		printf("%d", e);
	}
	printf("\n");
	*/
	char brackets[] = "{()()[]{}{}[]}";
	int len = strlen(brackets);
	if (bracketIsMatch(brackets, len)) {
		printf("合法\n");
	} else printf("不合法\n");
	system("pause");
	return 0;
}
