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

typedef struct SqList{  //顺序表（顺序结构）的定义
	ElemType * elem;
	int length;
	int listsize;
}SqList;

typedef struct ListInfo{
    char name[20];
    struct SqList* elem;
}ListInfo;

typedef struct ManageList{
    struct ListInfo* elem;
    int length;
    int listsize;
    int cur;
}ManageList;

status IntiaList(SqList *L);
status DestroyList(SqList *L);
status ClearList(SqList *L);
status ListEmpty(SqList *L);
int ListLength(SqList *L);
status GetElem(SqList *L,int i,ElemType *e);
status LocateElem(SqList *L,ElemType e,int (*compare)(ElemType,ElemType));
status PriorElem(SqList *L,ElemType cur,ElemType *pre_e);
status NextElem(SqList *L,ElemType cur,ElemType *next_e);
status ListInsert(SqList *L,int i,ElemType e);
status ListDelete(SqList *L,int i,ElemType *e);
status ListTraverse(SqList *L,void (*visit)(ElemType));

void visit(ElemType e);
status compare(ElemType e,ElemType f);
void save(ManageList* M);
void recover(ManageList* M,SqList **L);

#endif // DEF_H_INCLUDED
