#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
typedef int Status;
typedef int Boolean;


typedef char TElemType;


// 二叉树节点
typedef struct BiTNode {

	TElemType val;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
	Boolean isEmpty;
}BiTNode, *BiTree;


// 线索二叉树标志域 Link == 0 (指针) Thread == 1 (线索)
typedef enum PointerTag {
	Link, Thread
}PointerTag;

// 线索二叉树节点
typedef struct BiThrNode {
	// 节点值
	TElemType val;
	// 左孩子指针和有孩子指针
	struct BiThrNode* lchild, * rchild;
	PointerTag LTag, RTag; //左右标志
}BiThrNode, * BiThrTree;




// ============二叉树=====================

Status CreateBiTree(BiTree* T);

Status PrintElem(TElemType e);

Status RcsPreOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

Status RcsInOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

Status RcsPostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));




// 构造线索二叉树
Status CreateBiThrTree(BiThrTree* T);