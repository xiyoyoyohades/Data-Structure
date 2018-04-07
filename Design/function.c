#include "function.h"

HashNode_Ptr check_validation(HashTable_Ptr hashtable, int id)
{
    HashNode_Ptr user=Search_Hash(hashtable,id);
    if(user) return user;
    else return NULL;
}

void Add_user(HashTable_Ptr hashtable, int new_id, char* new_name)
{
    int status=Insert_Hash_Record(hashtable,new_id,new_name);
    if(status) printf("STATUS: Adding is done\n");
    else printf("STATUS: Adding failed, record already exists\n");
}

int Add_friend(HashTable_Ptr hashtable, int user_id, int friend_id,int flag)
{
    HashNode_Ptr validation1=check_validation(hashtable,user_id);
    if(!validation1)
    {
        printf("STATUS: Target user not found\n");
        return 0;
    }
    else
    {
        HashNode_Ptr validation2=check_validation(hashtable,friend_id);
        set_insert(validation1->friends,friend_id);
        if(!validation2)
        {
            printf("STATUS: New user detected, input name to continue: ");
            char new_name[20];
            scanf("%s",new_name); fflush(stdin);
            Insert_Hash_Record(hashtable,friend_id,new_name);
        }
        if(flag) Add_friend(hashtable,friend_id,user_id,0);
        printf("STATUS: Friend added\n");
        return 1;

    }

}

int Add_follower(HashTable_Ptr hashtable, int user_id,int follower_id, int flag)
{
    HashNode_Ptr validation1=check_validation(hashtable,user_id);
    if(!validation1)
    {
        printf("STATUS: Target user not found\n");
        return 0;
    }
    else
    {
        HashNode_Ptr validation2=check_validation(hashtable,follower_id);
        set_insert(validation1->followers,follower_id);
        if(!validation2)
        {
            printf("STATUS: New user detected, input name to continue: ");
            char new_name[20];
            scanf("%s",new_name); fflush(stdin);
            Insert_Hash_Record(hashtable,follower_id,new_name);
        }
        if(flag) Add_following(hashtable, follower_id, user_id,0);
        printf("STATUS: Follower added\n");
        return 1;
    }
}

int Add_following(HashTable_Ptr hashtable, int user_id,int following_id, int flag)
{
    HashNode_Ptr validation1=check_validation(hashtable,user_id);
    if(!validation1)
    {
        printf("STATUS: Target user not found\n");
        return 0;
    }
    else
    {
        HashNode_Ptr validation2=check_validation(hashtable,following_id);
        set_insert(validation1->following,following_id);
        if(!validation2)
        {
            printf("STATUS: New user detected, input name to continue: ");
            char new_name[20];
            scanf("%s",new_name); fflush(stdin);
            Insert_Hash_Record(hashtable,following_id,new_name);
        }
        if(flag) Add_follower(hashtable, following_id, user_id,0);
        printf("STATUS: Following added\n");
        return 1;
    }
}

int Add_hobby(HashTable_Ptr hashtable, int user_id, char* new_hobby)
{
    HashNode_Ptr validation1=check_validation(hashtable,user_id);
    if(!validation1)
    {
        printf("STATUS: Target user not found\n");
        return 0;
    }
    else
    {
        int old_num=validation1->hobby->num;
        int j;
        for(j=1;j<=old_num;j++)
        {
            if(!strcmp((validation1->hobby+j)->hobby,new_hobby))
            {
                printf("STATUS: Hobby already exists\n");
                return 0;
            }

        }
        hobby_ptr hobby=NULL;
        hobby=(hobby_ptr)realloc(validation1->hobby,sizeof(hobby_node)*(old_num+2));
        validation1->hobby=hobby;
        hobby->num=old_num+1;
        strcpy((hobby+old_num+1)->hobby,new_hobby);
        printf("STATUS: Hobby added\n");
        return 1;
    }
}

void Delete_user(HashTable_Ptr hashtable, int id)
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
            set_remove(node->friends,id);
            set_remove(node->followers,id);
            set_remove(node->following,id);
            node=node->next;
        }
    }
   // printf("here\n");
    Delete_Hash_Record(hashtable,id);
    printf("STATUS: User deleted\n");
}

int Delete_friend(HashTable_Ptr hashtable, int user_id, int friend_id,int flag)
{
    HashNode_Ptr validation1=check_validation(hashtable,user_id);
    if(!validation1)
    {
        printf("STATUS: Target user not found\n");
        return 0;
    }
    else
    {
        HashNode_Ptr validation2=check_validation(hashtable,friend_id);
        if(!validation2)
        {
            printf("STATUS: Friend not found\n");
            return 0;
        }
        else
        {
            printf("1\n");
            set_remove(validation1->friends,friend_id);
        }
        printf("2\n");
        if(flag) Delete_friend(hashtable,friend_id,user_id,0);
        printf("STATUS: Friend deleted\n");
        return 1;

    }

}

int Delete_follower(HashTable_Ptr hashtable, int user_id, int follower_id,int flag)
{
    HashNode_Ptr validation1=check_validation(hashtable,user_id);
    if(!validation1)
    {
        printf("STATUS: Target user not found\n");
        return 0;
    }
    else
    {
        HashNode_Ptr validation2=check_validation(hashtable,follower_id);
        if(!validation2)
        {
            printf("STATUS: Follower not found\n");
            return 0;
        }
        else
        {
            set_remove(validation1->followers,follower_id);
        }
        if(flag) Delete_following(hashtable,follower_id,user_id,0);
        printf("STATUS: Follower deleted\n");
        return 1;

    }

}

int Delete_following(HashTable_Ptr hashtable, int user_id, int following_id,int flag)
{
    HashNode_Ptr validation1=check_validation(hashtable,user_id);
    if(!validation1)
    {
        printf("STATUS: Target user not found\n");
        return 0;
    }
    else
    {
        HashNode_Ptr validation2=check_validation(hashtable,following_id);
        if(!validation2)
        {
            printf("STATUS: Following not found\n");
            return 0;
        }
        else
        {
            set_remove(validation1->following,following_id);
        }
        if(flag) Delete_follower(hashtable,following_id,user_id,0);
        printf("STATUS: Following deleted\n");
        return 0;

    }

}

void Modify_user_name(HashTable_Ptr hashtable, char* new_name, int id)
{
    HashNode_Ptr target=Search_Hash(hashtable,id);
    if(target)
    {
        strcpy(target->name,new_name);
        printf("STATUS: Modified\n");
    }
    else printf("STATUS: No such user\n");
}

void Modify_friend(HashTable_Ptr hashtable, int user_id, int friend_id,int new_friend, int flag)
{
    int deleted=Delete_friend(hashtable,user_id,friend_id,1);
    if(!deleted)
    {
        printf("STATUS: Failed\n");
        return;
    }
    int added=Add_friend(hashtable,user_id,new_friend,1);
    if(!added)
    {
        printf("STATUS: Failed\n");
        return;
    }
    printf("STATUS: Modified\n");
}

void Modify_follower(HashTable_Ptr hashtable, int user_id, int follower_id,int new_follower, int flag)
{
    int deleted=Delete_follower(hashtable,user_id,follower_id,1);
    if(!deleted)
    {
        printf("STATUS: Failed\n");
        return;
    }
    int added=Add_follower(hashtable,user_id,new_follower,1);
    if(!added)
    {
        printf("STATUS: Failed\n");
        return;
    }
    printf("STATUS: Modified\n");
}


void Modify_following(HashTable_Ptr hashtable, int user_id, int following_id,int new_following, int flag)
{
    int deleted=Delete_following(hashtable,user_id,following_id,1);
    if(!deleted)
    {
        printf("STATUS: Failed\n");
        return;
    }
    int added=Add_following(hashtable,user_id,new_following,1);
    if(!added)
    {
        printf("STATUS: Failed\n");
        return;
    }
    printf("STATUS: Modified\n");
}



void Find_user(HashTable_Ptr hashtable, int id)
{
    HashNode_Ptr target=Search_Hash(hashtable,id);
    if(target)
    {
        printf("STATUS:    User found:\n");
        printf("STATUS:    User ID:%10d\n",target->key);
        printf("STATUS:    User Name:%10s\n",target->name);
        printf("STATUS:    Friends:%10d\n",target->friends->Tree->quantity);
        printf("STATUS:    Followers:%10d\n",target->followers->Tree->quantity);
        printf("STATUS:    following:%10d\n",target->following->Tree->quantity);
        printf("STATUS:    Hobby:%10d\n",target->hobby->num);
    }
    else
    {
        printf("STATUS: No such user\n");
    }
}

void Find_friend(HashTable_Ptr hashtable, int user_id, int friend_id)
{
    HashNode_Ptr user=check_validation(hashtable, user_id);
    if(!user)
    {
        printf("STATUS: No such user\n");
        return;
    }
    int isfound=set_member(user->friends,friend_id);
    if(!isfound)
    {
        printf("STATUS: Friend not found\n");
        return;
    }
    HashNode_Ptr target=Search_Hash(hashtable,friend_id);
    printf("STATUS: Friend found:\n");
    printf("STATUS: Friend name:  %s\n",target->name);
}

void Find_follower(HashTable_Ptr hashtable, int user_id, int follower_id)
{
    HashNode_Ptr user=check_validation(hashtable, user_id);
    if(!user)
    {
        printf("STATUS: No such user\n");
        return;
    }
    int isfound=set_member(user->followers,follower_id);
    if(!isfound)
    {
        printf("STATUS: Follower not found\n");
        return;
    }
    HashNode_Ptr target=Search_Hash(hashtable,follower_id);
    printf("STATUS: Follower found:\n");
    printf("STATUS: Follower name:  %s\n",target->name);
}

void Find_following(HashTable_Ptr hashtable, int user_id, int following_id)
{
    HashNode_Ptr user=check_validation(hashtable, user_id);
    if(!user)
    {
        printf("STATUS: No such user\n");
        return;
    }
    int isfound=set_member(user->following,following_id);
    if(!isfound)
    {
        printf("STATUS: Following not found\n");
        return;
    }
    HashNode_Ptr target=Search_Hash(hashtable,following_id);
    printf("STATUS: Following found:\n");
    printf("STATUS: Following name:  %s\n",target->name);
}



void show_visit(int id, HashTable_Ptr hashtable)
{
    HashNode_Ptr target=Search_Hash(hashtable,id);
    if(!target) return;
    printf("ID: %d, Name: %s\n",target->key,target->name);
}

void Common_following(int id1, int id2, HashTable_Ptr hashtable)
{
    HashNode_Ptr user1=Search_Hash(hashtable,id1);
    HashNode_Ptr user2=Search_Hash(hashtable,id2);
    if(!user1||!user2)
    {
        printf("STATUS: Failed\n");
        return;
    }
    Set_Ptr common_set=Set_intersection(user1->following,user2->following);
    Traverse_AVL(common_set->Tree->root,hashtable,show_visit);
}

int Common_friend_num(int id1, int id2, HashTable_Ptr hashtable)
{
    HashNode_Ptr user1=Search_Hash(hashtable,id1);
    HashNode_Ptr user2=Search_Hash(hashtable,id2);
    if(!user1||!user2)
    {
        printf("STATUS: Failed\n");
        return;
    }
    Set_Ptr common_set=Set_intersection(user1->friends,user2->friends);
    return set_size(common_set);

}

int Common_hobby(int id1, int id2, HashTable_Ptr hashtable,int outmode)
{
    HashNode_Ptr user1=Search_Hash(hashtable,id1);
    HashNode_Ptr user2=Search_Hash(hashtable,id2);
    if(!user1||!user2)
    {
        if(outmode)
        {
            printf("STATUS: Failed\n");
        }

        return -1;
    }
    int num1=user1->hobby->num;
    int num2=user2->hobby->num;
    if(!num1||!num2)
    {
        if(outmode)
        {
            printf("STATUS: No common hobby\n");
        }

        return 0;
    }
    int i,j,k;
    k=0;
    for(i=1;i<=num1;i++)
    {
        for(j=1;j<=num2;j++)
        {
            if(!strcmp(user1->hobby[i].hobby,user2->hobby[j].hobby))
            {
                if(outmode)
                {
                    printf("Common hobby: %s\n",user1->hobby[i].hobby);
                }

                k++;

            }
        }
    }
    if(!k)
    {
        if(outmode)
        {
            printf("STATUS: No common hobby\n");
        }

        return 0;
    }
    return k;
}

Set_Ptr Friend_Friend(int id, HashTable_Ptr hashtable)
{
    Set_Ptr ff=init_set(1,id);
    HashNode_Ptr afriend=NULL;

    AVL_Node_Ptr st[HASH_LENGTH+1]; //定义指针栈
    int top=0;//置空栈
    HashNode_Ptr user=Search_Hash(hashtable,id);
    if(!user)
    {
        printf("STATUS: No such user\n");
        return NULL;
    }
    AVL_Node_Ptr T=user->friends->Tree->root;
    if(!T)
    {
        printf("STATUS: No friend\n");
        return NULL;
    }
    do
    {
        while(T)
        {
            if(top==HASH_LENGTH) exit(-1);//栈已满,退出
            st[++top]=T;//根指针进栈(非空指针）
            T=T->left_child; //t移向左子树
        }//循环结束表示搜索达到以t为根指针的二叉树的最左下方
        if(top) //为非空栈
        {
            T=st[top--];
            afriend=Search_Hash(hashtable,T->key);
            ff=Set_union(ff,afriend->friends);
            //printf("%d\n",ff->Tree->quantity);
            T=T->right_child;//遍历右子树
        }
    } while(top||T);//父结点未访问，或右子树未遍历
    set_remove(ff,id);

    Traverse_AVL(ff->Tree->root,hashtable,show_visit);
    return ff;
}

void Recommend_friend(int id, HashTable_Ptr hashtable)
{
    int i,j,k,tmp1,tmp2;
    int cfnum;
    int common_hob_num[hashtable->record_num];
    int order[hashtable->record_num];
    int common_friend[hashtable->record_num];
    int sum[hashtable->record_num];

    for(i=0;i<hashtable->record_num;i++)
    {
        order[i]=i+1;
    }

    for(i=1;i<=(hashtable->record_num);i++)
    {
        common_hob_num[i-1]=Common_hobby(id,i,hashtable,0)*2;
    }
    for(i=1;i<=(hashtable->record_num);i++)
    {
        cfnum=Common_friend_num(id,i,hashtable);
        if(cfnum>=20) common_friend[i-1]=3;
        else if(cfnum>=10) common_friend[i-1]=2;
        else if(cfnum>=5) common_friend[i-1]=1;
        else common_friend[i-1]=0;
    }
    for(i=1;i<=(hashtable->record_num);i++)
    {
        sum[i-1]=common_hob_num[i-1]+common_friend[i-1];
    }


    for(j=0;j<hashtable->record_num-1;j++)
    {
        for(k=0;k<hashtable->record_num-1-j;k++)
        {
            if(sum[k]<sum[k+1])
            {
                tmp1=sum[k];
                tmp2=order[k];
                sum[k]=sum[k+1];
                order[k]=order[k+1];
                sum[k+1]=tmp1;
                order[k+1]=tmp2;

            }
        }
    }

    HashNode_Ptr user=Search_Hash(hashtable,id);

    for(k=0;k<hashtable->record_num;k++)
    {
        if(order[k]!=id&&sum[k]!=0)
        {
            if((!set_member(user->friends,order[k]))&&k<10)
            {
                HashNode_Ptr node=Search_Hash(hashtable,order[k]);
                printf("ID: %4d  Name: %6s",order[k],node->name);
                printf("     recommend point: %4d\n",sum[k]);
            }

        }
    }




}

int file_num()
{
    FILE* fp=fopen("data00.dat","rb");
    int* file_number=(int*)malloc(sizeof(int));
    fread(file_number,sizeof(int),1,fp);
    fclose(fp);
    return *file_number;
}

void modify_file_num(int num,int mode)
{
    if(mode)
    {
        remove("data00.dat");
        FILE* fp=fopen("data00.dat","wb");
        int new_num=num+1;
        fwrite(&new_num,sizeof(int),1,fp);
        fclose(fp);
    }
    else
    {
        FILE* fp=fopen("data00.dat","wb");
        int new_num=0;
        fwrite(&new_num,sizeof(int),1,fp);
        fclose(fp);
    }

}
