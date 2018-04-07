#include"avl.h"
#include"set.h"
#include"HashTable.h"
#include"i_o.h"

void save_avl(AVL_Node_Ptr root, FILE* fp)
{
    AVL_Node_Ptr empty=(AVL_Node_Ptr)malloc(sizeof(AVL_Node));
    empty->height=-2;
    empty->key=-1;

    if(root)
    {
        //printf("write\n");
        fwrite(root,sizeof(AVL_Node),1,fp);
    }
    else
    {
        //printf("write empty\n");
        fwrite(empty,sizeof(AVL_Node),1,fp);
    }
    if(root)
    {
        save_avl(root->left_child,fp);
        save_avl(root->right_child,fp);
    }
}

void save_set(Set_Ptr set, FILE* fp)
{
    fwrite(set,sizeof(Set),1,fp);
    fwrite(set->Tree,sizeof(AVL_Tree),1,fp);
    save_avl(set->Tree->root,fp);
}

void save_hash(HashTable_Ptr hashtable, FILE* fp)
{
    fwrite(hashtable,sizeof(HashTable),1,fp);
    fwrite(hashtable->Block,sizeof(HashBlock),hashtable->length,fp);

    int i;
    HashBlock* ptr=NULL;
    HashNode_Ptr node=NULL;
    for(i=0;i<HASH_LENGTH;i++)
    {
        ptr=hashtable->Block+i;
        node=ptr->Block_List;
        while(node)
        {
            fwrite(node,sizeof(HashNode),1,fp);
            save_set(node->friends,fp);
            save_set(node->followers,fp);
            save_set(node->following,fp);
            fwrite(node->hobby,sizeof(hobby_node),node->hobby->num+1,fp);
            node=node->next;
        }

    }
}


