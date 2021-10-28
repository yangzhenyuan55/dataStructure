#include <stdlib.h>
#include <stdbool.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char SElemType;
/*
 *˳��ջ�Ķ��� 
 */
typedef struct {
	SElemType* base;
	SElemType* top;
	int stackSize;
}SqStack;



bool initSqStack(SqStack* S);

bool destorySqStack(SqStack* S);

//ѹջ
bool Push(SqStack* S, SElemType e);

bool Pop(SqStack* S, SElemType* p);

//��*p����ջ��Ԫ��
bool getTop(SqStack* S, SElemType* p);

bool sqStackIsEmpty(SqStack S);

bool clearSqStack(SqStack* S);

//�ж�һ�������Ƿ�Ϸ�
bool bracketIsMatch(SElemType* b, int bracket_len);