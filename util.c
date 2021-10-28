#include "util.h"


/*
 *
 * ����
 * 
*/


//==================================================
/*
* ��������
* x,y:�������������
* op:�����
* �����res = x op y;
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
		printf("�������\n");
		break;
	}
}

/*
* ��������������ȼ�
* ����1,2,3�ĸ��ȼ�����
* �ӵ͵��߷ֱ��� '#', '+ -',  '* /'
*/

int compare(char ch) {
	if (ch == '#') return 1;
	else if (ch == '+' || ch == '-') return 2;
	else if (ch == '*' || ch == '/') return 3;
	else return 4; 
}

/*
* �жϷ����Ƿ��������(+ - * /)
*/
bool isOperationChar(char ch) {
	if (ch == '(' || ch == ')') return false;
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
	else {
		printf("���������\n");
		exit(0);
	}
}


//=========================================
bool initNumStack(NumStack* S) {
	S->base = (double*)malloc(STACK_INIT_CAP * sizeof(double*));
	if (!S->base) {
		return false;
	}//�洢����ʧ��
	S->top = S->base;
	S->cap = STACK_INIT_CAP;
	return true;
}


bool PushNum(NumStack* S, double e) {
	//˳��ջδ��ʼ��,ѹջʧ��
	if (S->cap < STACK_INIT_CAP) {
		puts("˳��ջδ��ʼ��");
		return false;
	}
	//ջ��������
	if (S->top - S->base >= S->cap) {
		S->base = (double*)realloc(S->base,(STACK_INIT_CAP+ STACK_INIT_SIZE) * sizeof(double*));
		if (!S->base) {
			return false;
		}//�洢����ʧ��
		S->top = S->base;
		S->cap += STACK_INIT_CAP;
		return true;
	}
	*(S->top++) = e; //��Ԫ��ѹ��ջ�У�����topָ��Ԫ�ص���һ��λ��
	return true;
}

double PopNum(NumStack* S) {
	
	//ջΪ�գ���ջʧ��
	if (S->base == S->top) {
		return 0;
	}
	double e;
	e = *(--S->top);
	return e;
}

double getTopNum(NumStack* S){
	
	//ջΪ�գ���ջʧ��
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
	}//�洢����ʧ��
	S->top = S->base;
	S->cap = STACK_INIT_CAP;
	return true;
}

bool PushChar(CharStack* S, int e) {
	//ջ��������
	if (S->top - S->base >= S->cap) {
		S->base = (char*)realloc(S->base,(STACK_INIT_CAP + STACK_INIT_SIZE) * sizeof(char*));
		if (!S->base) {
			return false;
		}//�洢����ʧ��
		S->top = S->base;
		S->cap += STACK_INIT_CAP;
		return true;
	}
	*(S->top++) = e; //��Ԫ��ѹ��ջ�У�����topָ��Ԫ�ص���һ��λ��
	return true;
}

char PopChar(CharStack* S) {
	//ջΪ�գ���ջʧ��
	if (S->base == S->top) {
		return 0;
	}

	return *(--S->top);
}

char getTopChar(CharStack* S) {
	//ջΪ�գ���ջʧ��
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

//˳��ջ��Ӧ��ʵ��
//�ж�һ�������Ƿ�Ϸ�
//SElemTyle����ֻ����char
bool bracketIsMatch(SElemType* b, int bracket_len) {
	//����ƥ��ļ���㷨
	SqStack stack;
	initSqStack(&stack);
	int i = 0;
	//��һ����������ֱ�Ӳ��Ϸ�
	if (b[0] == ')' || b[0] == ']' || b[0] == '}') return false;
	while (i < bracket_len) {
		//ɨ�赽������
		if (b[i] == '(' || b[i] == '[' || b[i] == '{') {
			Push(&stack, b[i]);
		}
		else { //ɨ�赽������
			if (sqStackIsEmpty(stack)) return false; //ջΪ������Щ���Ų��Ϸ�
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
* ����׺���ʽת���ɺ�׺���ʽ
* ��ջ����ʽ����
*/
CharStack* transferInfixToSuffix(char* infixExpr) {
	CharStack chs;
	initCharStack(&chs);


}

//������׺���ʽ
double evaluateExpression(char* expr) {
	NumStack nums; //����ջ
	CharStack chs; //����ջ
	int expr_len = strlen(expr); //���ʽ�ĳ���
	//��ʼ��ջ
	initNumStack(&nums);
	initCharStack(&chs);

	int i = 0;
	int j; //i, j����ѭ������
	double num = 0; //����ջ�е�����

	for (i = 0; expr[i] != '#' && i < expr_len; i++) { 
		num = 0;
		j = i;
		if (expr[j] >= '1' && expr[j] <= '9') { //����ַ������ֵ������
			//�Ȼ�ȡ������ֵ���������
			while (expr[j] >= '1' && expr[j] <= '9') {
				num = (double)((expr[j]-'0') + num*10);
				j++;
			}
			//������������С������
			if (expr[j] == '.') {
				double smNum = 0; //С������
				j++; //���±��Ƶ�С���ĵ�һ������
				int count = 1; //С�����ֵ�λ��
				while (expr[j] >= '1' && expr[j] <= '9') {
					smNum = (double)((expr[j] - '0') + smNum * 10);
					j++;
					count *= 10;
				}
				num += smNum / count;
			}
			i = --j; //ѭ���������ʱ��i��������һ�Σ�����������i���Լ�
			PushNum(&nums, num); //������ѹ������ջ��

		} else if (isOperationChar(expr[i])) { //�����ǰ�ַ��������
			if (CharStackIsEmpty(chs)) {
				//�����ǰ�ַ�ջΪ�գ�ֱ��ѹ��ջ��
				PushChar(&chs,expr[i]);
			} else {
				char topElem = getTopChar(&chs); //����ջ��ջ��Ԫ��
				if (compare(topElem) >= compare(expr[i])) { //�ж�ջ������������ȼ������ڵ�ǰ��ֱ�ӽ�������
					double y = PopNum(&nums);
					double x = PopNum(&nums);
					double res = evaluate(x, topElem, y);
					PopChar(&chs); //��ջ��Ԫ�ص���
					PushNum(&nums,res); //���������ٴ�ѹ��ջ��
				}
				if (expr[i] != '#') {
					//�������#����ѹ��ջ��
					PushChar(&chs,expr[i]);
				}
			}
		} else if (!isOperationChar(expr[i])) {
			if (expr[i]=='(') {
				//����� ������ֱ��ѹջ
				PushChar(&chs,expr[i]);
			} else {
				while (getTopChar(&chs)!='(') {
					char topElem = getTopChar(&chs); //����ջ��ջ��Ԫ��
					double y = PopNum(&nums);
					double x = PopNum(&nums);
					double res = evaluate(x, topElem, y);
					PopChar(&chs); //��ջ��Ԫ�ص���
					PushNum(&nums, res); //���������ٴ�ѹ��ջ��
				}
				PopChar(&chs); //�� '(' ����
			}
		}
	}

	//�������ջ��Ϊ�գ���ô��һֱ����
	while (!CharStackIsEmpty(chs)) {
		char topElem = getTopChar(&chs); //����ջ��ջ��Ԫ��
		double y = PopNum(&nums);
		double x = PopNum(&nums);
		double res = evaluate(x, topElem, y);
		PopChar(&chs); //��ջ��Ԫ�ص���
		PushNum(&nums, res); //���������ٴ�ѹ��ջ��
	}

	return getTopNum(&nums); //��������ջ��ջ��Ԫ�ؾ������ս��
}


