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


typedef int status;
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode, *LNode_ptr, *Position;

typedef struct LinkList{
    struct LNode* head;
    //struct LNode* tail;
    int length;
}LinkList;

typedef struct ListInfo{
    char name[20];
    struct LinkList* elem;
}ListInfo;

typedef struct ManageList{
    struct ListInfo* elem;
    int length;
    int listsize;
    int cur;
}ManageList;

status IntiaList(LinkList *L);
status DestroyList(LinkList *L);
status ClearList(LinkList *L);
status ListEmpty(LinkList *L);
int ListLength(LinkList *L);
status GetElem(LinkList *L,int i,ElemType *e);
status LocateElem(LinkList *L,ElemType e,int (*compare)(ElemType,ElemType));
status PriorElem(LinkList *L,ElemType cur_e,ElemType *pre_e);
status NextElem(LinkList *L,ElemType cur_e,ElemType *next_e);
status ListInsert(LinkList *L,int i,ElemType e);
status ListDelete(LinkList *L,int i,ElemType *e);
status ListTraverse(LinkList *L,void (*visit)(ElemType));

void visit(ElemType e);
status compare(ElemType e,ElemType f);
void save(ManageList* M);
void recover(ManageList* M,LinkList **L);

#endif // DEF_H_INCLUDED
