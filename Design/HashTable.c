#include"HashTable.h"
#include"set.h"
#include"avl.h"

int Hash_Function(int key,int length)
{
    return key%length;
}

HashTable_Ptr Init_HashTable(int length)
{
    HashTable_Ptr hashtable=(HashTable_Ptr)malloc(sizeof(HashTable));
    hashtable->length=length;
    hashtable->record_num=0;
    hashtable->Block=(HashBlock*)malloc(sizeof(HashBlock)*HASH_LENGTH);
    int i;
    for(i=0;i<HASH_LENGTH;i++)
    {
        hashtable->Block[i].Block_record_num=0;
        hashtable->Block[i].Block_List=NULL;
    }
    return hashtable;
}

int Insert_Hash_Record(HashTable_Ptr hashtable, int key, char* name)
{
    int index=Hash_Function(key,HASH_LENGTH);
    int isexist=0;
    HashNode_Ptr node=NULL;
    HashBlock* ptr=hashtable->Block+index;
    if(ptr->Block_List==NULL) isexist=0;
    else
    {
        node=ptr->Block_List;
        while(node)
        {
            if(node->key==key)
            {
                isexist=1;
                break;
            }
            else node=node->next;
        }
    }

    if(isexist) return 0;
    else
    {
        if(ptr->Block_record_num==0)
        {
            HashNode_Ptr new_record=(HashNode_Ptr)malloc(sizeof(HashNode));
            new_record->followers=init_set(Followers,key);
            new_record->following=init_set(Following,key);
            new_record->friends=init_set(Friends,key);
            new_record->hobby=(hobby_ptr)malloc(sizeof(hobby_node));
            new_record->hobby->num=0;

            new_record->key=key;
            strcpy(new_record->name,name);
            new_record->next=NULL;
            ptr->Block_List=new_record;
            ptr->Block_record_num++;
            hashtable->record_num++;
        }
        else
        {
            HashNode_Ptr new_record=(HashNode_Ptr)malloc(sizeof(HashNode));
            new_record->followers=init_set(Followers,key);
            new_record->following=init_set(Following,key);
            new_record->friends=init_set(Friends,key);
            new_record->hobby=(hobby_ptr)malloc(sizeof(hobby_node));
            new_record->hobby->num=0;

            new_record->key=key;
            strcpy(new_record->name,name);
            new_record->next=ptr->Block_List;
            ptr->Block_List=new_record;
            ptr->Block_record_num++;
            hashtable->record_num++;
        }
        return 1;
    }

}

int Delete_Hash_Record(HashTable_Ptr hashtable, int key)
{
    int index=Hash_Function(key,HASH_LENGTH);
    HashBlock* ptr=hashtable->Block+index;
    HashNode_Ptr node=ptr->Block_List;
    HashNode_Ptr pre=node;
    if(ptr->Block_record_num==0) return 0;
    else
    {
        while(node)
        {
            if(node->key==key)
            {
                while(pre->next!=node&&pre->next!=NULL)
                {
                    pre=pre->next;
                }

                if(!(pre->next))
                {
                    ptr->Block_record_num--;
                    ptr->Block_List=node->next;
                    set_destroy(node->friends);
                    set_destroy(node->followers);
                    set_destroy(node->following);
                    free(node->hobby);
                    free(node);
                }
                else
                {
                    ptr->Block_record_num--;
                    pre->next=node->next;
                    set_destroy(node->friends);
                    set_destroy(node->followers);
                    set_destroy(node->following);
                    free(node->hobby);
                    free(node);
                }
                hashtable->record_num--;
                return 1;
            }
            else
            {
                node=node->next;
            }
        }
        return 0;
    }
}

HashNode_Ptr Search_Hash(HashTable_Ptr hashtable, int key)
{
    int index=Hash_Function(key,HASH_LENGTH);
    HashBlock* ptr=hashtable->Block+index;
    HashNode_Ptr node=ptr->Block_List;
    if(ptr->Block_record_num==0) return NULL;
    else
    {
        while(node)
        {
            if(node->key==key) return node;
            else node=node->next;
        }
        return NULL;
    }
}

void Traverse_Hash(HashTable_Ptr hashtable, void (*visit)(HashNode_Ptr))
{
    int index;
    HashBlock* ptr=NULL;
    HashNode_Ptr node=NULL;
    for(index=0;index<HASH_LENGTH;index++)
    {
        ptr=hashtable->Block+index;
        node=ptr->Block_List;
        while(node)
        {
            visit(node);
            node=node->next;
        }

    }
}


void Visit_Hash(HashNode_Ptr node)
{
    printf("%5d%10s",node->key,node->name);
    printf("%10d",node->friends==NULL?0:node->friends->Tree->quantity);
    printf("%10d",node->followers==NULL?0:node->followers->Tree->quantity);
    printf("%10d",node->following==NULL?0:node->following->Tree->quantity);
    printf("%10d\n",node->hobby->num);
}
