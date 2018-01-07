#include "def.h"


status InitBiTree(Tree* T)
{
    *T=NULL;
    return OK;
}

status DestroyBiTree(Tree T)
{
    if(T)
    {
        if(T->lchild)
        {
            DestroyBiTree(T->lchild);
            T->lchild=NULL;
        }
        if(T->rchild)
        {
            DestroyBiTree(T->rchild);
            T->rchild=NULL;
        }
        if(T)
        {
            free(T);
            T=NULL;
        }
        return OK;
    }
    else return ERROR;


}


TreeNode CreateBiTree(Treeinfo L)
{
        char content[7];
        char content_part[6];
        char s_index[4];
        char s_grade[4];
        TreeNode T;
        int i;
        char c=getchar();

        if (c=='#'||c=='\n')
        {
            return NULL;
        }
        content[0]=c;
        scanf("%5s",content_part);
        //printf("%s\n",content_part);
        for(i=1;i<=5;i++)
        {
            content[i]=content_part[i-1];
        }
        //printf("%s\n",content);

        T=(TreeNode)malloc(sizeof(BiTNode));
        if(!T) exit(OVERFLOW);

        sscanf(content,"%3s",s_index); //printf("%s\n",s_index);
        sscanf(content+3,"%3s",s_grade); //printf("%s\n",s_grade);
        T->index=atoi(s_index);
        T->grade=atoi(s_grade);
        (L->ver_num)++;
        T->lchild=CreateBiTree(L);
        T->rchild=CreateBiTree(L);

        return T;

}


status ClearBiTree(Tree T)
{
    if(T)
    {

        if(T->lchild)
        {
            ClearBiTree(T->lchild);
            T->lchild=NULL;
        }
        if(T->rchild)
        {
            ClearBiTree(T->rchild);
            T->rchild=NULL;
        }
        if(T)
        {
            free(T);
            T=NULL;
        }
        return OK;
    }
    else return ERROR;
}

status BiTreeEmpty(Tree T)
{
    if(T) return FALSE;
    else  return TRUE;
}

status BiTreeDepth(Tree T)
{
    if(!T)
    {
        return 0;
    }
    int nLeft=BiTreeDepth(T->lchild);
    int nRight=BiTreeDepth(T->rchild);
    return nLeft>nRight?nLeft+1:nRight+1;
}

TreeNode Root(Tree T)
{
    if(!T)
    {
        return NULL;
    }
    return T;
}

TElemType Value(Tree T,int e)
{
    BiTree st[MAX_LENGTH+1]; //����ָ��ջ
    int top=0; //�ÿ�ջ
    if(!T) return ERROR;
    do
    {
        while(T)
        {
            if(top==MAX_LENGTH) exit(OVERFLOW);//ջ����,�˳�
            st[++top]=T;//��ָ���ջ(�ǿ�ָ�룩
            T=T->lchild; //t����������
        }//ѭ��������ʾ�����ﵽ��tΪ��ָ��Ķ������������·�
        if(top) //Ϊ�ǿ�ջ
        {
            T=st[top--];
            if(T->index==e) return T->grade;
            T=T->rchild;//����������
        }
    } while(top||T); //�����δ���ʣ���������δ����
    return INFEASIBLE;
}

status Assign(Tree T,int e,int value)
{
    BiTree st[MAX_LENGTH+1]; //����ָ��ջ
    int top=0; //�ÿ�ջ
    if(!T) return ERROR;
    do
    {
        while(T)
        {
            if(top==MAX_LENGTH) exit(OVERFLOW);//ջ����,�˳�
            st[++top]=T;//��ָ���ջ(�ǿ�ָ�룩
            T=T->lchild; //t����������
        }//ѭ��������ʾ�����ﵽ��tΪ��ָ��Ķ������������·�
        if(top) //Ϊ�ǿ�ջ
        {
            T=st[top--];
            if(T->index==e)
            {
                T->grade=value;
                return OK;
            }
            T=T->rchild;//����������
        }
    } while(top||T);//�����δ���ʣ���������δ����
    return INFEASIBLE;
}

TreeNode Parent(Tree T,int e)
{
    BiTree st[MAX_LENGTH+1]; //����ָ��ջ
    int tag[MAX_LENGTH+1];
    int top=0; //�ÿ�ջ
    if(!T) return NULL;
    while(T||top)//ջ����tҲΪ�ա�
    {
        while(T)
        {
            if(top==MAX_LENGTH) exit(OVERFLOW);
            st[++top]=T;
            tag[top]=0;   //���÷��ʱ�ǣ�0Ϊ��һ�η��ʣ�1Ϊ�ڶ��η���
            T=T->lchild;
        }
        if(tag[top]==0)//��һ�η���ʱ��ת��ͬ���ҽ��
        {
            T=st[top];   //���ߵ���ʱt��Ϊ�յ�
            tag[top]=1;
            T=T->rchild;
            }
        else
        {
            while(tag[top]==1)//�ҵ�ջ����һ����һ�η��ʵĽ�㣬�˳�ѭ��ʱ��û��pop����Ϊ�����ӽ��
            {
                T=st[top--];
                if(T->index==e&&top>0) return st[top];
            }
            T=NULL; //��t�ÿա����������ߣ�ֱ��������
        }
    }
    return NULL;
}

TreeNode LeftChild(Tree T,int e)
{
    BiTree st[MAX_LENGTH+1]; //����ָ��ջ
    int top=0; //�ÿ�ջ
    if(!T) return ERROR;
    do
    {
        while(T)
        {
            if(top==MAX_LENGTH) exit(OVERFLOW);//ջ����,�˳�
            st[++top]=T;//��ָ���ջ(�ǿ�ָ�룩
            T=T->lchild; //t����������
        }//ѭ��������ʾ�����ﵽ��tΪ��ָ��Ķ������������·�
        if(top) //Ϊ�ǿ�ջ
        {
            T=st[top--];
            if(T->index==e) return T->lchild;
            T=T->rchild;//����������
        }
    } while(top||T);
    return NULL;

}


TreeNode RightChild(Tree T,int e)
{
    BiTree st[MAX_LENGTH+1];
    int top=0;
    if(!T) return ERROR;
    do
    {
        while(T)
        {
            if(top==MAX_LENGTH) exit(OVERFLOW);//ջ����,�˳�
            st[++top]=T;//��ָ���ջ(�ǿ�ָ�룩
            T=T->lchild; //t����������
        }//ѭ��������ʾ�����ﵽ��tΪ��ָ��Ķ������������·�
        if(top) //Ϊ�ǿ�ջ
        {
            T=st[top--];
            if(T->index==e) return T->rchild;
            T=T->rchild;//����������
        }
    } while(top||T);//�����δ���ʣ���������δ����
    return NULL;
}

TreeNode LeftSibling(Tree T,int e)
{
    TreeNode parent=Parent(T,e);
    TreeNode cur=Search(T,e);
    if(parent)
    {
        if(parent->lchild==cur||parent->lchild==NULL) return ERROR;
        else return parent->lchild;
    }
    else return ERROR;
}

TreeNode RightSibling(Tree T,int e)
{
    TreeNode parent=Parent(T,e);
    TreeNode cur=Search(T,e);
    if(parent)
    {
        if(parent->rchild==cur||parent->rchild==NULL) return ERROR;
        else return parent->rchild;
    }
    else return ERROR;

}

BiTree copy_tree(Tree T)
{
    TreeNode newNode=NULL;
    TreeNode newLp=NULL;
    TreeNode newRp=NULL;
    if(!T) return NULL;
    if(T->lchild)
    {
        newLp=copy_tree(T->lchild);//����������
    }
    else
    {
        newLp=NULL;
    }
    if(T->rchild)
    {
        newRp=copy_tree(T->rchild);//����������
    }
    else
    {
        newRp=NULL;
    }

    newNode=(TreeNode)malloc(sizeof(BiTNode));
    if(!newNode) return NULL;
    newNode->lchild=newLp;
    newNode->rchild=newRp;
    newNode->index=T->index;
    newNode->grade=T->grade;
    return newNode;
}

TreeNode Search(Tree T,int index)
{
    BiTree st[MAX_LENGTH+1]; //����ָ��ջ
    int top=0;//�ÿ�ջ
    if(!T) return ERROR;
    do
    {
        while(T)
        {
            if(top==MAX_LENGTH) exit(OVERFLOW);//ջ����,�˳�
            st[++top]=T;//��ָ���ջ(�ǿ�ָ�룩
            T=T->lchild; //t����������
        }//ѭ��������ʾ�����ﵽ��tΪ��ָ��Ķ������������·�
        if(top) //Ϊ�ǿ�ջ
        {
            T=st[top--];
            if(T->index==index) return T;
            T=T->rchild;//����������
        }
    } while(top||T);//�����δ���ʣ���������δ����
    return NULL;

}

status InsertChild(Tree T,int index,int LR,BiTree c)
{
    if(!T) return ERROR;
    Tree insertion=NULL;
    Tree origin=NULL;
    insertion=copy_tree(c);

    if(insertion->rchild)
    {
        DestroyBiTree(insertion->rchild);
        insertion->rchild=NULL;
    }
    TreeNode p=Search(T,index);
    if(p)
    {
        if(!LR)
        {
            origin=p->lchild;
            p->lchild=insertion;
            insertion->rchild=origin;
        }
        else
        {
            origin=p->rchild;
            p->rchild=insertion;
            insertion->rchild=origin;
        }
        return OK;
    }
    else return ERROR;

}

status DeleteChild(Tree T,int e,int LR)
{
    if(!T) return ERROR;
    TreeNode p=Search(T,e);
    if(p)
    {
        Tree left=p->lchild;
        Tree right=p->rchild;
        if(!LR)
        {
            DestroyBiTree(left);
            p->lchild=NULL;
        }
        else
        {
            DestroyBiTree(right);
            p->rchild=NULL;
        }
        return OK;
    }
    else return ERROR;


}

void visit(TElemType e)
{
    printf("%d\t",e);
}

status PreOrderTraverse(Tree T,void (*visit)(TElemType))
{
    BiTree st[MAX_LENGTH+1];
    int top=0;
    if(!T) return ERROR;
    while(T||top)
    {
        while(T)
        {
            if(top==MAX_LENGTH) exit(OVERFLOW);
            visit(T->grade);
            st[++top]=T;
            T=T->lchild;
        }
        T=st[top--];
        T=T->rchild;
    }
    return OK;
}

status InOrderTraverse(Tree T,void (*visit)(TElemType))
{
    BiTree st[MAX_LENGTH+1]; //����ָ��ջ
    int top=0;//�ÿ�ջ
    if(!T) return ERROR;
    do
    {
        while(T)
        {
            if(top==MAX_LENGTH) exit(OVERFLOW);//ջ����,�˳�
            st[++top]=T;//��ָ���ջ(�ǿ�ָ�룩
            T=T->lchild; //t����������
        }//ѭ��������ʾ�����ﵽ��tΪ��ָ��Ķ������������·�
        if(top) //Ϊ�ǿ�ջ
        {
            T=st[top--];
            visit(T->grade);
            T=T->rchild;//����������
        }
    } while(top||T);//�����δ���ʣ���������δ����
    return OK;
}

status PostOrderTraverse(Tree T,void (*visit)(TElemType))
{
    BiTree st[MAX_LENGTH+1]; //����ָ��ջ
    int tag[MAX_LENGTH+1];
    int top=0; //�ÿ�ջ
    if(!T) return ERROR;
    while(T||top)//ջ����tҲΪ�ա�
    {
        while(T)
        {
            if(top==MAX_LENGTH) exit(OVERFLOW);
            st[++top]=T;
            tag[top]=0;   //���÷��ʱ�ǣ�0Ϊ��һ�η��ʣ�1Ϊ�ڶ��η���
            T=T->lchild;
        }
        if(tag[top]==0)//��һ�η���ʱ��ת��ͬ���ҽ��
        {
            T=st[top];   //���ߵ���ʱt��Ϊ�յģ��������ⲽ��
            tag[top]=1;
            T=T->rchild;
            }
        else
        {
            while(tag[top]==1)//�ҵ�ջ����һ����һ�η��ʵĽ�㣬�˳�ѭ��ʱ��û��pop����Ϊ�����ӽ��
            {
                T=st[top--];
                visit(T->grade);
            }
            T=NULL; //��t�ÿա����������ߣ�ֱ��������
        }
    }
    return OK;
}

status LevelOrderTraverse(Tree T,void (*visit)(TElemType))
{
    BiTree q[2*MAX_LENGTH+1];
    BiTree p;
    int top=0;
    int tail=0;
    if(T)
    {
        q[++tail]=T;
        while(top!=tail)
        {
            p=q[++top];
            visit(p->grade);
            if(p->lchild) q[++tail]=p->lchild;
            if(p->rchild) q[++tail]=p->rchild;
        }
        return OK;
    }
    else return ERROR;
}


void save_tree(Tree T,FILE* fp)
{
    TreeNode empty=(TreeNode)malloc(sizeof(BiTNode));
    empty->index=-1;
    if(T)
    {
        fwrite(T,sizeof(BiTNode),1,fp);
    }
    else
    {
        fwrite(empty,sizeof(BiTNode),1,fp);
    }
    if(T)
    {
        save_tree(T->lchild,fp);
        save_tree(T->rchild,fp);
    }
}

int get_ver_num(Tree T)
{
    BiTree st[MAX_LENGTH+1];
    int top=0;
    int num=0;
    if(!T) return ERROR;
    while(T||top)
    {
        while(T)
        {
            if(top==MAX_LENGTH) exit(OVERFLOW);
            num++;
            st[++top]=T;
            T=T->lchild;
        }
        T=st[top--];
        T=T->rchild;
    }
    return num;

}
void save(ManageList* M)
{
    if(M->length==0) return;
    FILE* fp=NULL;
    int i;
    Treeinfo info_node;
    TreeNode root;
    fp=fopen("save.dat","wb");
    fwrite(M,sizeof(ManageList),1,fp);
    fwrite(M->elem,sizeof(ListInfo),M->listsize,fp);
    for(i=0;i<M->length;i++)
    {
        info_node=(M->elem+i)->elem;
        fwrite(info_node,sizeof(Bitreeinfo),1,fp);
        root=info_node->root;
        save_tree(root,fp);
        DestroyBiTree(root);
        free(info_node);
    }
    free(M->elem);
    printf("�ѱ���\n");
}

TreeNode recover_tree(FILE* fp)
{
    TreeNode T=(TreeNode)malloc(sizeof(BiTNode));
    if(!T) exit(OVERFLOW);
    fread(T,sizeof(BiTNode),1,fp);
    if(T->index>0)
    {
        T->lchild=recover_tree(fp);
        T->rchild=recover_tree(fp);
        return T;
    }
    else
    {
        free(T);
        return NULL;
    }

}

void recover(ManageList* M,Treeinfo* L)
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
        Treeinfo LL=(Treeinfo)malloc(sizeof(Bitreeinfo));
        fread(LL,sizeof(Bitreeinfo),1,fp);
        (M->elem+i)->elem=LL;
        LL->root=recover_tree(fp);
    }
    M->cur=0;
    *L=M->elem[0].elem;

    printf("�ָ��ɹ�,���س�����\n"); getchar();
}
