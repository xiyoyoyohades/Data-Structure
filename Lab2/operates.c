#include "def.h"


status IntiaList(LinkList *L)
{
	L->head = (LNode_ptr)malloc(sizeof (LNode));
    if(!L->head) exit(OVERFLOW);
	L->length=0;
	L->head->data=-1;
	L->head->next=NULL;
	return OK;
}

status DestroyList(LinkList *L)
{
    if(!L->head) return ERROR;
    LNode_ptr cur,af;
    af=L->head;
    while(af!=NULL)
    {
        cur=af;
        af=af->next;
        free(cur);
    }
    L->head=NULL;
    L->length=0;
    return OK;
}

status ClearList(LinkList *L)
{
    if(!L->head) return ERROR;
    LNode_ptr cur,af;
    if(L->length!=0)
    {
        af=L->head->next;
        while(af!=NULL)
        {
            cur=af;
            af=af->next;
            free(cur);
        }
        L->length=0;
        L->head->next=NULL;
        return OK;
    }
    else return OK;

}

status ListEmpty(LinkList *L)
{
    if(!L->head) return -1;
    if(L->length==0) return TRUE;
    else    return FALSE;
}

int ListLength(LinkList *L)
{
    if(!L->head) return -1;
    return L->length;
}

status GetElem(LinkList *L,int i,ElemType *e)
{
    if(!L->head||i<1||i>L->length) return ERROR;
    Position p=L->head;
    while(i)
    {
        p=p->next;
        i--;
    }
    *e=p->data;
    return OK;
}

status compare(ElemType e,ElemType f)
{
    return e==f?TRUE:FALSE;
}

status LocateElem(LinkList *L,ElemType e,int (*compare)(ElemType,ElemType))
{
    int i=1;
    LNode_ptr p=L->head->next;
    while(i<=L->length&&!(*compare)(p->data,e))
    {
        ++i;
        p=p->next;
    }
    if(i<=L->length) return i;
    else return 0;
}

status PriorElem(LinkList *L,ElemType cur_e,ElemType *pre_e)
{
    int i=LocateElem(L,cur_e,compare);
    if(i==1||i>L->length||i==0) return ERROR;
    else
    {
        Position cur,pre;
        cur=L->head->next;
        pre=L->head;
        while(cur&&cur->data!=cur_e)
        {
            cur=cur->next;
            pre=pre->next;
        }
        *pre_e=pre->data;
        return OK;
    }
}

status NextElem(LinkList *L,ElemType cur_e,ElemType *next_e)
{
    int i=LocateElem(L,cur_e,compare);
    if(i==0||i>=L->length) return ERROR;
    else
    {
        Position cur=L->head->next;
        while(cur&&cur->data!=cur_e)
        {
            cur=cur->next;
        }
        *next_e=cur->next->data;
        return OK;
    }
}

status ListInsert(LinkList *L,int i,ElemType e)
{
    if(!L->head||i<1||i>L->length+1) return ERROR;
    Position pos=L->head->next;
    Position pre=L->head;
    while(i-1)
    {
        pos=pos->next;
        pre=pre->next;
        i--;
    }
    LNode_ptr new_node=(LNode_ptr)malloc(sizeof(LNode));
    new_node->data=e;
    new_node->next=pos;
    pre->next=new_node;
    ++L->length;
    return OK;
}

status ListDelete(LinkList *L,int i,ElemType *e)
{
    if(!L->head||i<1||i>L->length) return ERROR;
    Position pos=L->head->next;
    Position pre=L->head;
    while(i-1)
    {
        pos=pos->next;
        pre=pre->next;
        i--;
    }
    *e=pos->data;
    pre->next=pos->next;
    free(pos);
    --L->length;
    return OK;
}

void visit(ElemType e)
{
    printf("%d\t",e);
}

status ListTraverse(LinkList *L,void (*visit)(ElemType))
{
    if(!L->head) return ERROR;
    Position p=L->head->next;
    while(p)
    {
        (*visit)(p->data);
        p=p->next;
    }
    return OK;
}

void save(ManageList* M)
{
    if(M->length==0) return;
    FILE* fp=NULL;
    int i;
    LinkList *info_node;
    LNode_ptr cur,pre;
    fp=fopen("save.dat","wb");
    fwrite(M,sizeof(ManageList),1,fp);
    fwrite(M->elem,sizeof(ListInfo),M->listsize,fp);
    for(i=0;i<M->length;i++)
    {
        info_node=(M->elem+i)->elem;
        fwrite(info_node,sizeof(LinkList),1,fp);
        cur=info_node->head;
        while(cur)
        {
            fwrite(cur,sizeof(LNode),1,fp);
            pre=cur;
            cur=cur->next;
            free(pre);
        }
        free(info_node);
    }
    free(M->elem);
    printf("已保存\n");
}

void recover(ManageList* M,LinkList **L)
{
    FILE* fp=NULL;
    int i,j;
    fp=fopen("save.dat","rb");
    fread(M,sizeof(ManageList),1,fp);
    ListInfo* info=(ListInfo*)malloc(sizeof(ListInfo)*(M->listsize));
    M->elem=info;
    fread(M->elem,sizeof(ListInfo),M->listsize,fp);
    for(i=0;i<M->length;i++)
    {
        LinkList* L=(LinkList*)malloc(sizeof(LinkList));
        fread(L,sizeof(LinkList),1,fp);
        (M->elem+i)->elem=L;
        LNode_ptr cur,new_node;
        L->head=(LNode_ptr)malloc(sizeof(LNode));
        fread(L->head,sizeof(LNode),1,fp);
        cur=L->head;
        for(j=1;j<=L->length;j++)
        {
            new_node=(LNode_ptr)malloc(sizeof(LNode));
            fread(new_node,sizeof(LNode),1,fp);
            cur->next=new_node;
            cur=new_node;
        }
        cur->next=NULL;
    }
    M->cur=0;
    *L=M->elem[0].elem;

    printf("恢复成功,按回车继续\n"); getchar();


}
