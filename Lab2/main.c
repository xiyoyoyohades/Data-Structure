#include "def.h"


int main()
{
    LinkList* L; int op=1; char rec;
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
        printf("    ��ѡ����Ĳ���[0~13]:");
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
                printf("���Ա����ɹ���\n");
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
                printf("���Ա���ʧ�ܣ�\n");
                fflush(stdin); getchar();
                break;

            }
            }
        case 2:
            if(M.length==0)
            {
                printf("û�б���Դݻ٣�\n"); fflush(stdin); getchar();
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

                printf("���Ա����ٳɹ���\n");
            }
            else printf("���Ա�����ʧ�ܣ�\n");
            fflush(stdin); getchar();
            break;
        case 3:
            if(M.length==0)
            {
                printf("û�б�����ÿգ�\n"); fflush(stdin); getchar();
                break;
            }
            if(ClearList(L)==OK) printf("���Ա����ÿգ�\n");
            else printf("���Ա��ÿ�ʧ�ܣ�\n");
            fflush(stdin); getchar();
            break;
        case 4:
            {
                if(M.length==0)
                {
                    printf("û�б�����жϣ�\n"); fflush(stdin); getchar();
                    break;
                }
                status s=ListEmpty(L);
                if(s==-1) printf("���Ա����ڣ�\n");
                if(s==TRUE) printf("���Ա�Ϊ�ձ�\n");
                if(s==FALSE) printf("���Ա�Ϊ�գ�\n");
                fflush(stdin); getchar();
                break;
            }

        case 5:
            {
                if(M.length==0)
                {
                    printf("û�б���Խ��м��㣡\n"); fflush(stdin); getchar();
                    break;
                }
                int length=ListLength(L);
                if(length==-1) printf("���Ա����ڣ�\n");
                else printf("���Ա�Ԫ�ظ���Ϊ%d��\n",length);
                fflush(stdin); getchar();
                break;
            }

        case 6:
            {
                if(M.length==0)
                {
                    printf("û�б�\n"); fflush(stdin); getchar();
                    break;
                }
                int i;
                ElemType e;
                printf("��i��Ԫ�ص�ֵ\n����i:");
                scanf("%d",&i); fflush(stdin);
                if(GetElem(L,i,&e)==OK) printf("��%d��Ԫ�ص�ֵΪ%d\n",i,e);
                else printf("������Ԫ�ز�����\n");
                fflush(stdin); getchar();
                break;
            }

        case 7:
            {
                if(M.length==0)
                {
                    printf("û�б�\n"); fflush(stdin); getchar();
                    break;
                }
                ElemType e;
                int i;
                printf("Ԫ�ض�λ\n����Ԫ��e:");
                scanf("%d",&e); fflush(stdin);
                i=LocateElem(L,e,compare);
                if(i) printf("eԪ��λ��Ϊ%d\n",i);
                else printf("����Ԫ�ز�����\n");
                fflush(stdin); getchar();
                break;
            }

        case 8:
            {
                if(M.length==0)
                {
                    printf("û�б�\n"); fflush(stdin); getchar();
                    break;
                }
                ElemType pre_e,cur;
                printf("Ԫ��ǰ������\n����Ԫ��cur:");
                scanf("%d",&cur); fflush(stdin);
                if(PriorElem(L,cur,&pre_e)==OK) printf("Ԫ��cur��ǰ��Ԫ��Ϊ%d\n",pre_e);
                else printf("����ʧ�ܣ�\n");
                fflush(stdin); getchar();
                break;
            }

        case 9:
            {
                if(M.length==0)
                {
                    printf("û�б�\n"); fflush(stdin); getchar();
                    break;
                }
                ElemType next_e,cur;
                printf("Ԫ�غ�̲���:\n����Ԫ��cur:");
                scanf("%d",&cur); fflush(stdin);
                if(NextElem(L,cur,&next_e)==OK) printf("Ԫ��cur�ĺ��Ԫ��Ϊ%d\n",next_e);
                else printf("����ʧ�ܣ�\n");
                fflush(stdin); getchar();
                break;
            }

        case 10:
            {
                if(M.length==0)
                {
                    printf("û�б�\n"); fflush(stdin); getchar();
                    break;
                }
                int i;
                ElemType e;
                printf("�ڵ�i��Ԫ��֮ǰ����Ԫ��e\n����i:");
                scanf("%d",&i); fflush(stdin);
                printf("����Ԫ��e\n");
                scanf("%d",&e); fflush(stdin);
                if(ListInsert(L,i,e)==OK) printf("Ԫ�ز���ɹ���\n");
                else printf("����ʧ�ܣ�\n");
                fflush(stdin);getchar();
                break;
            }

        case 11:
            {
                if(M.length==0)
                {
                    printf("û�б�\n"); fflush(stdin); getchar();
                    break;
                }
                int i;
                ElemType e;
                printf("ɾ����i��Ԫ��\n����i:");
                scanf("%d",&i); fflush(stdin);
                if(ListDelete(L,i,&e)==OK) printf("Ԫ��ɾ���ɹ�����%d��Ԫ��ֵΪ%d\n",i,e);
                else printf("ɾ��ʧ�ܣ�\n");
                fflush(stdin); getchar();
                break;
            }

        case 12:
            {
                if(M.length==0)
                {
                    printf("û�б�\n"); fflush(stdin); getchar();
                    break;
                }
                if(!ListTraverse(L,visit)) printf("���Ա��ǿձ�\n");
                else printf("\n�������\n");
                fflush(stdin); getchar();
                break;
            }

        case 13:
            {
                int i,j;
                if(M.length==0)
                {
                    printf("��ǰû�����Ա�\n");
                    fflush(stdin); getchar();
                    break;
                }
                if(M.length==1)
                {
                    printf("��ǰֻ��1�����Ա�\n");
                    printf("��%d\t���ƣ�%s\t���ȣ�%d\n",1,(M.elem)->name,(M.elem)->elem->length);
                    fflush(stdin); getchar();
                    break;
                }
                for(i=0;i<=M.length-1;i++)
                {
                    printf("��%d\t���ƣ�%s\t���ȣ�%d\n",i+1,(M.elem+i)->name,(M.elem+i)->elem->length);
                }
                printf("ѡ�����Ա�[1-%d]\n",M.length);
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


