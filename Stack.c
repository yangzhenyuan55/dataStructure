#include "Stack.h"
#include <stdio.h>

//��ʼ��˳��ջ,�ɹ��򷵻�true,ʧ�ܷ���false
bool initSqStack(SqStack* S) {
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType*));
	if (!S->base) {
		return false;
	}//�洢����ʧ��
	S->top = S->base;
	S->stackSize = STACK_INIT_SIZE;
	return true;
}

bool increaseCapacity(SqStack* S) {
	S->base = (SElemType*)realloc(S->base, (S->stackSize + STACKINCREMENT)*sizeof(SElemType*));
	if (!S->base) exit(0);
	S->top = S->base + S->stackSize;
	S->stackSize += STACKINCREMENT;
	return true;
}


//����˳��ջ���ͷ�ռ�õ��ڴ�ռ䣬�ɹ�����true��ʧ���򷵻�false
bool destorySqStack(SqStack* S) {
	//˳��ջδ��ʼ��,ѹջʧ��
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("˳��ջδ��ʼ��");
		return false;
	}
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stackSize = 0;
	return false;
}

//ѹջ
bool Push(SqStack* S, SElemType e) {
	//˳��ջδ��ʼ��,ѹջʧ��
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("˳��ջδ��ʼ��");
		return false;
	}
	//ջ��������
	if (S->top - S->base >= S->stackSize) {
		increaseCapacity(S);
	}
	*S->top = e; //��Ԫ��ѹ��ջ�У�����topָ��Ԫ�ص���һ��λ��
	S->top++;
	return true;
}

//��ջ�����ظ�ջ��Ԫ��
//
bool Pop(SqStack* S, SElemType* p) {
	//ջδ��ʼ��
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("˳��ջδ��ʼ��");
		return false;
	}
	//ջΪ�գ���ջʧ��
	if (S->base == S->top) {
		return false;
	}
	S->top--;
	*p = *S->top;
	return true;
}

//����ջ��Ԫ��
bool getTop(SqStack* S, SElemType* p) {
	//ջδ��ʼ��
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("˳��ջδ��ʼ��");
		return false;
	}
	//ջΪ�գ���ջʧ��
	if (S->base == S->top) {
		return false;
	}

	*p = *(S->top - 1);
	return true;
}

//�ж�˳����Ƿ�Ϊ�գ����򷵻�true�����򷵻�false��
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
	//ջδ��ʼ��
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("˳��ջδ��ʼ��");
		return false;
	}
	S->base = S->top;
	return true;
}


