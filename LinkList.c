#include "LinkList.h"

void InitLinkList(LinkList* head){
	
	*head = (LinkList)malloc(sizeof(LNode));
	if (!head) exit(0); //��ʼ��ʧ��
	(*head)->next = NULL;
	return;
}


bool add(LinkList linkList, int elem) {
	if (!linkList) return false;
	LinkList temp = linkList;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = (LinkList)malloc(sizeof(LNode));
	if (!temp->next) {
		return false;
	}
	temp->next->data = elem;
	temp->next->next = NULL;
	return true;
}

/*
 *���ٳɹ�����true,ʧ�ܷ���false 
 */
bool destroyLinkList(LinkList L) {
	if (!L) return false;
	LinkList temp;
	/*for (i = L->next; L!= NULL; L = i) {
		free(L);
	}*/
	/*ʹ��һ���м�����洢ͷ�ڵ����һ���ڵ㣬����freeͷ�ڵ�*/
	while (L) {
		temp = L->next;
		free(L);
		L = temp;
	}
	return true;
}

/*
 * ��ճɹ�����true�����򷵻�false
*/
bool clearLinkList(LinkList L) {
	if (!L) return false;
	if (!(L->next)) return false;
	LinkList temp;
	while (L->next) {
		temp = L->next;
		L->next = temp->next;
		free(temp);
	}
	return true;
}

/*�ж������Ƿ�Ϊ�գ����򷵻�true�����򷵻�false*/
bool listIsEmpty(LinkList L) {
	if (!L || L->next) return true;
	return false;
}

int listLength(LinkList L) {
	LinkList temp = L->next;
	int count = 0;
	while (temp) {
		count++;
		temp = temp->next;
	}
	return count;
}


/*��Ԫ��elem��������ĵ�i���ڵ�,�ɹ�����true,ʧ�ܷ���false*/
bool linkListInsert(LinkList L, int i, int elem) {
	if (!L || i < 1) return false; //LΪ��ָ�����
	LinkList temp = L;
	int count = 0; //������
	while (L && count < i -1) {
		temp = temp->next;
		count++;
	}
	//��ʱ��tempָ��ľ��ǵ�i-1��Ԫ��
	
	LinkList newElem = (LinkList)malloc(sizeof(LNode)); //Ϊelem����ռ�
	if (!newElem) return false; //����ʧ��
	newElem->data = elem; //Ϊ�½ڵ㸳ֵ
	newElem->next = temp->next; //����Ԫ��ָ��ԭ���ĵ�i���ڵ�(temp�ǵ�i-1���ڵ�)
	temp->next = newElem;
	return true;
}

int getLinkListElem(LinkList L, int i) {
	if (!L || i < 1) exit(0); //����������
	LinkList temp = L;
	int count = 0; //������
	while (L && count < i) {
		temp = temp->next;
		count++;
	}
	return temp->data;
}

/*����ָ��ֵ���±�,��û�и�ֵ����ʧ�ܷ���-1*/
int locateLinkListElem(LinkList L, int value){	
	if (!L) return -1;
	int count; //������
	LinkList temp = L;
	for (count = 1; (temp->next) != NULL; count++) {
		temp = temp->next;
		if (temp->data == value) {
			return count;
		}
	}
	return -1;
}

/*���� ��ǰ����ֵΪvalue �ĵ�һ���ڵ��ǰ��,û���ҵ�����NULL*/
LinkList priorElem(LinkList L, int cur_value) {
	if (!L) exit(0);
	
	LinkList temp = L->next;
	LinkList prior = L;
	while (temp && cur_value!=(temp->data)) {
		if (temp->next) {
			prior = temp;
			temp = temp->next;
		}
	}
	if (temp) NULL;
	return prior;
}


LinkList nextElem(LinkList L, int cur_value) {
	if (!L) exit(0);

	LinkList temp = L->next;
	LinkList n = temp->next;
	while (temp && cur_value != (temp->data)) {
		if (temp->next) {
			temp = temp->next;
			n = temp->next;
		}
	}
	if (temp) NULL;
	return n;
}

//ɾ�������е�i���ڵ㣬�����ظýڵ��ֵ
int deleteLinkListElem(LinkList L, int i) {
	if (!L || i < 1) exit(0);

	LinkList temp = L;
	int count = 0;
	while (temp && count < i -1) {
		temp = temp->next;
		count++;
	}
	
	LinkList p = temp->next;
	int value = p->data;
	temp->next = p->next;
	free(p);
	return value;
}

void travelLinkList(LinkList L) {
	LinkList temp = L->next;
	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n\n");
	return;
}


bool modifyLinkListElem(LinkList L, int i, int elem) {
	if (!L || i < 1) return false; //LΪ��ָ�����
	LinkList temp = L;
	int count = 0; //������
	while (L && count < i) {
		temp = temp->next;
		count++;
	}
	// ��ʱtempָ���i������ڵ�
	temp->data = elem;

	return true;
}