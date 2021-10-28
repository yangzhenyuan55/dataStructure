#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

//栈的初始容量
#define STACK_INIT_CAP 20
#define STACKINCREACAP 10

//操作数字的栈
typedef struct {
	double* base; //栈堆
	double* top; //栈顶
	int cap; //栈的容量
}NumStack;

//操作字符的栈
typedef struct {
	char* base;
	char* top;
	int cap;
}CharStack;


//======================================
bool initNumStack(NumStack* S);

//压栈
bool PushNum(NumStack* S, double e);

double PopNum(NumStack* S);

//用*p返回栈顶元素，但是不弹栈
double getTopNum(NumStack* S);

bool NumStackIsEmpty(NumStack S);

//=======================================

bool initCharStack(CharStack* S);


//压栈
bool PushChar(CharStack* S, int e);

char PopChar(CharStack* S);

//用*p返回栈顶元素，但是不弹栈
char getTopChar(CharStack* S);

bool CharStackIsEmpty(CharStack S);
//========================================

//判断一组括号是否合法
bool bracketIsMatch(SElemType* b, int bracket_len);

//计算算术表达式
//算术表达式字符串exprs
double evaluateExpression(char* expr);