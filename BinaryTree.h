#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

// 构造二叉树
Status CreateBiTree(BiTree* T);

// 往二叉树中插入节点
Status InsertNode(BiTree* T, TElemType val);

// 删除指定的节点
BiTree DeleteNode(BiTree T, TElemType val);

// 修改指定的节点
Status ModifyNode(BiTree T, TElemType val, TElemType up);

// 打印节点
Status PrintElem(TElemType e);

// 递归先序遍历
Status RcsPreOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

// 递归中序遍历
Status RcsInOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

// 递归后续遍历
Status RcsPostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

Status DestoryBiTree(BiTree T);



// 构造线索二叉树
Status CreateThrBiTree(BiThrTree* T);