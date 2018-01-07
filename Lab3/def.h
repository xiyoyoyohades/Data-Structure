#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define MAX_LENGTH 512

typedef int status;
typedef int TElemType;

typedef struct BiTNode{
	TElemType index;
	TElemType grade;
	struct BiTNode *lchild,*rchild;
}BiTNode, *Tree, *TreeNode, *BiTree;

typedef struct Bitreeinfo{
    int ver_num;
    int depth;
    struct BiTNode *root;
}Bitreeinfo, *Treeinfo;

typedef struct ListInfo{
    char name[20];
    struct Bitreeinfo* elem;
}ListInfo;

typedef struct ManageList{
    struct ListInfo* elem;
    int length;
    int listsize;
    int cur;
}ManageList;

status InitBiTree(Tree* T);
status DestroyBiTree(Tree T);
TreeNode CreateBiTree(Treeinfo L);
status ClearBiTree(Tree T);
status BiTreeEmpty(Tree T);
status BiTreeDepth(Tree T);
TreeNode Root(Tree T);
TElemType Value(Tree T,int e);
status Assign(Tree T,int e,int value);
TreeNode Parent(Tree T,int e);
TreeNode LeftChild(Tree T,int e);
TreeNode RightChild(Tree T,int e);
TreeNode LeftSibling(Tree T,int e);
TreeNode RightSibling(Tree T,int e);
status InsertChild(Tree T,int index,int LR,BiTree c);
status DeleteChild(Tree T,int e,int LR);
status PreOrderTraverse(Tree T,void (*visit)(TElemType));
status InOrderTraverse(Tree T,void (*visit)(TElemType));
status PostOrderTraverse(Tree T,void (*visit)(TElemType));
status LevelOrderTraverse(Tree T,void (*visit)(TElemType));

BiTree copy_tree(Tree T);
TreeNode Search(Tree T,int index);
int get_ver_num(Tree T);
void visit(TElemType e);
//status compare(ElemType e,ElemType f);
void save_tree(Tree T,FILE* fp);
void save(ManageList* M);
TreeNode recover_tree(FILE* fp);
void recover(ManageList* M,Treeinfo* L);


#endif // DEF_H_INCLUDED
