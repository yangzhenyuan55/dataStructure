#include <stdlib.h>
#include <stdbool.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
typedef char SElemType;
/*
 *顺序栈的定义 
 */
typedef struct {
	SElemType* base;
	SElemType* top;
	int capacity;
	int stackSize;
}SqStack;



bool initSqStack(SqStack* S);

bool destorySqStack(SqStack* S);

//压栈
bool Push(SqStack* S, SElemType e);

bool Pop(SqStack* S, SElemType* p);

//用*p返回栈顶元素，但是不弹栈
bool getTop(SqStack* S, SElemType* p);

bool sqStackIsEmpty(SqStack S);

bool clearSqStack(SqStack* S);


void travelSqStack(SqStack S);

