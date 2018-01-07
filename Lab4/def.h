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
//#define MAX_LENGTH 512
#define MAX_VERTEX_NUM 20

typedef enum{DG,DN,UDG,UDN} GraphKind;

typedef int status;
typedef char Vertex;
typedef int Arcinfo;

typedef struct ArcNode{//表结点结构类型
    int adjvex; //该弧(边)的终点位置
    struct ArcNode* nextarc; //指向下一条弧的指针
    Arcinfo weight; //该弧的相关信息的指针
} ArcNode, *p_ArcNode;

typedef struct Vnode {//头结点的类型
    Vertex data; //顶点信息
    struct ArcNode *firstarc; //指向第一条弧
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph{//邻接表
    AdjList vertices;
    int vexnum, arcnum; //图中顶点数n和边数e
    GraphKind kind; //图的类型
} ALGraph, *GraphPtr, *Graph;

typedef struct ListInfo{
    char name[20];
    struct ALGraph* elem;
}ListInfo;

typedef struct ManageList{
    struct ListInfo* elem;
    int length;
    int listsize;
    int cur;
}ManageList;



typedef struct qu{
    struct qu* pre;
    int v;
    struct qu* next;
}qu, *que;

Graph CreateGraph(Graph g);
status DestroyGraph(Graph g);
int LocateVex(Graph g,Vertex u);
Vertex GetVex(Graph g,int v);
status PutVex(Graph g,int v,Vertex value);
int FirstAdjVex(Graph g,int v);
int NextAdjVex(Graph g,int v, int w);
status InsertVex(Graph g,Vertex v);
status DeleteVex(Graph g,int v);
status InsertArc(Graph g,int v,int w);
status DeleteArc(Graph g,int v,int w);
status DFSTraverse(Graph g,void (*visit)(Vertex));
void DFS(Graph g,int v0);
status BFSTraverse(Graph g,void (*visit)(Vertex));

void visit(Vertex e);
//status compare(Vertex e,Vertex f);

void save(ManageList* M);

void recover(ManageList* M,Graph* g);


#endif // DEF_H_INCLUDED
