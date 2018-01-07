#include "def.h"


int main()
{
    Treeinfo L; int op=1; char rec;
    ManageList M;
    M.length=0;
    M.listsize=10;
    M.cur=-1;
    printf("�Ƿ���ļ��������ݣ�y/n\n");
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
        printf("    ��ѡ����Ĳ���[0~21]:");
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
                printf("��������ʼ���ɹ���\n");
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
                printf("����������ʧ�ܣ�\n");
                fflush(stdin); getchar();
                break;

            }
            }
        case 2:
            if(M.length==0)
            {
                printf("û�ж��������Դݻ٣�\n"); fflush(stdin); getchar();
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

                    printf("���������ٳɹ���\n");
                }
                else printf("����������ʧ�ܣ�\n");
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

                    printf("���������ٳɹ���\n");

            }

            fflush(stdin); getchar();
            break;

        case 3:
            {
                Tree root;
                if(M.length==0)
                {
                    printf("��ǰû���ѳ�ʼ���Ķ�������\n"); fflush(stdin); getchar();
                    break;
                }
                fflush(stdin);
                printf("�������������У�");
                root=CreateBiTree(L);
                if(root)
                {
                    L->depth=BiTreeDepth(L->root);
                    L->root=root;
                    printf("�����������ɹ�\n");
                }
                else printf("����������ʧ��\n");
                fflush(stdin); getchar();
                break;
            }


        case 4:
            if(M.length==0)
            {
                printf("û�ж����������ÿգ�\n"); fflush(stdin); getchar();
                break;
            }
            if(ClearBiTree(L->root)==OK)
            {
                L->depth=0;
                L->ver_num=0;
                L->root=NULL;
                printf("���������ÿգ�\n");
            }
            else printf("�������ÿ�ʧ�ܣ�\n");
            fflush(stdin); getchar();
            break;
        case 5:
            {
                if(M.length==0)
                {
                    printf("û�ж����������жϣ�\n"); fflush(stdin); getchar();
                    break;
                }
                status s=BiTreeEmpty(L->root);
                if(s==TRUE) printf("������Ϊ�գ�\n");
                if(s==FALSE) printf("��������Ϊ�գ�\n");
                fflush(stdin); getchar();
                break;
            }

        case 6:
            {
                if(M.length==0)
                {
                    printf("û�ж��������Խ��м��㣡\n"); fflush(stdin); getchar();
                    break;
                }
                int depth=BiTreeDepth(L->root);
                printf("���������Ϊ%d\n",depth);
                fflush(stdin); getchar();
                break;
            }

        case 7:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                TreeNode r=Root(L->root);
                if(r==ERROR) printf("��������û�нڵ�\n");
                else printf("���ڵ��ҵ�����ʶΪ%d,����Ϊ%d\n",r->index,r->grade);
                fflush(stdin); getchar();
                break;
            }

        case 8:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                int e;
                TElemType v;
                printf("Ԫ�ض�λ\n����ڵ��ʶ:");
                scanf("%d",&e); fflush(stdin);
                v=Value(L->root,e);
                if(v) printf("�ڵ�ֵΪ%d\n",v);
                else printf("�ýڵ㲻����\n");
                fflush(stdin); getchar();
                break;
            }

        case 9:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index,value;
                printf("���ڵ㸳ֵ��\n����ڵ��ʶ:");
                scanf("%d",&index); fflush(stdin);
                printf("����ڵ�ֵ\n");
                scanf("%d",&value); fflush(stdin);
                if(Assign(L->root,index,value)) printf("��ֵ�ɹ�\n");
                else printf("����ʧ�ܣ�\n");
                fflush(stdin); getchar();
                break;
            }

        case 10:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index;
                TreeNode parent;
                printf("���Ҹ��ڵ�:\n����ڵ��ʶ:");
                scanf("%d",&index); fflush(stdin);
                parent=Parent(L->root,index);
                if(parent) printf("���ڵ��ҵ�����ʶΪ%d��ֵΪ%d\n",parent->index,parent->grade);
                else printf("����ʧ�ܣ�\n");
                fflush(stdin); getchar();
                break;
            }

        case 11:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index;
                TreeNode leftc;
                printf("��������:\n����ڵ��ʶ:");
                scanf("%d",&index); fflush(stdin);
                leftc=LeftChild(L->root,index);
                if(leftc) printf("���ӱ�ʶΪ%d��ֵΪ%d\n",leftc->index,leftc->grade);
                else printf("����ʧ�ܣ�\n");
                fflush(stdin);getchar();
                break;
            }

        case 12:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index;
                TreeNode rightc;
                printf("�����Һ���:\n����ڵ��ʶ:");
                scanf("%d",&index); fflush(stdin);
                rightc=RightChild(L->root,index);
                if(rightc) printf("�Һ��ӱ�ʶΪ%d��ֵΪ%d\n",rightc->index,rightc->grade);
                else printf("����ʧ�ܣ�\n");
                fflush(stdin);getchar();
                break;
            }

        case 13:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index;
                TreeNode lefts;
                printf("�������ֵ�:\n����ڵ��ʶ:");
                scanf("%d",&index); fflush(stdin);
                lefts=LeftSibling(L->root,index);
                if(lefts) printf("���ֵܱ�ʶΪ%d��ֵΪ%d\n",lefts->index,lefts->grade);
                else printf("����ʧ�ܣ�\n");
                fflush(stdin);getchar();
                break;
            }

        case 14:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                TElemType index;
                TreeNode rights;
                printf("�������ֵ�:\n����ڵ��ʶ:");
                scanf("%d",&index); fflush(stdin);
                rights=RightSibling(L->root,index);
                if(rights) printf("���ֵܱ�ʶΪ%d��ֵΪ%d\n",rights->index,rights->grade);
                else printf("����ʧ�ܣ�\n");
                fflush(stdin);getchar();
                break;
            }

        case 15:
            {
                int LR;
                int index;
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                if(M.length==1)
                {
                    printf("��ǰֻ��һ����������������\n");
                    printf("�������ڵ��ʶ\n"); scanf("%d",&index); fflush(stdin);
                    printf("ѡ�����Ϊ�ýڵ����������0������������1��\n"); scanf("%d",&LR); fflush(stdin);
                    if(InsertChild(L->root,index,LR,L->root)==OK)
                    {
                        printf("����ɹ�\n");
                        L->depth=BiTreeDepth(L->root);
                        (L->ver_num)*=2;
                    }
                    else printf("����ʧ��\n");
                }
                else
                {
                    printf("��ǰ����һ�����������һ����\n");
                    printf("�������ڵ��ʶ\n"); scanf("%d",&index); fflush(stdin);
                    printf("ѡ�����Ϊ�ýڵ����������0������������1��\n"); scanf("%d",&LR); fflush(stdin);
                    if(InsertChild(L->root,index,LR,M.elem->elem->root)==OK)
                    {
                        printf("����ɹ�\n");
                        L->depth=BiTreeDepth(L->root);
                        L->ver_num=get_ver_num(L->root);
                    }
                    else printf("����ʧ��\n");
                }
                fflush(stdin);getchar();
                break;
            }

        case 16:
            {
                int index,LR;
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                printf("����Ҫ�����Ľ��ı�ʶ\n");
                scanf("%d",&index); fflush(stdin);
                printf("ѡ����������0������������1��\n");
                scanf("%d",&LR); fflush(stdin);
                if(DeleteChild(L->root,index,LR)==OK)
                {
                    L->depth=BiTreeDepth(L->root);
                    L->ver_num=get_ver_num(L->root);
                    printf("%s\n",LR?"��������ɾ��":"��������ɾ��");
                }
                else printf("����ʧ��\n");
                fflush(stdin);getchar();
                break;
            }

        case 17:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                printf("�������\n");
                if(PreOrderTraverse(L->root,visit)==OK) printf("�������\n");
                else printf("����ʧ��\n");
                fflush(stdin);getchar();
                break;
            }

        case 18:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                printf("�������\n");
                if(InOrderTraverse(L->root,visit)==OK) printf("�������\n");
                else printf("����ʧ��\n");
                fflush(stdin);getchar();
                break;
            }
        case 19:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                printf("�������\n");
                if(PostOrderTraverse(L->root,visit)==OK) printf("�������\n");
                else printf("����ʧ��\n");
                fflush(stdin);getchar();
                break;
            }

        case 20:
            {
                if(M.length==0)
                {
                    printf("û�ж�������\n"); fflush(stdin); getchar();
                    break;
                }
                printf("�������\n");
                if(LevelOrderTraverse(L->root,visit)==OK) printf("�������\n");
                else printf("����ʧ��\n");
                fflush(stdin);getchar();
                break;
            }



        case 21:
            {
                int i,j;
                if(M.length==0)
                {
                    printf("��ǰû�ж�����\n");
                    fflush(stdin); getchar();
                    break;
                }
                if(M.length==1)
                {
                    printf("��ǰֻ��1�ö�����\n");
                    printf("������%d\t���ƣ�%s\t�ڵ�����%d\n",1,(M.elem)->name,(M.elem)->elem->ver_num);
                    fflush(stdin); getchar();
                    break;
                }
                for(i=0;i<=M.length-1;i++)
                {
                    printf("������%d\t���ƣ�%s\t�ڵ�����%d\n",i+1,(M.elem+i)->name,(M.elem+i)->elem->ver_num);
                }
                printf("ѡ�������[1-%d]\n",M.length);
                scanf("%d",&j); fflush(stdin);
                L=(M.elem+j-1)->elem;
                M.cur=j-1;
                printf("�л��ɹ�\n");
                fflush(stdin); getchar();
                break;

            }

        case 0:
         break;
	}
  }
  char choose;
  printf("�Ƿ񱣴����ݵ��ļ���\ty/n:"); fflush(stdin);
  scanf("%c",&choose); fflush(stdin);
  printf("\n");
  if(choose=='y') save(&M);
  printf("��ӭ�´���ʹ�ñ�ϵͳ��\n\n---�س����˳�---\n");
  getchar();
  return 0;
}


