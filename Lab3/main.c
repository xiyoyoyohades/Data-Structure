#include "def.h"


int main()
{
    Treeinfo L; int op=1; char rec;
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
        printf("      Menu for Binary Tree On Binary List Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitBiTree       11. LeftChild\n");
        printf("    	  2. DestroyBiTree    12. RightChild\n");
        printf("    	  3. CreateBiTree     13. LeftSibling\n");
        printf("    	  4. ClearBiTree      14. RightSibling\n");
        printf("    	  5. BiTreeEmpty      15. InsertChild\n");
        printf("    	  6. BiTreeDepth      16. DeleteChild\n");
        printf("    	  7. Root             17. PreOrderTraverse\n");
        printf("    	  8. Value            18. InOrderTraverse\n");
        printf("    	  9. Assign           19. PostOrderTraverse\n");
        printf("    	 10. Parent           20. LevelOrderTraverse\n");
        printf("                              21. switch Tree\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~21]:");
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
            M.elem[M.length].elem=(Bitreeinfo*)malloc(sizeof(Bitreeinfo));
            L=M.elem[M.length].elem;
            if(InitBiTree(&(L->root))==OK)
            {
                printf("二叉树初始化成功！\n");
                itoa(M.length+1,M.elem[M.length].name,10);
                ++(M.length);
                M.cur=M.length-1;
                L->depth=0;
                L->ver_num=0;
                fflush(stdin); getchar();
                break;

            }
            else
            {
                free(L);
                M.elem[M.length].elem=NULL;
                printf("二叉树创建失败！\n");
                fflush(stdin); getchar();
                break;

            }
            }
        case 2:
            if(M.length==0)
            {
                printf("没有二叉树可以摧毁！\n"); fflush(stdin); getchar();
                break;
            }
            if(L->root)
            {
                if(DestroyBiTree(L->root)==OK)
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

                    printf("二叉树销毁成功！\n");
                }
                else printf("二叉树销毁失败！\n");
            }
            else
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

                    printf("二叉树销毁成功！\n");

            }

            fflush(stdin); getchar();
            break;

        case 3:
            {
                Tree root;
                if(M.length==0)
                {
                    printf("当前没有已初始化的二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                fflush(stdin);
                printf("请输入先序序列：");
                root=CreateBiTree(L);
                if(root)
                {
                    L->depth=BiTreeDepth(L->root);
                    L->root=root;
                    printf("二叉树创建成功\n");
                }
                else printf("二叉树创建失败\n");
                fflush(stdin); getchar();
                break;
            }


        case 4:
            if(M.length==0)
            {
                printf("没有二叉树可以置空！\n"); fflush(stdin); getchar();
                break;
            }
            if(ClearBiTree(L->root)==OK)
            {
                L->depth=0;
                L->ver_num=0;
                L->root=NULL;
                printf("二叉树已置空！\n");
            }
            else printf("二叉树置空失败！\n");
            fflush(stdin); getchar();
            break;
        case 5:
            {
                if(M.length==0)
                {
                    printf("没有二叉树可以判断！\n"); fflush(stdin); getchar();
                    break;
                }
                status s=BiTreeEmpty(L->root);
                if(s==TRUE) printf("二叉树为空！\n");
                if(s==FALSE) printf("二叉树不为空！\n");
                fflush(stdin); getchar();
                break;
            }

        case 6:
            {
                if(M.length==0)
                {
                    printf("没有二叉树可以进行计算！\n"); fflush(stdin); getchar();
                    break;
                }
                int depth=BiTreeDepth(L->root);
                printf("二叉树深度为%d\n",depth);
                fflush(stdin); getchar();
                break;
            }

        case 7:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                TreeNode r=Root(L->root);
                if(r==ERROR) printf("二叉树还没有节点\n");
                else printf("根节点找到，标识为%d,数据为%d\n",r->index,r->grade);
                fflush(stdin); getchar();
                break;
            }

        case 8:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                int e;
                TElemType v;
                printf("元素定位\n输入节点标识:");
                scanf("%d",&e); fflush(stdin);
                v=Value(L->root,e);
                if(v) printf("节点值为%d\n",v);
                else printf("该节点不存在\n");
                fflush(stdin); getchar();
                break;
            }

        case 9:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index,value;
                printf("给节点赋值：\n输入节点标识:");
                scanf("%d",&index); fflush(stdin);
                printf("输入节点值\n");
                scanf("%d",&value); fflush(stdin);
                if(Assign(L->root,index,value)) printf("赋值成功\n");
                else printf("操作失败！\n");
                fflush(stdin); getchar();
                break;
            }

        case 10:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index;
                TreeNode parent;
                printf("查找父节点:\n输入节点标识:");
                scanf("%d",&index); fflush(stdin);
                parent=Parent(L->root,index);
                if(parent) printf("父节点找到，标识为%d，值为%d\n",parent->index,parent->grade);
                else printf("操作失败！\n");
                fflush(stdin); getchar();
                break;
            }

        case 11:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index;
                TreeNode leftc;
                printf("查找左孩子:\n输入节点标识:");
                scanf("%d",&index); fflush(stdin);
                leftc=LeftChild(L->root,index);
                if(leftc) printf("左孩子标识为%d，值为%d\n",leftc->index,leftc->grade);
                else printf("查找失败！\n");
                fflush(stdin);getchar();
                break;
            }

        case 12:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index;
                TreeNode rightc;
                printf("查找右孩子:\n输入节点标识:");
                scanf("%d",&index); fflush(stdin);
                rightc=RightChild(L->root,index);
                if(rightc) printf("右孩子标识为%d，值为%d\n",rightc->index,rightc->grade);
                else printf("查找失败！\n");
                fflush(stdin);getchar();
                break;
            }

        case 13:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index;
                TreeNode lefts;
                printf("查找左兄弟:\n输入节点标识:");
                scanf("%d",&index); fflush(stdin);
                lefts=LeftSibling(L->root,index);
                if(lefts) printf("左兄弟标识为%d，值为%d\n",lefts->index,lefts->grade);
                else printf("查找失败！\n");
                fflush(stdin);getchar();
                break;
            }

        case 14:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index;
                TreeNode rights;
                printf("查找右兄弟:\n输入节点标识:");
                scanf("%d",&index); fflush(stdin);
                rights=RightSibling(L->root,index);
                if(rights) printf("右兄弟标识为%d，值为%d\n",rights->index,rights->grade);
                else printf("查找失败！\n");
                fflush(stdin);getchar();
                break;
            }

        case 15:
            {
                int LR;
                int index;
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                if(M.length==1)
                {
                    printf("当前只有一棵树，插入其自身\n");
                    printf("输入插入节点标识\n"); scanf("%d",&index); fflush(stdin);
                    printf("选择插入为该节点的左子树（0）或右子树（1）\n"); scanf("%d",&LR); fflush(stdin);
                    if(InsertChild(L->root,index,LR,L->root)==OK)
                    {
                        printf("插入成功\n");
                        L->depth=BiTreeDepth(L->root);
                        (L->ver_num)*=2;
                    }
                    else printf("插入失败\n");
                }
                else
                {
                    printf("当前多于一棵树，插入第一棵树\n");
                    printf("输入插入节点标识\n"); scanf("%d",&index); fflush(stdin);
                    printf("选择插入为该节点的左子树（0）或右子树（1）\n"); scanf("%d",&LR); fflush(stdin);
                    if(InsertChild(L->root,index,LR,M.elem->elem->root)==OK)
                    {
                        printf("插入成功\n");
                        L->depth=BiTreeDepth(L->root);
                        L->ver_num=get_ver_num(L->root);
                    }
                    else printf("插入失败\n");
                }
                fflush(stdin);getchar();
                break;
            }

        case 16:
            {
                int index,LR;
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                printf("输入要操作的结点的标识\n");
                scanf("%d",&index); fflush(stdin);
                printf("选择左子树（0）或右子树（1）\n");
                scanf("%d",&LR); fflush(stdin);
                if(DeleteChild(L->root,index,LR)==OK)
                {
                    L->depth=BiTreeDepth(L->root);
                    L->ver_num=get_ver_num(L->root);
                    printf("%s\n",LR?"右子树已删除":"左子树已删除");
                }
                else printf("操作失败\n");
                fflush(stdin);getchar();
                break;
            }

        case 17:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                printf("先序遍历\n");
                if(PreOrderTraverse(L->root,visit)==OK) printf("遍历完成\n");
                else printf("操作失败\n");
                fflush(stdin);getchar();
                break;
            }

        case 18:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                printf("中序遍历\n");
                if(InOrderTraverse(L->root,visit)==OK) printf("遍历完成\n");
                else printf("操作失败\n");
                fflush(stdin);getchar();
                break;
            }
        case 19:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                printf("后序遍历\n");
                if(PostOrderTraverse(L->root,visit)==OK) printf("遍历完成\n");
                else printf("操作失败\n");
                fflush(stdin);getchar();
                break;
            }

        case 20:
            {
                if(M.length==0)
                {
                    printf("没有二叉树！\n"); fflush(stdin); getchar();
                    break;
                }
                printf("层序遍历\n");
                if(LevelOrderTraverse(L->root,visit)==OK) printf("遍历完成\n");
                else printf("操作失败\n");
                fflush(stdin);getchar();
                break;
            }



        case 21:
            {
                int i,j;
                if(M.length==0)
                {
                    printf("当前没有二叉树\n");
                    fflush(stdin); getchar();
                    break;
                }
                if(M.length==1)
                {
                    printf("当前只有1棵二叉树\n");
                    printf("二叉树%d\t名称：%s\t节点数：%d\n",1,(M.elem)->name,(M.elem)->elem->ver_num);
                    fflush(stdin); getchar();
                    break;
                }
                for(i=0;i<=M.length-1;i++)
                {
                    printf("二叉树%d\t名称：%s\t节点数：%d\n",i+1,(M.elem+i)->name,(M.elem+i)->elem->ver_num);
                }
                printf("选择二叉树[1-%d]\n",M.length);
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


