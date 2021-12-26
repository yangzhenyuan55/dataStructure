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


// �������ڵ�
typedef struct BiTNode {

	TElemType val;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
	Boolean isEmpty;
}BiTNode, *BiTree;


// ������������־�� Link == 0 (ָ��) Thread == 1 (����)
typedef enum PointerTag {
	Link, Thread
}PointerTag;

// �����������ڵ�
typedef struct BiThrNode {
	// �ڵ�ֵ
	TElemType val;
	// ����ָ����к���ָ��
	struct BiThrNode* lchild, * rchild;
	PointerTag LTag, RTag; //���ұ�־
}BiThrNode, * BiThrTree;




// ============������=====================

// ���������
Status CreateBiTree(BiTree* T);

// ���������в���ڵ�
Status InsertNode(BiTree* T, TElemType val);

// ɾ��ָ���Ľڵ�
BiTree DeleteNode(BiTree T, TElemType val);

// �޸�ָ���Ľڵ�
Status ModifyNode(BiTree T, TElemType val, TElemType up);

// ��ӡ�ڵ�
Status PrintElem(TElemType e);

// �ݹ��������
Status RcsPreOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

// �ݹ��������
Status RcsInOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

// �ݹ��������
Status RcsPostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

Status DestoryBiTree(BiTree T);



// ��������������
Status CreateThrBiTree(BiThrTree* T);