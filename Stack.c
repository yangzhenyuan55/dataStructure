#include "Stack.h"
#include <stdio.h>

//³õÊ¼»¯Ë³ÐòÕ»,³É¹¦Ôò·µ»Øtrue,Ê§°Ü·µ»Øfalse
bool initSqStack(SqStack* S) {
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType*));
	if (!S->base) {
		return false;
	}//´æ´¢·ÖÅäÊ§°Ü
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


//Ïú»ÙË³ÐòÕ»£¬ÊÍ·ÅÕ¼ÓÃµÄÄÚ´æ¿Õ¼ä£¬³É¹¦·µ»Øtrue£¬Ê§°ÜÔò·µ»Øfalse
bool destorySqStack(SqStack* S) {
	//Ë³ÐòÕ»Î´³õÊ¼»¯,Ñ¹Õ»Ê§°Ü
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("Ë³ÐòÕ»Î´³õÊ¼»¯");
		return false;
	}
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stackSize = 0;
	return false;
}

//Ñ¹Õ»
bool Push(SqStack* S, SElemType e) {
	//Ë³ÐòÕ»Î´³õÊ¼»¯,Ñ¹Õ»Ê§°Ü
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("Ë³ÐòÕ»Î´³õÊ¼»¯");
		return false;
	}
	//Õ»Âú£¬À©ÈÝ
	if (S->top - S->base >= S->stackSize) {
		increaseCapacity(S);
	}
	*S->top = e; //½«ÔªËØÑ¹ÈëÕ»ÖÐ£¬²¢½«topÖ¸ÏòÔªËØµÄÏÂÒ»¸öÎ»ÖÃ
	S->top++;
	return true;
}

//µ¯Õ»£¬·µ»Ø¸ÃÕ»¶¥ÔªËØ
//
bool Pop(SqStack* S, SElemType* p) {
	//Õ»Î´³õÊ¼»¯
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("Ë³ÐòÕ»Î´³õÊ¼»¯");
		return false;
	}
	//Õ»Îª¿Õ£¬µ¯Õ»Ê§°Ü
	if (S->base == S->top) {
		return false;
	}
	S->top--;
	*p = *S->top;
	return true;
}

//·µ»ØÕ»¶¥ÔªËØ
bool getTop(SqStack* S, SElemType* p) {
	//Õ»Î´³õÊ¼»¯
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("Ë³ÐòÕ»Î´³õÊ¼»¯");
		return false;
	}
	//Õ»Îª¿Õ£¬µ¯Õ»Ê§°Ü
	if (S->base == S->top) {
		return false;
	}

	*p = *(S->top - 1);
	return true;
}

//ÅÐ¶ÏË³Ðò±íÊÇ·ñÎª¿Õ£¨¿ÕÔò·µ»Øtrue£¬·ñÔò·µ»Øfalse£©
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
	//Õ»Î´³õÊ¼»¯
	if (S->stackSize < STACK_INIT_SIZE) {
		puts("Ë³ÐòÕ»Î´³õÊ¼»¯");
		return false;
	}
	S->base = S->top;
	return true;
}


