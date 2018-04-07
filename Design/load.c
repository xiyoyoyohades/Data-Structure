#include"avl.h"
#include"set.h"
#include"HashTable.h"
#include"i_o.h"

AVL_Node_Ptr load_avl(FILE* fp)
{
    AVL_Node_Ptr T=(AVL_Node_Ptr)malloc(sizeof(AVL_Node));
    if(!T) exit(-1);
    fread(T,sizeof(AVL_Node),1,fp);

    if(T->key>-1)
    {

        //printf("loaded\n");
       // exit(0);
        T->left_child=load_avl(fp);
        T->right_child=load_avl(fp);
        return T;
    }
    else
    {
        //printf("%d\n",T->key);
        //printf("free empty\n");
        free(T);
        return NULL;
    }
}

Set_Ptr load_set(FILE* fp)
{
    Set_Ptr set=(Set_Ptr)malloc(sizeof(Set));
    fread(set,sizeof(Set),1,fp);
    AVL_Tree_Ptr tree=(AVL_Tree_Ptr)malloc(sizeof(AVL_Tree));
    fread(tree,sizeof(AVL_Tree),1,fp);

    tree->root=load_avl(fp);
    set->Tree=tree;
    return set;
}

HashTable_Ptr load_hash(FILE* fp)
{
    HashTable_Ptr hashtable=(HashTable_Ptr)malloc(sizeof(HashTable));
    fread(hashtable,sizeof(HashTable),1,fp);

    HashBlock* block=(HashBlock*)malloc(sizeof(HashBlock)*hashtable->length);
    fread(block,sizeof(HashBlock),hashtable->length,fp);
    hashtable->Block=block;

    HashBlock* ptr=NULL;
    HashNode_Ptr new_node=NULL;
    HashNode_Ptr pre=NULL;



    int i,j;
    for(i=0;i<HASH_LENGTH;i++)
    {
        ptr=hashtable->Block+i;
        for(j=1;j<=ptr->Block_record_num;j++)
        {

            new_node=(HashNode_Ptr)malloc(sizeof(HashNode));
            fread(new_node,sizeof(HashNode),1,fp);

            new_node->friends=load_set(fp);

            new_node->followers=load_set(fp);
            new_node->following=load_set(fp);


            new_node->hobby=(hobby_ptr)malloc(sizeof(hobby_node));
            fread(new_node->hobby,sizeof(hobby_node),1,fp);
            fseek(fp,-sizeof(hobby_node),SEEK_CUR);
            int hobby_num=new_node->hobby->num;
            new_node->hobby=(hobby_ptr)malloc(sizeof(hobby_node)*(hobby_num+1));
            fread(new_node->hobby,sizeof(hobby_node),hobby_num+1,fp);

            new_node->next=NULL;

            if(j==1)
            {
                ptr->Block_List=new_node;
            }
            else
            {
                pre->next=new_node;
            }
            pre=new_node;
        }
    }
    return hashtable;
}


