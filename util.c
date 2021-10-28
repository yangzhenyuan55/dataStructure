#include "util.h"


/*
 *
 * 工具
 * 
*/


//==================================================
/*
* 四则运算
* x,y:参与运算的数字
* op:运算符
* 结果：res = x op y;
*/
double evaluate(double x,char op,double y) {
	switch (op)
	{
	case '+':return x + y;
	case '-':return x - y;
	case '*':return x * y;
	case '/':return x / y;
	default:
		return 0;
		printf("运算出错\n");
		break;
	}
}

/*
* 返回运算符的优先级
* 按照1,2,3四个等级划分
* 从低到高分别是 '#', '+ -',  '* /'
*/

int compare(char ch) {
	if (ch == '#') return 1;
	else if (ch == '+' || ch == '-') return 2;
	else if (ch == '*' || ch == '/') return 3;
	else return 4; 
}

/*
* 判断符号是否是运算符(+ - * /)
*/
bool isOperationChar(char ch) {
	if (ch == '(' || ch == ')') return false;
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
	else {
		printf("运算符出错\n");
		exit(0);
	}
}


//=========================================
bool initNumStack(NumStack* S) {
	S->base = (double*)malloc(STACK_INIT_CAP * sizeof(double*));
	if (!S->base) {
		return false;
	}//存储分配失败
	S->top = S->base;
	S->cap = STACK_INIT_CAP;
	return true;
}


bool PushNum(NumStack* S, double e) {
	//顺序栈未初始化,压栈失败
	if (S->cap < STACK_INIT_CAP) {
		puts("顺序栈未初始化");
		return false;
	}
	//栈满，扩容
	if (S->top - S->base >= S->cap) {
		S->base = (double*)realloc(S->base,(STACK_INIT_CAP+ STACK_INIT_SIZE) * sizeof(double*));
		if (!S->base) {
			return false;
		}//存储分配失败
		S->top = S->base;
		S->cap += STACK_INIT_CAP;
		return true;
	}
	*(S->top++) = e; //将元素压入栈中，并将top指向元素的下一个位置
	return true;
}

double PopNum(NumStack* S) {
	
	//栈为空，弹栈失败
	if (S->base == S->top) {
		return 0;
	}
	double e;
	e = *(--S->top);
	return e;
}

double getTopNum(NumStack* S){
	
	//栈为空，弹栈失败
	if (S->base == S->top) {
		return false;
	}

	return *(S->top - 1);
}

bool NumStackIsEmpty(NumStack S) {
	if (S.base == S.top) {
		return true;
	}
	else {
		return false;
	}
	return true;
}
//======================================
//======================================
bool initCharStack(CharStack* S)
{
	S->base = (char*)malloc(STACK_INIT_CAP * sizeof(char*));
	if (!S->base) {
		return false;
	}//存储分配失败
	S->top = S->base;
	S->cap = STACK_INIT_CAP;
	return true;
}

bool PushChar(CharStack* S, int e) {
	//栈满，扩容
	if (S->top - S->base >= S->cap) {
		S->base = (char*)realloc(S->base,(STACK_INIT_CAP + STACK_INIT_SIZE) * sizeof(char*));
		if (!S->base) {
			return false;
		}//存储分配失败
		S->top = S->base;
		S->cap += STACK_INIT_CAP;
		return true;
	}
	*(S->top++) = e; //将元素压入栈中，并将top指向元素的下一个位置
	return true;
}

char PopChar(CharStack* S) {
	//栈为空，弹栈失败
	if (S->base == S->top) {
		return 0;
	}

	return *(--S->top);
}

char getTopChar(CharStack* S) {
	//栈为空，弹栈失败
	if (S->base == S->top) {
		return false;
	}

	return *(S->top - 1);
}

bool CharStackIsEmpty(CharStack S) {
	if (S.base == S.top) {
		return true;
	}
	else return false;
	return true;
}
//=========================================

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
//==================================================================================



/*
* 将中缀表达式转换成后缀表达式
* 以栈的形式返回
*/
CharStack* transferInfixToSuffix(char* infixExpr) {
	CharStack chs;
	initCharStack(&chs);


}

//计算中缀表达式
double evaluateExpression(char* expr) {
	NumStack nums; //数字栈
	CharStack chs; //符号栈
	int expr_len = strlen(expr); //表达式的长度
	//初始化栈
	initNumStack(&nums);
	initCharStack(&chs);

	int i = 0;
	int j; //i, j都是循环变量
	double num = 0; //数字栈中的数字

	for (i = 0; expr[i] != '#' && i < expr_len; i++) { 
		num = 0;
		j = i;
		if (expr[j] >= '1' && expr[j] <= '9') { //这个字符是数字的情况下
			//先获取这个数字的整数部分
			while (expr[j] >= '1' && expr[j] <= '9') {
				num = (double)((expr[j]-'0') + num*10);
				j++;
			}
			//如果这个数字有小数部分
			if (expr[j] == '.') {
				double smNum = 0; //小数部分
				j++; //将下标移到小数的第一个数字
				int count = 1; //小数部分的位数
				while (expr[j] >= '1' && expr[j] <= '9') {
					smNum = (double)((expr[j] - '0') + smNum * 10);
					j++;
					count *= 10;
				}
				num += smNum / count;
			}
			i = --j; //循环体结束的时候i还会自增一次，所以在这里i先自减
			PushNum(&nums, num); //将数字压入数字栈内

		} else if (isOperationChar(expr[i])) { //如果当前字符是运算符
			if (CharStackIsEmpty(chs)) {
				//如果当前字符栈为空，直接压入栈内
				PushChar(&chs,expr[i]);
			} else {
				char topElem = getTopChar(&chs); //符号栈的栈顶元素
				if (compare(topElem) >= compare(expr[i])) { //判断栈顶运算符的优先级，大于当前的直接进行运算
					double y = PopNum(&nums);
					double x = PopNum(&nums);
					double res = evaluate(x, topElem, y);
					PopChar(&chs); //将栈顶元素弹出
					PushNum(&nums,res); //将运算结果再次压入栈内
				}
				if (expr[i] != '#') {
					//如果不是#号则压入栈内
					PushChar(&chs,expr[i]);
				}
			}
		} else if (!isOperationChar(expr[i])) {
			if (expr[i]=='(') {
				//如果是 左括号直接压栈
				PushChar(&chs,expr[i]);
			} else {
				while (getTopChar(&chs)!='(') {
					char topElem = getTopChar(&chs); //符号栈的栈顶元素
					double y = PopNum(&nums);
					double x = PopNum(&nums);
					double res = evaluate(x, topElem, y);
					PopChar(&chs); //将栈顶元素弹出
					PushNum(&nums, res); //将运算结果再次压入栈内
				}
				PopChar(&chs); //将 '(' 弹出
			}
		}
	}

	//若运算符栈不为空，那么就一直计算
	while (!CharStackIsEmpty(chs)) {
		char topElem = getTopChar(&chs); //符号栈的栈顶元素
		double y = PopNum(&nums);
		double x = PopNum(&nums);
		double res = evaluate(x, topElem, y);
		PopChar(&chs); //将栈顶元素弹出
		PushNum(&nums, res); //将运算结果再次压入栈内
	}

	return getTopNum(&nums); //返回数字栈的栈顶元素就是最终结果
}


