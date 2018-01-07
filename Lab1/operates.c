#include "def.h"


status IntiaList(SqList *L)
{
	L->elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L->elem) exit(OVERFLOW);
	L->length=0;
    L->listsize=LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList *L)
{
    if(!L->elem) return ERROR;
    free(L->elem);
    L->elem=NULL;
    L->length=0;
    L->listsize=0;
    return OK;
}

status ClearList(SqList *L)
{
    if(!L->elem) return ERROR;
    free(L->elem);
    L->elem = (ElemType *)malloc( L->listsize * sizeof (ElemType));
    if(!L->elem) exit(OVERFLOW);
    L->length=0;
    return OK;
}

status ListEmpty(SqList *L)
{
    if(!L->elem) return -1;
    if(L->length==0) return TRUE;
    else    return FALSE;
}

int ListLength(SqList *L)
{
    if(!L->elem) return -1;
    return L->length;
}

status GetElem(SqList *L,int i,ElemType *e)
{
    if(!L->elem||i<1||i>L->length) return ERROR;
    *e=L->elem[i-1];
    return OK;
}

status compare(ElemType e,ElemType f)
{
    return e==f?TRUE:FALSE;
}

status LocateElem(SqList *L,ElemType e,int (*compare)(ElemType,ElemType))
{
    if(!L->elem) return ERROR;
    int i=1;
    ElemType *p=L->elem;
    while(i<=L->length&&!(*compare)(*p++,e)) ++i;
    if(i<=L->length) return i;
    else return 0;
}

status PriorElem(SqList *L,ElemType cur,ElemType *pre_e)
{
    int i=LocateElem(L,cur,compare);
    if(i==1||i>L->length||i==0) return ERROR;
    else
    {
        *pre_e=L->elem[i-2];
        return OK;
    }
}

status NextElem(SqList *L,ElemType cur,ElemType *next_e)
{
    int i=LocateElem(L,cur,compare);
    if(i>=L->length||i==0) return ERROR;
    else
    {
        *next_e=L->elem[i];
        return OK;
    }
}

status ListInsert(SqList *L,int i,ElemType e)
{
    if(!L->elem||i<1||i>L->length+1) return ERROR;
    if(L->length>=L->listsize-1)
    {
        ElemType *newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L->elem=newbase;
        L->listsize+=LISTINCREMENT;
    }
    ElemType *q=L->elem+i-1;
    ElemType *p;
    for(p=L->elem+L->length-1;p>=q;--p)
    {
        *(p+1)=*p;
    }
    *q=e;
    ++L->length;
    return OK;
}

status ListDelete(SqList *L,int i,ElemType *e)
{
    if(!L->elem||i<1||i>L->length) return ERROR;
    ElemType *p,*q;
    p=L->elem+i-1;
    *e=*p;
    q=L->elem+L->length-1;
    for(++p;p<=q;++p)
    {
        *(p-1)=*p;
    }
    --L->length;
    return OK;
}

void visit(ElemType e)
{
    printf("%d\t",e);
}

status ListTraverse(SqList *L,void (*visit)(ElemType))
{
    if(!L->elem) return ERROR;
    ElemType *p;
    for(p=L->elem;(p-L->elem)<=L->length-1;p++)
    {
        (*visit)(*p);
    }
    return OK;
}

void save(ManageList* M)
{
    if(M->length==0) return;
    FILE* fp=NULL;
    int i;
    fp=fopen("save.dat","wb");
    fwrite(M,sizeof(ManageList),1,fp);
    fwrite(M->elem,sizeof(ListInfo),M->listsize,fp);
    for(i=0;i<M->length;i++)
    {
        fwrite((M->elem+i)->elem,sizeof(SqList),1,fp);
        fwrite((M->elem+i)->elem->elem,sizeof(ElemType),(M->elem+i)->elem->listsize,fp);
        free((M->elem+i)->elem->elem);
        free((M->elem+i)->elem);
    }
    free(M->elem);
    printf("已保存\n");
}

void recover(ManageList* M,SqList **L)
{
    FILE* fp=NULL;
    int i;
    fp=fopen("save.dat","rb");
    fread(M,sizeof(ManageList),1,fp);
    ListInfo* info=(ListInfo*)malloc(sizeof(ListInfo)*(M->listsize));
    M->elem=info;
    fread(M->elem,sizeof(ListInfo),M->listsize,fp);
    for(i=0;i<M->length;i++)
    {
        SqList* L=(SqList*)malloc(sizeof(SqList));
        fread(L,sizeof(SqList),1,fp);
        (M->elem+i)->elem=L;
        ElemType* e_ptr=(ElemType *)malloc( (L->listsize) * sizeof (ElemType));
        fread(e_ptr,sizeof (ElemType),L->listsize,fp);
        L->elem=e_ptr;
    }
    M->cur=0;
    *L=M->elem[0].elem;

    printf("恢复成功,按回车继续\n"); getchar();


}
