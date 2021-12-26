#include "LinkList.h"

void InitLinkList(LinkList* head){
	
	*head = (LinkList)malloc(sizeof(LNode));
	if (!head) exit(0); //初始化失败
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
 *销毁成功返回true,失败返回false 
 */
bool destroyLinkList(LinkList L) {
	if (!L) return false;
	LinkList temp;
	/*for (i = L->next; L!= NULL; L = i) {
		free(L);
	}*/
	/*使用一个中间变量存储头节点的下一个节点，依次free头节点*/
	while (L) {
		temp = L->next;
		free(L);
		L = temp;
	}
	return true;
}

/*
 * 清空成功返回true，否则返回false
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

/*判断链表是否为空，空则返回true，否则返回false*/
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


/*将元素elem插入链表的第i个节点,成功返回true,失败返回false*/
bool linkListInsert(LinkList L, int i, int elem) {
	if (!L || i < 1) return false; //L为空指针或者
	LinkList temp = L;
	int count = 0; //计数器
	while (L && count < i -1) {
		temp = temp->next;
		count++;
	}
	//此时的temp指向的就是第i-1个元素
	
	LinkList newElem = (LinkList)malloc(sizeof(LNode)); //为elem分配空间
	if (!newElem) return false; //分配失败
	newElem->data = elem; //为新节点赋值
	newElem->next = temp->next; //将新元素指向原来的第i个节点(temp是第i-1个节点)
	temp->next = newElem;
	return true;
}

int getLinkListElem(LinkList L, int i) {
	if (!L || i < 1) exit(0); //不符合条件
	LinkList temp = L;
	int count = 0; //计数器
	while (L && count < i) {
		temp = temp->next;
		count++;
	}
	return temp->data;
}

/*返回指定值的下标,若没有该值或者失败返回-1*/
int locateLinkListElem(LinkList L, int value){	
	if (!L) return -1;
	int count; //计数器
	LinkList temp = L;
	for (count = 1; (temp->next) != NULL; count++) {
		temp = temp->next;
		if (temp->data == value) {
			return count;
		}
	}
	return -1;
}

/*返回 当前链表值为value 的第一个节点的前驱,没有找到返回NULL*/
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

//删除链表中第i个节点，并返回该节点的值
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
	if (!L || i < 1) return false; //L为空指针或者
	LinkList temp = L;
	int count = 0; //计数器
	while (L && count < i) {
		temp = temp->next;
		count++;
	}
	// 此时temp指向第i个链表节点
	temp->data = elem;

	return true;
}