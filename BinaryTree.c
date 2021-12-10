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
}


Status PrintElem(TElemType e) {
	printf("%c",e);
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

Status CreateBiThrTree(BiThrTree* T) {
	TElemType data;
	scanf("%c", &data);


	if (data == '#') {
		*T = NULL;
		return FALSE;
	}
	(*T) = (BiTree)malloc(sizeof(BiThrNode));
	if (!(*T)) { return FALSE; };
	(*T)->val = data;

	getchar(); //将回车键给get，免得影响下一个scanf

	CreateBiThrTree(&(*T)->lchild);
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

