#include "BinaryTree.h"


Status InitBitree(BiTree* T) {
	(*T) = NULL;
	return OK;
}

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

//µÝ¹éÏÈÐò±éÀú
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

//µÝ¹éÖÐÐò±éÀú
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

//µÝ¹éºóÐò±éÀú
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