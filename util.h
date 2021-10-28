#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

//ջ�ĳ�ʼ����
#define STACK_INIT_CAP 20
#define STACKINCREACAP 10

//�������ֵ�ջ
typedef struct {
	double* base; //ջ��
	double* top; //ջ��
	int cap; //ջ������
}NumStack;

//�����ַ���ջ
typedef struct {
	char* base;
	char* top;
	int cap;
}CharStack;


//======================================
bool initNumStack(NumStack* S);

//ѹջ
bool PushNum(NumStack* S, double e);

double PopNum(NumStack* S);

//��*p����ջ��Ԫ�أ����ǲ���ջ
double getTopNum(NumStack* S);

bool NumStackIsEmpty(NumStack S);

//=======================================

bool initCharStack(CharStack* S);


//ѹջ
bool PushChar(CharStack* S, int e);

char PopChar(CharStack* S);

//��*p����ջ��Ԫ�أ����ǲ���ջ
char getTopChar(CharStack* S);

bool CharStackIsEmpty(CharStack S);
//========================================

//�ж�һ�������Ƿ�Ϸ�
bool bracketIsMatch(SElemType* b, int bracket_len);

//�����������ʽ
//�������ʽ�ַ���exprs
double evaluateExpression(char* expr);