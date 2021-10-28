#include "Stack.h"
#include <stdio.h>

//初始化顺序栈,成功则返回true,失败返回false
bool initSqStack(SqStack* S) {
	S->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int*));
	if (!S->base) {
		return false;
	}//存储分配失败
	S->top = S->base;
	S->stackSize = STACK_INIT_SIZE;
	return true;
}

bool increaseCapacity(SqStack* S) {
	S->base = (int*)realloc(S->base, (S->stackSize + STACKINCREMENT)*sizeof(int*));
	if (!S->base) exit(0);
	S->top = S->base + S->stackSize;
	S->stackSize += STACKINCREMENT;
	return true;
}


//销毁顺序栈，释放占用的内存空间，成功返回true，失败则返回false
bool destorySqStack(SqStack* S) {
	//顺序栈未初始化,压栈失败
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("顺序栈未初始化");
		return false;
	}
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stackSize = 0;
	return false;
}

//压栈
bool Push(SqStack* S, SElemType e) {
	//顺序栈未初始化,压栈失败
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("顺序栈未初始化");
		return false;
	}
	//栈满，扩容
	if (S->top - S->base >= S->stackSize) {
		increaseCapacity(S);
	}
	*S->top = e; //将元素压入栈中，并将top指向元素的下一个位置
	S->top++;
	return true;
}

//弹栈，返回该栈顶元素
//
bool Pop(SqStack* S, SElemType* p) {
	//栈未初始化
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("顺序栈未初始化");
		return false;
	}
	//栈为空，弹栈失败
	if (S->base == S->top) {
		return false;
	}
	S->top--;
	*p = *S->top;
	return true;
}

//返回栈顶元素
bool getTop(SqStack* S, SElemType* p) {
	//栈未初始化
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("顺序栈未初始化");
		return false;
	}
	//栈为空，弹栈失败
	if (S->base == S->top) {
		return false;
	}

	*p = *(S->top - 1);
	return true;
}

//判断顺序表是否为空（空则返回true，否则返回false）
bool sqStackIsEmpty(SqStack S) {
	if (S.base == S.top) {
		return true;
	}
	else {
		return false;
	}
}

bool clearSqStack(SqStack* S)
{
	//栈未初始化
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("顺序栈未初始化");
		return false;
	}
	S->base = S->top;
	return true;
}

//顺序栈的应用实例
//判断一组括号是否合法
//SElemTyle类型只能是char
bool bracketIsMatch(SElemType* b, int bracket_len) {
	//括号匹配的检查算法
	SqStack stack;
	initSqStack(&stack);
	int i = 0;
	//第一个是右括号直接不合法
	if (b[0] == ')' || b[0] == ']' || b[0] == '}') return false;
	while (i < bracket_len) {
		//扫描到左括号
		if (b[i] == '(' || b[i] == '[' || b[i] == '{') {
			Push(&stack, b[i]);
		}
		else { //扫描到右括号
			if (sqStackIsEmpty(stack)) return false; //栈为空则这些括号不合法
			SElemType topElem;
			Pop(&stack, &topElem);
			if ((b[i] == ')' && topElem == '(') || (b[i] == '}' && topElem == '{') || (b[i] == ']' && topElem == '[')) {
				i++;
				continue;
			}
			else return false;
		}
		i++;
	}
	return sqStackIsEmpty(stack);
}
