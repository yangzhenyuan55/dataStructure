#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include "BinaryTree.h"

//ע����ͷ�ļ���ʱ���Ƿ���ص���������ض������ 



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
		printf("˳���Ϊ��\n");
	} else printf("˳���Ϊ��\n");
	Push(&stack, 1);
	Push(&stack, 2);
	if (sqStackIsEmpty(stack)) {
		printf("˳���Ϊ��\n");
	}
	else printf("˳���Ϊ��\n");
	int e;
	getTop(&stack, &e);
	printf("%d\n", e);*/

	/*
	SqStack stack;
	initSqStack(&stack);
	//����ת���㷨
	int N = 0; //�Ǹ�ʮ������
	int d = 0; //��������ת����d����
	printf("������һ���Ǹ�ʮ������:>");
	scanf("%d", &N);
	printf("������ת������:>");
	scanf("%d", &d);
	while (N) {
		Push(&stack, N%d);
		N /= d;
	}

	printf("ת�ɳ�%d����Ϊ:>", d);
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
		printf("�Ϸ�\n");
	} else printf("���Ϸ�\n");*/

	/*char expr[50];
	printf("������һ��������ʽ ��#��Ϊ��β\n");
	printf("���ʽ:>");
	gets(expr);
	double res = evaluateExpression(&expr);
	printf("������Ϊ:>");
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
	
	printf("\n�ݹ��������: ");
	RcsPreOrderTraverse(tree, PrintElem);
	printf("\n�ݹ��������: ");
	RcsInOrderTraverse(tree, PrintElem);
	printf("\n�ݹ��������: ");
	RcsPostOrderTraverse(tree, PrintElem);
	return 0;
}