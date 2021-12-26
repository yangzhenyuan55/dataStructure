#include "BinaryTree.h"

// ����һ��������
Status CreateBiTree(BiTree* T) {
	TElemType e;
	scanf("%c",&e);
	if (e == '#') {
		*T = NULL;
		return FALSE;
	}
	(*T) = (BiTree)malloc(sizeof(BiTNode));
	
	(*T)->val = e;
	getchar();
	CreateBiTree(&(*T)->lchild);
	getchar();
	CreateBiTree(&(*T)->rchild);
	return OK;
}


Status InsertNode(BiTree* T, TElemType val) {
	// ��������ǰ�ڵ�Ϊ��
	if (!(*T)) {
		// ����ռ��ڴ�
		(*T) = (BiTree)malloc(sizeof(BiTNode));
		if (!(*T)) {
			return ERROR;
		}
		memset((*T), 0, sizeof(BiTNode));
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		(*T)->val = val;
		return OK;
	}

	// ��С�ڵ�ǰ�ڵ��ֵ�����뵽�˽ڵ�����ӽڵ�
	if (val < (*T)->val) {
		InsertNode(&(*T)->lchild, val);
	} else if (val > (*T)->val) {
		InsertNode(&(*T)->rchild, val);
	}
	return OK;
}

// ɾ��ָ���ڵ�
// �ݹ�
BiTree DeleteNode(BiTree T, TElemType val) {
	if (!T) {
		return NULL;
	}
	BiTNode* head = T;
	

	// �����ɾ���Ľڵ�С�ڻ��ߴ��ڸ��ڵ㣬��ô�����ݹ�
	if (val < head->val) {
		head->lchild = DeleteNode(head->lchild, val);
	} else if (val > head->val) {
		head->rchild = DeleteNode(head->rchild, val);
	} else { // �ҵ���Ӧ�ڵ㣬ɾ���ڵ�
		if (head->lchild != NULL) {
			BiTNode* MaxNode = head->lchild; // �������ӽڵ�
			head->val = MaxNode->val;
			while (MaxNode->rchild) {
				head->val = MaxNode->val;
				MaxNode = MaxNode->rchild;
			}
			// ɾ���Ǹ����Ľڵ�
			head->lchild = DeleteNode(head->lchild, MaxNode->val);
		} else if (head->rchild != NULL) {
			BiTNode* MinNode = head->rchild;
			head->val = MinNode->val;
			while (MinNode->lchild) {
				head->val = MinNode->val;
				MinNode = MinNode->lchild;
			}
			head->rchild = DeleteNode(head->rchild, MinNode->val);
		} else {
			return NULL;
		}
	}
	return head;
}


Status ModifyNode(BiTree T, TElemType val, TElemType up) {
	if (!T) {
		return ERROR;
	}
	if (T->val == val) {
		T->val = up;
		return OK;
	}
	if (T->lchild) {
		ModifyNode(T->lchild, val, up);
	}
	if (T->rchild) {
		ModifyNode(T->rchild, val, up);
	}
	return OK;
}


Status PrintElem(TElemType e) {
	printf("%c ",e);
	return OK;
}

//�ݹ��������
Status RcsPreOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		Visit(T->val);
		if (T->lchild != NULL) {
			RcsPreOrderTraverse(T->lchild, PrintElem);
		}
		if (T != NULL) {
			RcsPreOrderTraverse(T->rchild, PrintElem);
		}
	} else {
		return ERROR;
	}
	
	return OK;
}

//�ݹ��������
Status RcsInOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (T->lchild != NULL) {
			RcsInOrderTraverse(T->lchild, PrintElem);
		}
		Visit(T->val);
		if (T->rchild != NULL) {
			RcsInOrderTraverse(T->rchild, PrintElem);
		}
	} else {
		return ERROR;
	}
	
	return OK;
}

//�ݹ�������
Status RcsPostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (T->lchild != NULL) {
			RcsInOrderTraverse(T->lchild, PrintElem);
		}
		if (T->rchild != NULL) {
			RcsPostOrderTraverse(T->rchild, PrintElem);
		}
		Visit(T->val);
	}
	else {
		return ERROR;
	}
	
	return OK;
}

// ���������ݹ�
Status DestoryBiTree(BiTree T) {
	if (T) {
		DestoryBiTree(T->lchild);
		DestoryBiTree(T->rchild);
		free(T);
		T = NULL;
	}
	return OK;
}



Status CreateThrBiTree(BiThrTree* T) {
	TElemType data;
	scanf("%c", &data);


	if (data == '#') {
		*T = NULL;
		return FALSE;
	}
	(*T) = (BiTree)malloc(sizeof(BiTNode));
	if (!(*T)) { return FALSE; };
	(*T)->val = data;

	getchar(); //���س�����get�����Ӱ����һ��scanf

	CreateThrBiTree(&(*T)->lchild);
	if ((*T)->lchild) {
		(*T)->LTag = Link;
	} else {
		(*T)->LTag = Thread;
	}

	getchar();

	CreateThrBiTree(&(*T)->rchild);
	if ((*T)->rchild) {
		(*T)->RTag = Link;
	} else {
		(*T)->RTag = Thread;
	}

	return OK;
}




// ====================����������====================

