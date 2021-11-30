#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include "BinaryTree.h"

//注意引头文件的时候是否会重叠，会出现重定义错误 



/*int main() {
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

	
	/*char brackets[] = "{()()[]{}{}[]}";
	int len = strlen(brackets);
	if (bracketIsMatch(brackets, len)) {
		printf("合法\n");
	} else printf("不合法\n");*/

	/*char expr[50];
	printf("请输入一个运算表达式 以#作为结尾\n");
	printf("表达式:>");
	gets(expr);
	double res = evaluateExpression(&expr);
	printf("运算结果为:>");
	printf("%f\n",res);*/

	/*char info[100][3];
	long long  num;
	int count = 0;

	

	fflush(stdout);
	while (scanf("%lld", &num) != EOF) {


		if (num % 11 == 0) {
			strcpy(info[count++], "yes");
		}
		else {
			strcpy(info[count++], "no");
		}
		
	}
	printf("%s\n", info[0]);
	for (int i = 0; i < count; i++) {
		printf("%s\n", info[i]);
	}
	

	system("pause");
	return 0;
}*/


int main() {
	BiTree tree =  NULL;
	CreateBiTree(&tree);
	
	printf("\n递归先序遍历: ");
	RcsPreOrderTraverse(tree, PrintElem);
	printf("\n递归中序遍历: ");
	RcsInOrderTraverse(tree, PrintElem);
	printf("\n递归后续遍历: ");
	RcsPostOrderTraverse(tree, PrintElem);
	return 0;
}