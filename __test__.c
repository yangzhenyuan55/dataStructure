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
	
	//LinkList L;
	//InitLinkList(&L); // 初始化链表
	//add(L, 1); // 插入元素1
	//add(L, 2); // 插入元素2
	//add(L, 3); // 插入元素3
	//printf("原链表:>");
	//travelLinkList(L); //遍历链表

	//deleteLinkListElem(L, 1); // 删除第i个元素
	//printf("删除第1个元素后的链表:>");
	//travelLinkList(L);

	//linkListInsert(L, 1, 2); //在第i个位置插入元素2
	//printf("在第1个位置插入2后的链表:>");
	//travelLinkList(L);

	//modifyLinkListElem(L, 1, 1); // 将链表第1个元素的值改为1
	//printf("将第1个元素的值");
	//travelLinkList(L);


	//SqStack stack;
	//initSqStack(&stack);
	//Push(&stack, 'A');
	//Push(&stack, 'B');
	//Push(&stack, 'C');
	//Push(&stack, 'D');
	//Push(&stack, 'E');
	//Push(&stack, 'F');
	//Push(&stack, 'G');
	//printf("输入:> ");
	//travelSqStack(stack); // 遍历栈
 //	char temp;

	//printf("逆序:> ");
	//for (int i = 0; i < 7; i++) {
	//	Pop(&stack, &temp);
	//	printf("%c ", temp);
	//}
	//printf("\n");

	/*char expr[50];
	printf("请输入一个运算表达式 以#作为结尾\n");
	printf("表达式:>");
	gets(expr);
	double res = evaluateExpression(&expr);
	printf("运算结果为:>");
	printf("%.0f\n", res);*/

	BiTree T = NULL;
	InsertNode(&T, '3');
	InsertNode(&T, '1');
	InsertNode(&T, '2');
	InsertNode(&T, '4');

	printf("先序遍历:> ");
	RcsPreOrderTraverse(T, PrintElem);
	printf("\n");

	printf("中序遍历:> ");
	RcsInOrderTraverse(T, PrintElem);
	printf("\n");
	
	printf("后序遍历:> ");
	RcsPostOrderTraverse(T, PrintElem);
	printf("\n");

	DeleteNode(T, '1');
	printf("删除 1 后:> \n");

	printf("先序遍历:> ");
	RcsPreOrderTraverse(T, PrintElem);
	printf("\n");

	printf("中序遍历:> ");
	RcsInOrderTraverse(T, PrintElem);
	printf("\n");

	printf("后序遍历:> ");
	RcsPostOrderTraverse(T, PrintElem);
	printf("\n");


	printf("将2修改成6:>\n");
	ModifyNode(T, '2', '6');


	printf("先序遍历:> ");
	RcsPreOrderTraverse(T, PrintElem);
	printf("\n");

	printf("中序遍历:> ");
	RcsInOrderTraverse(T, PrintElem);
	printf("\n");

	printf("后序遍历:> ");
	RcsPostOrderTraverse(T, PrintElem);
	printf("\n");

	DestoryBiTree(T);

	system("pause");
	return 0;
}