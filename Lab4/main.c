#include "def.h"


int main()
{
    Graph g; int op=1; char rec;
    ManageList M;
    M.length=0;
    M.listsize=10;
    M.cur=-1;
    printf("是否从文件读入数据？y/n\n");
    scanf("%c",&rec); fflush(stdin);
    if(rec=='y') recover(&M,&g);
    else M.elem=(ListInfo*)malloc(sizeof(ListInfo)*10);

    while(op)
    {
        system("cls");	printf("\n\n");
        printf("      Menu for Graph On Adjacency List \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. CreateGraph       11. DeleteArc  \n");
        printf("    	  2. DestroyGraph      12. DFSTraverse\n");
        printf("    	  3. LocateVex         13. BFSTraverse\n");
        printf("    	  4. GetVex                           \n");
        printf("    	  5. PutVex                           \n");
        printf("    	  6. FirstAdjVex                      \n");
        printf("    	  7. NextAdjVex                       \n");
        printf("    	  8. InsertVex                        \n");
        printf("    	  9. DeleteVex                        \n");
        printf("    	 10. InsertArc                        \n");
        printf("                               14. switch Graph\n");
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
            M.elem[M.length].elem=NULL;
            g=M.elem[M.length].elem;
            g=CreateGraph(g);
            if(g)
            {
                printf("create success！\n");
                itoa(M.length+1,M.elem[M.length].name,10);
                M.elem[M.length].elem=g;
                ++(M.length);
                printf("%d\n",M.length);
                M.cur=M.length-1;
                fflush(stdin); getchar();
                break;

            }
            else
            {
                free(g);
                M.elem[M.length].elem=NULL;
                printf("fail to create graph！\n");
                fflush(stdin); getchar();
                break;

            }
            }
        case 2:
            if(M.length==0)
            {
                printf("no graph to destroy！\n"); fflush(stdin); getchar();
                break;
            }
            if(g)
            {
                if(DestroyGraph(g)==OK)
                {
                    int i;
                    for(i=M.cur;i<M.length;i++)
                    {
                        M.elem[i]=M.elem[i+1];
                    }
                    M.length--;
                    M.cur=0;
                    g=M.elem[0].elem;

                    printf("destroy success！\n");
                }
                else printf("destroy failed！\n");
            }
           // else
            //{
                   // int i;
                    //free(L);
                   //for(i=M.cur;i<M.length;i++)
                   // {
                       // M.elem[i]=M.elem[i+1];
                    //}
                    //M.length--;
                    //M.cur=0;
                    //L=M.elem[0].elem;

                   // printf("二叉树销毁成功！\n");

            //}

            fflush(stdin); getchar();
            break;

        case 3:
            {

                if(M.length==0)
                {
                    printf("no created graph！\n"); fflush(stdin); getchar();
                    break;
                }
                Vertex value;
                int i;

                printf("Locate\n input the value of the vertex：");
                fflush(stdin);
                scanf("%c",&value); fflush(stdin);
                i=LocateVex(g,value);
                if(i+1)
                {
                    printf("the location is %d\n",i);
                }
                else printf("fail to find the vertex\n");
                fflush(stdin); getchar();
                break;
            }


        case 4:
            if(M.length==0)
            {
                printf("no created graph！\n"); fflush(stdin); getchar();
                break;
            }
            Vertex value;
            int i;

            printf("get the value\n input the number of the vertex：");
            scanf("%d",&i); fflush(stdin);
            value=GetVex(g,i);

            if(value!='#')
            {
                printf("the value is %c！\n",value);
            }
            else printf("no such vertex！\n");
            fflush(stdin); getchar();
            break;
        case 5:
            {
                if(M.length==0)
                {
                    printf("no created graph！\n"); fflush(stdin); getchar();
                    break;
                }
                Vertex value;
                int i;

                printf("assign\n input the number and the value of the vertex：");
                scanf("%d%c",&i,&value); fflush(stdin);
                if(PutVex(g,i,value)==OK)
                {
                    printf("done\n");
                }
                else printf("fail to find the vertex\n");
                fflush(stdin); getchar();
                break;
            }

        case 6:
            {
                if(M.length==0)
                {
                    printf("no created graph！\n"); fflush(stdin); getchar();
                    break;
                }
                int v,u;
                printf("find the first adjvex\ninput the number of the vertex:");
                scanf("%d",&v); fflush(stdin);
                u=FirstAdjVex(g,v);
                if(u==-2) printf("no such vertex\n");
                if(u==-1) printf("the vertex has no adjvex\n");
                if(u>=0) printf("the location of the first adjvex is %d\n",u);
                fflush(stdin); getchar();
                break;
            }

        case 7:
            {
                if(M.length==0)
                {
                    printf("no created graph！\n"); fflush(stdin); getchar();
                    break;
                }
                int v,w,u;
                printf("find the next adjvex\ninput the number of the vertex and the last vertex:");
                scanf("%d%d",&v,&w); fflush(stdin);
                u=NextAdjVex(g,v,w);
                if(u>=0) printf("the location of the next adjvex is %d\n",u);
                else printf("failed\n");
                fflush(stdin); getchar();
                break;
            }

        case 8:
            {
                if(M.length==0)
                {
                    printf("no created graph！\n"); fflush(stdin); getchar();
                    break;
                }
                Vertex value;
                printf("insert a vertex\ninput the value of the vertex:");
                fflush(stdin);
                scanf("%c",&value); fflush(stdin);
                if(InsertVex(g,value)==OK)
                {
                    printf("insertion done\n");
                }
                else printf("failed\n");
                fflush(stdin); getchar();
                break;
            }

        case 9:
            {
                if(M.length==0)
                {
                    printf("no created graph！\n"); fflush(stdin); getchar();
                    break;
                }
                int v;
                printf("delete a vertex\ninput the number of the vertex:");
                fflush(stdin);
                scanf("%d",&v); fflush(stdin);
                if(DeleteVex(g,v)==OK)
                {
                    printf("deleted\n");
                }
                else printf("failed\n");
                fflush(stdin); getchar();
                break;
            }

        case 10:
            {
                if(M.length==0)
                {
                    printf("no created graph！\n"); fflush(stdin); getchar();
                    break;
                }
                int v,w,result;
                printf("insert an arc\ninput the number of the tail and the head:");
                fflush(stdin);
                scanf("%d%d",&v,&w); fflush(stdin);
                result=InsertArc(g,v,w);

                if(result==OK)
                {
                    printf("insertion done\n");
                }
                else if(result==ERROR) printf("no such vertex\n");
                else printf("the arc is already there\n");
                fflush(stdin); getchar();
                break;
            }

        case 11:
            {
                if(M.length==0)
                {
                    printf("no created graph！\n"); fflush(stdin); getchar();
                    break;
                }
                int v,w,result;
                printf("delete an arc\ninput the number of the tail and the head:");
                fflush(stdin);
                scanf("%d%d",&v,&w); fflush(stdin);
                result=DeleteArc(g,v,w);

                if(result==OK)
                {
                    printf("deleted\n");
                }
                if(result==ERROR) printf("failed\n");
                fflush(stdin); getchar();
                break;
            }

        case 12:
            {
                if(M.length==0)
                {
                    printf("no created graph！\n"); fflush(stdin); getchar();
                    break;
                }

                printf("DFS\n");

                if(DFSTraverse(g,visit)==OK)
                {
                    printf("done\n");
                }
                else printf("failed\n");
                fflush(stdin); getchar();
                break;
            }

        case 13:
            {
                if(M.length==0)
                {
                    printf("no created graph！\n"); fflush(stdin); getchar();
                    break;
                }
                printf("BFS\n");

                if(BFSTraverse(g,visit)==OK)
                {
                    printf("done\n");
                }
                else printf("failed\n");
                fflush(stdin); getchar();
                break;
            }


        case 14:
            {
                int i,j,type;
                if(M.length==0)
                {
                    printf("no created graph\n");
                    fflush(stdin); getchar();
                    break;
                }
                if(M.length==1)
                {
                    printf("there is only one graph\n");
                    printf("Graph%d\tname：%s\tvexnum：%d  arcnum:%d\t",1,(M.elem)->name,(M.elem)->elem->vexnum,(M.elem)->elem->arcnum);
                    type=(int)(M.elem)->elem->kind;
                    printf("Type:%s\n",type==0?"DG":(type==1?"DN":(type==2?"UDG":"UDN")));
                    fflush(stdin); getchar();
                    break;
                }
                for(i=0;i<=M.length-1;i++)
                {
                    printf("Graph%d\tname：%s\tvexnum：%d  arcnum:%d\t",i+1,(M.elem+i)->name,(M.elem+i)->elem->vexnum,(M.elem+i)->elem->arcnum);
                    type=(int)(M.elem+i)->elem->kind;
                    printf("Type:%s\n",type==0?"DG":(type==1?"DN":(type==2?"UDG":"UDN")));
                }
                printf("choose graph[1-%d]\n",M.length);
                scanf("%d",&j); fflush(stdin);
                g=(M.elem+j-1)->elem;
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



