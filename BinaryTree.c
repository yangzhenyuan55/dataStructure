#include "BinaryTree.h"

// 构造一个二叉树
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
	// 二叉树当前节点为空
	if (!(*T)) {
		// 申请空间内存
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

	// 当小于当前节点的值，插入到此节点的左孩子节点
	if (val < (*T)->val) {
		InsertNode(&(*T)->lchild, val);
	} else if (val > (*T)->val) {
		InsertNode(&(*T)->rchild, val);
	}
	return OK;
}

// 删除指定节点
// 递归
BiTree DeleteNode(BiTree T, TElemType val) {
	if (!T) {
		return NULL;
	}
	BiTNode* head = T;
	

	// 如果向删除的节点小于或者大于根节点，那么继续递归
	if (val < head->val) {
		head->lchild = DeleteNode(head->lchild, val);
	} else if (val > head->val) {
		head->rchild = DeleteNode(head->rchild, val);
	} else { // 找到对应节点，删除节点
		if (head->lchild != NULL) {
			BiTNode* MaxNode = head->lchild; // 最大的左孩子节点
			head->val = MaxNode->val;
			while (MaxNode->rchild) {
				head->val = MaxNode->val;
				MaxNode = MaxNode->rchild;
			}
			// 删除那个最大的节点
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

//递归先序遍历
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

//递归中序遍历
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

//递归后序遍历
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

// 销毁树，递归
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

	getchar(); //将回车键给get，免得影响下一个scanf

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




// ====================线索二叉树====================

