#include "def.h"


int main()
{
    LinkList* L; int op=1; char rec;
    ManageList M;
    M.length=0;
    M.listsize=10;
    M.cur=-1;
    printf("是否从文件读入数据？y/n\n");
    scanf("%c",&rec); fflush(stdin);
    if(rec=='y') recover(&M,&L);
    else M.elem=(ListInfo*)malloc(sizeof(ListInfo)*10);

    while(op)
    {
        system("cls");	printf("\n\n");
        printf("      Menu for Linear Table On List Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. IntiaList       7. LocateElem\n");
        printf("    	  2. DestroyList     8. PriorElem\n");
        printf("    	  3. ClearList       9. NextElem \n");
        printf("    	  4. ListEmpty      10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem        12. ListTraverse\n");
        printf("                            13. switch list\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~13]:");
        scanf("%d",&op);
        switch(op){
        case 1:
            {

            if(M.length+1>=M.listsize)
            {
                ListInfo* newelem=(ListInfo*)realloc(M.elem,(M.listsize+1)*sizeof(ListInfo));
                if(!newelem) exit(OVERFLOW);
                M.elem=newelem;
                M.listsize++;
            }
            M.elem[M.length].elem=(LinkList*)malloc(sizeof(LinkList));
            L=M.elem[M.length].elem;
            if(IntiaList(L)==OK)
            {
                printf("线性表创建成功！\n");
                itoa(M.length+1,M.elem[M.length].name,10);
                ++(M.length);
                M.cur=M.length-1;
                fflush(stdin); getchar();
                break;

            }
            else
            {
                free(L);
                M.elem[M.length].elem=NULL;
                printf("线性表创建失败！\n");
                fflush(stdin); getchar();
                break;

            }
            }
        case 2:
            if(M.length==0)
            {
                printf("没有表可以摧毁！\n"); fflush(stdin); getchar();
                break;
            }
            if(DestroyList(L)==OK)
            {
                int i;
                free(L);
                for(i=M.cur;i<M.length;i++)
                {
                    M.elem[i]=M.elem[i+1];
                }
                M.length--;
                M.cur=0;
                L=M.elem[0].elem;

                printf("线性表销毁成功！\n");
            }
            else printf("线性表销毁失败！\n");
            fflush(stdin); getchar();
            break;
        case 3:
            if(M.length==0)
            {
                printf("没有表可以置空！\n"); fflush(stdin); getchar();
                break;
            }
            if(ClearList(L)==OK) printf("线性表已置空！\n");
            else printf("线性表置空失败！\n");
            fflush(stdin); getchar();
            break;
        case 4:
            {
                if(M.length==0)
                {
                    printf("没有表可以判断！\n"); fflush(stdin); getchar();
                    break;
                }
                status s=ListEmpty(L);
                if(s==-1) printf("线性表不存在！\n");
                if(s==TRUE) printf("线性表为空表！\n");
                if(s==FALSE) printf("线性表不为空！\n");
                fflush(stdin); getchar();
                break;
            }

        case 5:
            {
                if(M.length==0)
                {
                    printf("没有表可以进行计算！\n"); fflush(stdin); getchar();
                    break;
                }
                int length=ListLength(L);
                if(length==-1) printf("线性表不存在！\n");
                else printf("线性表元素个数为%d个\n",length);
                fflush(stdin); getchar();
                break;
            }

        case 6:
            {
                if(M.length==0)
                {
                    printf("没有表！\n"); fflush(stdin); getchar();
                    break;
                }
                int i;
                ElemType e;
                printf("第i个元素的值\n输入i:");
                scanf("%d",&i); fflush(stdin);
                if(GetElem(L,i,&e)==OK) printf("第%d个元素的值为%d\n",i,e);
                else printf("该数据元素不存在\n");
                fflush(stdin); getchar();
                break;
            }

        case 7:
            {
                if(M.length==0)
                {
                    printf("没有表！\n"); fflush(stdin); getchar();
                    break;
                }
                ElemType e;
                int i;
                printf("元素定位\n输入元素e:");
                scanf("%d",&e); fflush(stdin);
                i=LocateElem(L,e,compare);
                if(i) printf("e元素位序为%d\n",i);
                else printf("数据元素不存在\n");
                fflush(stdin); getchar();
                break;
            }

        case 8:
            {
                if(M.length==0)
                {
                    printf("没有表！\n"); fflush(stdin); getchar();
                    break;
                }
                ElemType pre_e,cur;
                printf("元素前驱查找\n输入元素cur:");
                scanf("%d",&cur); fflush(stdin);
                if(PriorElem(L,cur,&pre_e)==OK) printf("元素cur的前驱元素为%d\n",pre_e);
                else printf("操作失败！\n");
                fflush(stdin); getchar();
                break;
            }

        case 9:
            {
                if(M.length==0)
                {
                    printf("没有表！\n"); fflush(stdin); getchar();
                    break;
                }
                ElemType next_e,cur;
                printf("元素后继查找:\n输入元素cur:");
                scanf("%d",&cur); fflush(stdin);
                if(NextElem(L,cur,&next_e)==OK) printf("元素cur的后继元素为%d\n",next_e);
                else printf("操作失败！\n");
                fflush(stdin); getchar();
                break;
            }

        case 10:
            {
                if(M.length==0)
                {
                    printf("没有表！\n"); fflush(stdin); getchar();
                    break;
                }
                int i;
                ElemType e;
                printf("在第i个元素之前插入元素e\n输入i:");
                scanf("%d",&i); fflush(stdin);
                printf("输入元素e\n");
                scanf("%d",&e); fflush(stdin);
                if(ListInsert(L,i,e)==OK) printf("元素插入成功！\n");
                else printf("插入失败！\n");
                fflush(stdin);getchar();
                break;
            }

        case 11:
            {
                if(M.length==0)
                {
                    printf("没有表！\n"); fflush(stdin); getchar();
                    break;
                }
                int i;
                ElemType e;
                printf("删除第i个元素\n输入i:");
                scanf("%d",&i); fflush(stdin);
                if(ListDelete(L,i,&e)==OK) printf("元素删除成功！第%d个元素值为%d\n",i,e);
                else printf("删除失败！\n");
                fflush(stdin); getchar();
                break;
            }

        case 12:
            {
                if(M.length==0)
                {
                    printf("没有表！\n"); fflush(stdin); getchar();
                    break;
                }
                if(!ListTraverse(L,visit)) printf("线性表是空表！\n");
                else printf("\n遍历完成\n");
                fflush(stdin); getchar();
                break;
            }

        case 13:
            {
                int i,j;
                if(M.length==0)
                {
                    printf("当前没有线性表\n");
                    fflush(stdin); getchar();
                    break;
                }
                if(M.length==1)
                {
                    printf("当前只有1个线性表\n");
                    printf("表%d\t名称：%s\t长度：%d\n",1,(M.elem)->name,(M.elem)->elem->length);
                    fflush(stdin); getchar();
                    break;
                }
                for(i=0;i<=M.length-1;i++)
                {
                    printf("表%d\t名称：%s\t长度：%d\n",i+1,(M.elem+i)->name,(M.elem+i)->elem->length);
                }
                printf("选择线性表[1-%d]\n",M.length);
                scanf("%d",&j); fflush(stdin);
                L=(M.elem+j-1)->elem;
                M.cur=j-1;
                printf("切换成功\n");
                fflush(stdin); getchar();
                break;

            }

        case 0:
         break;
	}
  }
  char choose;
  printf("是否保存数据到文件？\ty/n:"); fflush(stdin);
  scanf("%c",&choose); fflush(stdin);
  printf("\n");
  if(choose=='y') save(&M);
  printf("欢迎下次再使用本系统！\n\n---回车键退出---\n");
  getchar();
  return 0;
}


