#include "def.h"
int visited[MAX_VERTEX_NUM];
Graph CreateGraph(Graph g)
{
    int type;
    int i,k;
    int h_local,t_local,location1,location2;
    Vertex tail,head,vertex1,vertex2;
    Arcinfo weight;
    p_ArcNode arc_now=NULL;
    p_ArcNode arc_now1=NULL;
    p_ArcNode arc_now2=NULL;
    p_ArcNode arc_end[MAX_VERTEX_NUM]={NULL};

    g=(Graph)malloc(sizeof(ALGraph)); if(!g) exit(OVERFLOW);
    printf("input the type of the graph,0 as DG,1 as DN,2 as UDG,3 as UDN\n");
    scanf("%d",&type); fflush(stdin);  g->kind=(GraphKind)type;

    printf("input the number of vertex(no more than 20) and arc\n");
    scanf("%d%d",&(g->vexnum),&(g->arcnum)); getchar();


    printf("now input the value of all the vertex\n");
    for(i=0;i<g->vexnum;i++)
    {
        printf("vertex %d:\n",i);
        scanf("%c",&((g->vertices[i]).data)); fflush(stdin);
        (g->vertices[i]).firstarc=NULL;
    }
    printf("%d\n",g->vexnum);


    //DG
    if(g->kind==DG)
    {
        printf("The graph is a DG, input the arcs with tails and heads\n");
        for(k=0;k<g->arcnum;k++)
        {
            scanf("%c",&tail); getchar();
            scanf("%c",&head); getchar();
            h_local=LocateVex(g,head);
            t_local=LocateVex(g,tail);
     //       printf("%c%c%c\n%c%c\n",g->vertices[0].data,g->vertices[1].data,g->vertices[2].data,head,tail);
     //       printf("%d%d\n",h_local,t_local);
            if(h_local==-1||t_local==-1)
            {
                printf("no such vertex.\n");
                k--;
                continue;
            }
            arc_now=(p_ArcNode)malloc(sizeof(ArcNode)); if(!arc_now) exit(OVERFLOW);
            if(g->vertices[t_local].firstarc==NULL)
            {
                g->vertices[t_local].firstarc=arc_now;
                arc_now->adjvex=h_local;
                arc_now->weight=-1;
                arc_now->nextarc=NULL;
                arc_end[t_local]=arc_now;
            }
            else
            {
                arc_end[t_local]->nextarc=arc_now;
                arc_now->adjvex=h_local;
                arc_now->weight=-1;
                arc_now->nextarc=NULL;
                arc_end[t_local]=arc_now;
            }
            printf("%d arcs done.\n",k+1);
        }
        printf("%d arcs inputed\n",g->arcnum);

    }

    //DN
    if(g->kind==DN)
    {
        printf("The graph is a DN, input the arcs with tails, heads and weight\n");
        for(k=0;k<g->arcnum;k++)
        {
            scanf("%c",&tail); getchar();
            scanf("%c",&head); getchar();
            scanf("%d",&weight); getchar();
            h_local=LocateVex(g,head);
            t_local=LocateVex(g,tail);
            if(h_local==-1||t_local==-1)
            {
                printf("no such vertex.\n");
                k--;
                continue;
            }
            arc_now=(p_ArcNode)malloc(sizeof(ArcNode)); if(!arc_now) exit(OVERFLOW);
            if(g->vertices[t_local].firstarc==NULL)
            {
                g->vertices[t_local].firstarc=arc_now;
                arc_now->adjvex=h_local;
                arc_now->weight=weight;
                arc_now->nextarc=NULL;
                arc_end[t_local]=arc_now;
            }
            else
            {
                arc_end[t_local]->nextarc=arc_now;
                arc_now->adjvex=h_local;
                arc_now->weight=weight;
                arc_now->nextarc=NULL;
                arc_end[t_local]=arc_now;
            }
            printf("%d arcs done.\n",k+1);
        }
        printf("%d arcs inputed\n",g->arcnum);
    }

    //UDG
    if(g->kind==UDG)
    {
        printf("The graph is a UDG, input the arcs with two linked vertexes\n");
        for(k=0;k<g->arcnum;k++)
        {
            scanf("%c",&vertex1); getchar();
            scanf("%c",&vertex2); getchar();
            location1=LocateVex(g,vertex1);
            location2=LocateVex(g,vertex2);
            if(location1==-1||location2==-1)
            {
                printf("no such vertex.\n");
                k--;
                continue;
            }
            arc_now1=(p_ArcNode)malloc(sizeof(ArcNode)); if(!arc_now1) exit(OVERFLOW);
            if(g->vertices[location1].firstarc==NULL)
            {
                g->vertices[location1].firstarc=arc_now1;
                arc_now1->adjvex=location2;
                arc_now1->weight=-1;
                arc_now1->nextarc=NULL;
                arc_end[location1]=arc_now1;
            }
            else
            {
                arc_end[location1]->nextarc=arc_now1;
                arc_now1->adjvex=location2;
                arc_now1->weight=-1;
                arc_now1->nextarc=NULL;
                arc_end[location1]=arc_now1;
            }

            arc_now2=(p_ArcNode)malloc(sizeof(ArcNode)); if(!arc_now2) exit(OVERFLOW);
            if(g->vertices[location2].firstarc==NULL)
            {
                g->vertices[location2].firstarc=arc_now2;
                arc_now2->adjvex=location1;
                arc_now2->weight=-1;
                arc_now2->nextarc=NULL;
                arc_end[location2]=arc_now2;
            }
            else
            {
                arc_end[location2]->nextarc=arc_now2;
                arc_now2->adjvex=location1;
                arc_now2->weight=-1;
                arc_now2->nextarc=NULL;
                arc_end[location2]=arc_now2;
            }
            printf("%d arcs done.\n",k+1);
        }
        printf("%d arcs inputed\n",g->arcnum);
    }

    //UDN
    if(g->kind==UDN)
    {
        printf("The graph is a UDN, input the arcs with two linked vertexes and weight\n");
        for(k=0;k<g->arcnum;k++)
        {
            scanf("%c",&vertex1); getchar();
            scanf("%c",&vertex2); getchar();
            scanf("%d",&weight); getchar();
            location1=LocateVex(g,vertex1);
            location2=LocateVex(g,vertex2);
            if(location1==-1||location2==-1)
            {
                printf("no such vertex.\n");
                k--;
                continue;
            }
            arc_now1=(p_ArcNode)malloc(sizeof(ArcNode)); if(!arc_now1) exit(OVERFLOW);
            if(g->vertices[location1].firstarc==NULL)
            {
                g->vertices[location1].firstarc=arc_now1;
                arc_now1->adjvex=location2;
                arc_now1->weight=weight;
                arc_now1->nextarc=NULL;
                arc_end[location1]=arc_now1;
            }
            else
            {
                arc_end[location1]->nextarc=arc_now1;
                arc_now1->adjvex=location2;
                arc_now1->weight=weight;
                arc_now1->nextarc=NULL;
                arc_end[location1]=arc_now1;
            }

            arc_now2=(p_ArcNode)malloc(sizeof(ArcNode)); if(!arc_now2) exit(OVERFLOW);
            if(g->vertices[location2].firstarc==NULL)
            {
                g->vertices[location2].firstarc=arc_now2;
                arc_now2->adjvex=location1;
                arc_now2->weight=weight;
                arc_now2->nextarc=NULL;
                arc_end[location2]=arc_now2;
            }
            else
            {
                arc_end[location2]->nextarc=arc_now2;
                arc_now2->adjvex=location1;
                arc_now2->weight=weight;
                arc_now2->nextarc=NULL;
                arc_end[location2]=arc_now2;
            }
            printf("%d arcs done.\n",k+1);
        }
        printf("%d arcs inputed\n",g->arcnum);
    }
    return g;
}



status DestroyGraph(Graph g)
{
    int i;
    p_ArcNode pre=NULL;
    p_ArcNode cur=NULL;

    for(i=0;i<g->arcnum;i++)
    {
        cur=g->vertices[i].firstarc;
        if(!cur)
        {
            continue;
        }
        while(cur)
        {
            pre=cur;
            cur=cur->nextarc;
            free(pre);
        }
    }
    free(g);
    return OK;

}


int LocateVex(Graph g,Vertex u)
{
    int i;
    for(i=0;i<g->vexnum;i++)
    {
        if(g->vertices[i].data==u) return i;
        else continue;
    }
    return -1;
}


Vertex GetVex(Graph g,int v)
{
    if(v<0||v>=g->vexnum) return '#';
    else return g->vertices[v].data;
}


status PutVex(Graph g,int v,Vertex value)
{
    if(v<0||v>=g->vexnum) return ERROR;
    else
    {
        g->vertices[v].data=value;
        return OK;
    }
}


int FirstAdjVex(Graph g,int v)
{
    if(v<0||v>=g->vexnum) return -2;
    else
    {
        if(g->vertices[v].firstarc)
        {
            return g->vertices[v].firstarc->adjvex;
        }
        else return -1;

    }

}


int NextAdjVex(Graph g,int v, int w)
{
    if(v<0||v>=g->vexnum) return -2;
    if(w<0||w>=g->vexnum) return -2;
    p_ArcNode cur=g->vertices[v].firstarc;
 //   p_ArcNode pre=NULL;
    while(cur)
    {
        if(cur->adjvex==w) break;
        else cur=cur->nextarc;
    }
    if(cur)
    {
        if(cur->nextarc) return cur->nextarc->adjvex;
        else return -1;
    }
    else return -2;
}

status InsertVex(Graph g,Vertex v)
{
    if(g->vexnum>=MAX_VERTEX_NUM) return ERROR;
    g->vertices[g->vexnum].data=v;
    g->vertices[g->vexnum].firstarc=NULL;
    (g->vexnum)++;
    return OK;
}

status DeleteVex(Graph g,int v)
{
    p_ArcNode arc=NULL;
    p_ArcNode pre=NULL;
    int arc_deleted=0;
    int i;
    if(v<0||v>=g->vexnum) return ERROR;

    if(g->kind==DN||g->kind==DG)
    {
        arc=g->vertices[v].firstarc;
        while(arc)
        {
            pre=arc;
            arc=arc->nextarc;
            free(pre);
            arc_deleted++;
        }
        printf("arc_deleted=%d\n",arc_deleted);
        g->vertices[v].firstarc=NULL;
        for(i=0;i<g->vexnum;i++)
        {
            arc=g->vertices[i].firstarc;
            while(arc)
            {
                printf("%p\n",arc);
                if(g->vertices[i].firstarc==arc)
                {
                    if(arc->adjvex==v)
                    {
                        pre=arc;
                        arc=arc->nextarc;
                        free(pre);
                        arc_deleted++;
                        g->vertices[i].firstarc=arc;

                    }
                    else
                    {
                        pre=arc;
                        arc=arc->nextarc;

                    }
                }
                else
                {
                    if(arc->adjvex==v)
                    {
                        arc=arc->nextarc;
                        free(pre->nextarc);
                        arc_deleted++;
                        pre->nextarc=arc;

                    }
                    else
                    {
                        arc=arc->nextarc;
                        pre=pre->nextarc;

                    }
                }
            }
        }
    }

    if(g->kind==UDG||g->kind==UDN)
    {
        arc=g->vertices[v].firstarc;
        while(arc)
        {
            pre=arc;
            arc=arc->nextarc;
            free(pre);

            arc_deleted++;
        }
        g->vertices[v].firstarc=NULL;
        for(i=0;i<g->vexnum;i++)
        {
            arc=g->vertices[i].firstarc;
            while(arc)
            {
                if(g->vertices[i].firstarc==arc)
                {
                    if(arc->adjvex==v)
                    {
                        pre=arc;
                        arc=arc->nextarc;
                        free(pre);
                        g->vertices[i].firstarc=arc;
                    }
                    else
                    {
                        pre=arc;
                        arc=arc->nextarc;
                    }
                }
                else
                {
                    if(arc->adjvex==v)
                    {
                        arc=arc->nextarc;
                        free(pre->nextarc);
                        pre->nextarc=arc;
                    }
                    else
                    {
                        arc=arc->nextarc;
                        pre=pre->nextarc;
                    }
                }
            }
        }

    }


    for(i=v+1;i<=g->vexnum;i++)
    {
        g->vertices[i-1]=g->vertices[i];
    }
    g->arcnum-=arc_deleted;
    g->vexnum--;

    p_ArcNode now=NULL;
    for(i=0;i<g->vexnum;i++)
    {
        now=g->vertices[i].firstarc;
        while(now)
        {
            if(now->adjvex>v) now->adjvex--;
            now=now->nextarc;
        }

    }
    printf("arc_deleted=%d\n",arc_deleted);

    return OK;
}

status InsertArc(Graph g,int v,int w)
{
    if(v<0||v>=g->vexnum) return ERROR;
    if(w<0||w>=g->vexnum) return ERROR;

    p_ArcNode new_arc=NULL;
    p_ArcNode end_arc=NULL;
    int weight;

    if(g->kind==DG||g->kind==DN)
    {
        end_arc=g->vertices[v].firstarc;
        while(end_arc)
        {
            if(end_arc->adjvex==w) return INFEASIBLE;
            else
            {
                if(end_arc->nextarc==NULL) break;
                else
                {
                    end_arc=end_arc->nextarc;
                    continue;
                }
            }

        }
        if(end_arc)
        {
            new_arc=(p_ArcNode)malloc(sizeof(ArcNode));
            end_arc->nextarc=new_arc;
            new_arc->adjvex=w;
            new_arc->nextarc=NULL;
            if(g->kind==DG) new_arc->weight=-1;
            else
            {
                printf("you are adding an arc in a DN, please enter the weight\n");
                scanf("%d",&weight); fflush(stdin);
                new_arc->weight=weight;
            }

        }
        else
        {
            new_arc=(p_ArcNode)malloc(sizeof(ArcNode));
            g->vertices[v].firstarc=new_arc;
            new_arc->adjvex=w;
            new_arc->nextarc=NULL;
            if(g->kind==DG) new_arc->weight=-1;
            else
            {
                printf("you are adding an arc in a DN, please enter the weight\n");
                scanf("%d",&weight); fflush(stdin);
                new_arc->weight=weight;
            }
        }
    }

    if(g->kind==UDN||g->kind==UDG)
    {
        end_arc=g->vertices[v].firstarc;
        while(end_arc)
        {
            if(end_arc->adjvex==w) return INFEASIBLE;
            else
            {
                if(end_arc->nextarc==NULL) break;
                else
                {
                    end_arc=end_arc->nextarc;
                    continue;
                }
            }
        }
        if(end_arc)
        {
            new_arc=(p_ArcNode)malloc(sizeof(ArcNode));
            end_arc->nextarc=new_arc;
            new_arc->adjvex=w;
            new_arc->nextarc=NULL;
            if(g->kind==UDG) new_arc->weight=-1;
            else
            {
                printf("you are adding an arc in an UDN, please enter the weight\n");
                scanf("%d",&weight); fflush(stdin);
                new_arc->weight=weight;
            }

        }
        if(!end_arc)
        {
            new_arc=(p_ArcNode)malloc(sizeof(ArcNode));
            g->vertices[v].firstarc=new_arc;
            new_arc->adjvex=w;
            new_arc->nextarc=NULL;
            if(g->kind==UDG) new_arc->weight=-1;
            else
            {
                printf("you are adding an arc in an UDN, please enter the weight\n");
                scanf("%d",&weight); fflush(stdin);
                new_arc->weight=weight;
            }
        }

        end_arc=g->vertices[w].firstarc;
        while(end_arc)
        {
            if(end_arc->adjvex==v) return INFEASIBLE;
            else
            {
                if(end_arc->nextarc==NULL) break;
                else
                {
                    end_arc=end_arc->nextarc;
                    continue;
                }
            }
        }
        if(end_arc)
        {
            new_arc=(p_ArcNode)malloc(sizeof(ArcNode));
            end_arc->nextarc=new_arc;
            new_arc->adjvex=v;
            new_arc->nextarc=NULL;
            if(g->kind==UDG) new_arc->weight=-1;
            else new_arc->weight=weight;
        }
        if(!end_arc)
        {
            new_arc=(p_ArcNode)malloc(sizeof(ArcNode));
            g->vertices[w].firstarc=new_arc;
            new_arc->adjvex=v;
            new_arc->nextarc=NULL;
            if(g->kind==UDG) new_arc->weight=-1;
            else new_arc->weight=weight;
        }

    }
    g->arcnum++;
    return OK;

}

status DeleteArc(Graph g,int v,int w)
{
    if(v<0||v>=g->vexnum) return ERROR;
    if(w<0||w>=g->vexnum) return ERROR;

    p_ArcNode arc=NULL;
    p_ArcNode pre=NULL;

    if(g->kind==DG||g->kind==DN)
    {
            arc=g->vertices[v].firstarc;
            while(arc)
            {
                if(g->vertices[v].firstarc==arc)
                {
                    if(arc->adjvex==w)
                    {
                        pre=arc;
                        arc=arc->nextarc;
                        free(pre);
                        g->vertices[v].firstarc=arc;
                        break;
                    }
                    else
                    {
                        pre=arc;
                        arc=arc->nextarc;
                        continue;
                    }
                }
                else
                {
                    if(arc->adjvex==w)
                    {
                        arc=arc->nextarc;
                        free(pre->nextarc);
                        pre->nextarc=arc;
                        break;
                    }
                    else
                    {
                        arc=arc->nextarc;
                        pre=pre->nextarc;
                        continue;
                    }
                }
            }


    }

    if(g->kind==UDG||g->kind==UDN)
    {
            arc=g->vertices[w].firstarc;
            while(arc)
            {
                if(g->vertices[w].firstarc==arc)
                {
                    if(arc->adjvex==v)
                    {
                        pre=arc;
                        arc=arc->nextarc;
                        free(pre);
                        g->vertices[w].firstarc=arc;
                        break;
                    }
                    else
                    {
                        pre=arc;
                        arc=arc->nextarc;
                        continue;
                    }
                }
                else
                {
                    if(arc->adjvex==v)
                    {
                        arc=arc->nextarc;
                        free(pre->nextarc);
                        pre->nextarc=arc;
                        break;
                    }
                    else
                    {
                        arc=arc->nextarc;
                        pre=pre->nextarc;
                        continue;
                    }
                }
            }



            arc=g->vertices[v].firstarc;
            while(arc)
            {
                if(g->vertices[v].firstarc==arc)
                {
                    if(arc->adjvex==w)
                    {
                        pre=arc;
                        arc=arc->nextarc;
                        free(pre);
                        g->vertices[v].firstarc=arc;
                        break;
                    }
                    else
                    {
                        pre=arc;
                        arc=arc->nextarc;
                        continue;
                    }
                }
                else
                {
                    if(arc->adjvex==w)
                    {
                        arc=arc->nextarc;
                        free(pre->nextarc);
                        pre->nextarc=arc;
                        break;
                    }
                    else
                    {
                        arc=arc->nextarc;
                        pre=pre->nextarc;
                        continue;
                    }
                }
            }
    }
    g->arcnum--;
    return OK;
}

void visit(Vertex e)
{
    printf("%c\t",e);
}

status DFSTraverse(Graph g,void (*visit)(Vertex))
{
    int v;
    for(v=0;v<g->vexnum;v++) visited[v]=FALSE;
    for(v=0;v<g->vexnum;v++)
    {
        if(!visited[v]) DFS(g,v);
    }
    return OK;

}

void DFS(Graph g,int v0)
{
    int st[MAX_VERTEX_NUM+1];
    int top=0;
    int v,w;

    st[++top]=v0;
    while(top)
    {
        v=st[top--];
        if(!visited[v])
        { //栈中可能有重复顶点
            visited[v]=TRUE;
            visit(g->vertices[v].data);
        }
        for(w=FirstAdjVex(g,v); w>=0; w=NextAdjVex(g, v, w))
        {
            if (!visited[w]) st[++top]=w;
        }
    }

}

status BFSTraverse(Graph g,void (*visit)(Vertex))
{
    int u,v,w;

    for(v=0;v<g->vexnum;v++) visited[v]=FALSE;
    que tail=NULL;
    que head=NULL;
    que new_node=NULL;


    tail=(que)malloc(sizeof(qu)); tail->next=NULL; tail->pre=NULL; tail->v=-1;
    head=tail;
    for(v=0;v<g->vexnum;++v)
    {
        if(!visited[v])
        {
            visited[v]=TRUE;
            visit(g->vertices[v].data);
            new_node=(que)malloc(sizeof(qu));
            new_node->v=v;
            if(head!=tail)
            {
                new_node->next=tail->next; new_node->pre=tail; tail->next->pre=new_node; tail->next=new_node;
            }
            else
            {
                tail->next=new_node; new_node->pre=tail; new_node->next=tail; tail->pre=new_node;
                head=new_node;
            }


            while(head!=tail)
            {
                head=head->pre;
                u=head->next->v;
                free(head->next); head->next=tail; tail->pre=head;
                for(w=FirstAdjVex(g,u);w>=0;w=NextAdjVex(g,u,w))
                {
                    if(!visited[w])
                    {
                        visited[w]=TRUE;
                        visit(g->vertices[w].data);
                        new_node=(que)malloc(sizeof(qu));
                        new_node->v=w;
                        if(head!=tail)
                        {
                            new_node->next=tail->next; new_node->pre=tail; tail->next->pre=new_node; tail->next=new_node;
                        }
                        else
                        {
                            tail->next=new_node; new_node->pre=tail; new_node->next=tail; tail->pre=new_node;
                            head=new_node;
                        }
                    }
                }


            }


        }
    }
    return OK;

}

void save(ManageList* M)
{
    if(M->length==0) return;
    FILE* fp=NULL;
    int i,j;
    Graph g;
    p_ArcNode arc,pre;
    p_ArcNode blank=(p_ArcNode)malloc(sizeof(ArcNode));
    blank->weight=-2;

    fp=fopen("graph.dat","wb");
    fwrite(M,sizeof(ManageList),1,fp);
    fwrite(M->elem,sizeof(ListInfo),M->listsize,fp);
    for(i=0;i<M->length;i++)
    {
        g=(M->elem+i)->elem;
        fwrite(g,sizeof(ALGraph),1,fp);
        for(j=0;j<g->vexnum;j++)
        {
            arc=g->vertices[j].firstarc;
            while(arc)
            {
                fwrite(arc,sizeof(ArcNode),1,fp);
                pre=arc;
                arc=arc->nextarc;
                free(pre);
            }
            fwrite(blank,sizeof(ArcNode),1,fp);
        }
        free(g);
    }
    free(M->elem);
    printf("已保存\n");
}

void recover(ManageList* M,Graph* g)
{
    FILE* fp=NULL;
    int i,j,done=0;
    p_ArcNode new_arc,end_arc;

    fp=fopen("graph.dat","rb");
    fread(M,sizeof(ManageList),1,fp);
    ListInfo* info=(ListInfo*)malloc(sizeof(ListInfo)*(M->listsize));
    M->elem=info;
    fread(M->elem,sizeof(ListInfo),M->listsize,fp);
    for(i=0;i<M->length;i++)
    {
        Graph g=(Graph)malloc(sizeof(ALGraph));
        fread(g,sizeof(ALGraph),1,fp);
        for(j=0;j<g->vexnum;j++)
        {
            new_arc=(p_ArcNode)malloc(sizeof(ArcNode));
            fread(new_arc,sizeof(ArcNode),1,fp);
            if(new_arc->weight==-2)
            {
                g->vertices[j].firstarc=NULL;
                free(new_arc);
                continue;
            }
            else
            {
                g->vertices[j].firstarc=new_arc;
                new_arc->nextarc=NULL;
                end_arc=new_arc;
            }
            while(!done)
            {
                new_arc=(p_ArcNode)malloc(sizeof(ArcNode));
                fread(new_arc,sizeof(ArcNode),1,fp);
                if(new_arc->weight==-2)
                {
                    free(new_arc);
                    done=1;
                }
                else
                {
                    end_arc->nextarc=new_arc;
                    new_arc->nextarc=NULL;
                    end_arc=new_arc;
                }
            }
            done=0;

        }
        (M->elem+i)->elem=g;

    }
    M->cur=0;
    *g=M->elem[0].elem;

    printf("恢复成功,按回车继续\n"); getchar();
}



