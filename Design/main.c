#include <stdio.h>
#include <stdlib.h>
#include"avl.h"
#include"set.h"
#include"HashTable.h"
#include"function.h"
#include"i_o.h"
#include"test.h"

#define AVL 1
#define SET 2
#define MANAGE 3

int main()
{
    int run_mode;
    printf("STATUS: Input the test mode-----AVL=1  SET=2  MANAGE=3\nINPUT:");
    scanf("%d",&run_mode); fflush(stdin);

if(run_mode==MANAGE)
{


    char filename[20];
    int number,op,mode;
    HashTable_Ptr hashtable=NULL;

    if(!fopen("data00.dat","r"))
    {
        modify_file_num(0,0);
    }
    printf("STATUS: You want to load data from file? ");
    printf(" y/n: ");
    char choice;
    scanf("%c",&choice); fflush(stdin);

    if(choice=='y')
    {
        number=file_num();
        if(number!=0)
        {
            printf("Files exists:\n");
            int i;
            for(i=1;i<=number;i++)
            {
                printf("             data%d.dat\n",i);
            }
            printf("Input the file name:");
            scanf("%s",filename); fflush(stdin);

            FILE* fp=fopen(filename,"rb");

            hashtable=load_hash(fp);
            fclose(fp);
            printf("STATUS: File Loaded\n");
            mode=0;
        }
        else
        {
            mode=1;
            sprintf(filename,"data1.dat");
            hashtable=Init_HashTable(HASH_LENGTH);
            printf("STATUS: No data file found, initialized\n");
        }
    }

    else
    {
        number=file_num();
        mode=2;
        sprintf(filename,"data%d.dat",number+1);
        hashtable=Init_HashTable(HASH_LENGTH);
        printf("STATUS: Initialized\n");
    }

    fflush(stdin);

    printf("STATUS: Press ENTER to continue\n");
    getchar();

    op=1;


    while(op)
    {
        system("cls");	printf("\n\n");
        printf("               Weibo Information Manager \n");
        printf("------------------------------------------------------------\n");
        printf("                        Users                               \n");
        printf("------------------------------------------------------------\n");
        printf("    	  1. Add User            3. Modify a user's name    \n");
        printf("    	  2. Delete User         4. Find a user             \n");
        printf("    	 21. Show users                                     \n");
        printf("------------------------------------------------------------\n");
        printf("                        Friends                             \n");
        printf("------------------------------------------------------------\n");
        printf("    	  5. Add Friend          7. Modify Friend\n");
        printf("    	  6. Delete Friend       8. Find a Friend\n");
        printf("    	 22. Show friends                                   \n");
        printf("------------------------------------------------------------\n");
        printf("                        Followers                           \n");
        printf("------------------------------------------------------------\n");
        printf("    	  9. Add Follower       11. Modify Follower\n");
        printf("    	 10. Delete Follower    12. Find a Follower\n");
        printf("    	 23. Show followers                                 \n");
        printf("------------------------------------------------------------\n");
        printf("                        Following                           \n");
        printf("------------------------------------------------------------\n");
        printf("    	 13. Add Following      15. Modify Following\n");
        printf("    	 14. Delete Following   16. Find a Following person \n");
        printf("    	 24. Show followings                                \n");
        printf("------------------------------------------------------------\n");
        printf("                          Hobby                             \n");
        printf("------------------------------------------------------------\n");
        printf("    	 17. Add Hobby          25. Show hobbies            \n");
        printf("------------------------------------------------------------\n");
        printf("                          Others                            \n");
        printf("------------------------------------------------------------\n");
        printf("    	 18. Commom Following   20. Show Friend's Friend\n");
        printf("         19. Commom Hobby       26. Save data               \n");
        printf("         27. Recommend friend                               \n");
        printf("------------------------------------------------------------\n");
        printf("    	  0. Exit                                           \n");
        printf("------------------------------------------------------------\n");
        printf("    Choose your operation[0~26]:");
        scanf("%d",&op); fflush(stdin);
        switch(op){
        case 1:
            {
                if(TEST)
                {
                    generate_data();
                    auto_input(hashtable);
                    printf("record num: %d\n",hashtable->record_num);

                    fflush(stdin); getchar();
                    break;
                }


                printf("STATUS: Add a user to database\n");
                printf("STATUS: Input new user's ID: \n        ");
                int id;
                char name[20];
                scanf("%d",&id); fflush(stdin);
                printf("STATUS: Input the name of the user:\n        ");
                scanf("%s",name); fflush(stdin);
                Add_user(hashtable,id,name);
                getchar();
                break;


            }
        case 2:
            {
                printf("STATUS: Delete a user from database\n");
                printf("STATUS: Input target user's ID (1-%d): \n        ",hashtable->record_num);
                int id;
                scanf("%d",&id); fflush(stdin);
                if(Search_Hash(hashtable,id))
                {
                    Delete_user(hashtable,id);
                }
                else printf("Invalid id\n");

                fflush(stdin); getchar();
                break;
            }

        case 3:
            {
                printf("STATUS: Modify a user's name\n");
                printf("STATUS: Input target user's ID: \n        ");
                int id;
                scanf("%d",&id); fflush(stdin);
                char name[20];
                printf("STATUS: Input target user's new name: \n        ");
                scanf("%s",name); fflush(stdin);
                Modify_user_name(hashtable,name,id);

                fflush(stdin); getchar();
                break;
            }


        case 4:
            {
                printf("STATUS: Find a user\n");
                printf("STATUS: Input target user's ID :\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);
                Find_user(hashtable,id);

                fflush(stdin); getchar();
                break;
            }


        case 5:
            {
                printf("STATUS: Add a friend\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input friend's ID:\n");
                int Friend;
                scanf("%d",&Friend); fflush(stdin);
                Add_friend(hashtable,id,Friend,1);


                fflush(stdin); getchar();
                break;
            }

        case 6:
            {
                printf("STATUS: Delete a friend\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input target friend's ID:\n");
                int Friend;
                scanf("%d",&Friend); fflush(stdin);
                Delete_friend(hashtable,id,Friend,1);

                fflush(stdin); getchar();
                break;
            }

        case 7:
            {
                printf("STATUS: Modify a friend\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input target friend's ID:\n");
                int Friend;
                scanf("%d",&Friend); fflush(stdin);

                printf("STATUS: Input new friend's ID:\n");
                int new_friend;
                scanf("%d",&new_friend); fflush(stdin);

                Modify_friend(hashtable,id,Friend,new_friend,1);

                fflush(stdin); getchar();
                break;
            }

        case 8:
            {
                printf("STATUS: Find a friend\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input target friend's ID:\n");
                int Friend;
                scanf("%d",&Friend); fflush(stdin);

                Find_friend(hashtable,id,Friend);


                fflush(stdin); getchar();
                break;
            }

        case 9:
            {
                printf("STATUS: Add a follower\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input follower's ID:\n");
                int follower;
                scanf("%d",&follower); fflush(stdin);

                Add_follower(hashtable,id,follower,1);

                fflush(stdin); getchar();
                break;
            }

        case 10:
            {
                printf("STATUS: Delete a follower\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input target follower's ID:\n");
                int follower;
                scanf("%d",&follower); fflush(stdin);

                Delete_follower(hashtable,id,follower,1);

                fflush(stdin); getchar();
                break;
            }

        case 11:
            {
                printf("STATUS: Modify a follower\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input target follower's ID:\n");
                int follower;
                scanf("%d",&follower); fflush(stdin);

                printf("STATUS: Input new follower's ID:\n");
                int new_follower;
                scanf("%d",&new_follower); fflush(stdin);

                Modify_follower(hashtable,id,follower,new_follower,1);

                fflush(stdin);getchar();
                break;
            }

        case 12:
            {
                printf("STATUS: Find a follower\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input target follower's ID:\n");
                int follower;
                scanf("%d",&follower); fflush(stdin);

                Find_follower(hashtable,id,follower);

                fflush(stdin);getchar();
                break;
            }

        case 13:
            {
                printf("STATUS: Add a following\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input the ID to follow:\n");
                int following;
                scanf("%d",&following); fflush(stdin);

                Add_following(hashtable,id,following,1);

                fflush(stdin);getchar();
                break;
            }

        case 14:
            {
                printf("STATUS: Delete a following\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input the ID to unfollow:\n");
                int following;
                scanf("%d",&following); fflush(stdin);

                Delete_following(hashtable,id,following,1);

                fflush(stdin);getchar();
                break;
            }

        case 15:
            {
                printf("STATUS: Modify a following person\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input the old ID to modify:\n");
                int old_following;
                scanf("%d",&old_following); fflush(stdin);

                printf("STATUS: Input the new person's ID to follow:\n");
                int following;
                scanf("%d",&following); fflush(stdin);

                Modify_following(hashtable,id,old_following,following,1);


                fflush(stdin);getchar();
                break;
            }

        case 16:
            {
                printf("STATUS: Find a following person\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input the ID to find:\n");
                int following;
                scanf("%d",&following); fflush(stdin);

                Find_following(hashtable,id,following);

                fflush(stdin);getchar();
                break;
            }

        case 17:
            {
                printf("STATUS: Add a hobby\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                printf("STATUS: Input the new hobby:\n");
                char hobby[20];
                scanf("%s",hobby); fflush(stdin);

                Add_hobby(hashtable,id,hobby);

                fflush(stdin);getchar();
                break;
            }

        case 18:
            {
                printf("STATUS: Show two user's common following\n");
                printf("STATUS: Input one user's ID:\n        ");
                int id1;
                scanf("%d",&id1); fflush(stdin);
                printf("STATUS: Input another user's ID:\n        ");
                int id2;
                scanf("%d",&id2); fflush(stdin);

                Common_following(id1,id2,hashtable);

                fflush(stdin);getchar();
                break;
            }
        case 19:
            {
                printf("STATUS: Show two user's common hobbies\n");
                printf("STATUS: Input one user's ID:\n        ");
                int id1;
                scanf("%d",&id1); fflush(stdin);
                printf("STATUS: Input another user's ID:\n        ");
                int id2;
                scanf("%d",&id2); fflush(stdin);

                Common_hobby(id1,id2,hashtable,1);


                fflush(stdin);getchar();
                break;
            }

        case 20:
            {
                printf("STATUS: Show friend's friend\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                Friend_Friend(id,hashtable);

                fflush(stdin);getchar();
                break;
            }
        case 21:
            {
                printf("STATUS: Show all users\n");
                printf("   ID      Name    friend  follower following     hobby\n");
                Traverse_Hash(hashtable,Visit_Hash);

                fflush(stdin);getchar();
                break;
            }
        case 22:
            {
                printf("STATUS: Show one user's all friends\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                HashNode_Ptr node=Search_Hash(hashtable,id);
                if(node)
                {
                    Traverse_AVL(node->friends->Tree->root,hashtable,show_visit);
                }
                else printf("No such user\n");


                fflush(stdin);getchar();
                break;
            }
        case 23:
            {
                printf("STATUS: Show one user's all followers\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                HashNode_Ptr node=Search_Hash(hashtable,id);
                if(node)
                {
                    Traverse_AVL(node->followers->Tree->root,hashtable,show_visit);
                }
                else printf("No such user\n");


                fflush(stdin);getchar();
                break;
            }
        case 24:
            {
                printf("STATUS: Show one user's all followings\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                HashNode_Ptr node=Search_Hash(hashtable,id);
                if(node)
                {
                    Traverse_AVL(node->following->Tree->root,hashtable,show_visit);
                }
                else printf("No such user\n");


                fflush(stdin);getchar();
                break;
            }
        case 25:
            {
                printf("STATUS: Show one user's all hobbies\n");
                printf("STATUS: Input target user's ID:\n        ");
                int id;
                scanf("%d",&id); fflush(stdin);

                HashNode_Ptr node=Search_Hash(hashtable,id);
                int i;
                if(node)
                {
                    for(i=1;i<=node->hobby->num;i++)
                    {
                        printf("        %s\n",node->hobby[i].hobby);
                    }
                }
                else printf("No such user\n");


                fflush(stdin);getchar();
                break;
            }
        case 26:
            {
                printf("STATUS: Save data to file\n");
                FILE* save=fopen(filename,"wb");
                save_hash(hashtable,save);
                fclose(save);

                if(mode) modify_file_num(number,1);

                printf("STATUS: Data saved\n");
                fflush(stdin); getchar();
                break;
            }
        case 27:
            {
                printf("STATUS: Recommend friend to a user\n");
                printf("Input the target user ID:");
                int id;
                scanf("%d",&id); fflush(stdin);

                if(Search_Hash(hashtable,id))
                {
                    printf("\n\nSort by recommended level:\n\n");
                    Recommend_friend(id,hashtable);
                }
                else printf("No such user\n");


                fflush(stdin); getchar();
                break;


            }



        case 0:
         break;
	}
  }

}

else if(run_mode==AVL)
{
    int op1=1;
    AVL_Tree_Ptr tree=NULL;
    while(op1)
    {
        system("cls");
        printf("\n\n");
        printf("              AVL Operations             \n\n");
        printf("     1. InitAVL           2. DestroyAVL    \n");
        printf("     3. SearchAVL         4. InsertAVL     \n");
        printf("     5. DeleteAVL         6. TraverseAVL   \n");
        printf("     0. Exit                               \n\n");
        printf("    Choose your operation[0~6]:");
        scanf("%d",&op1); getchar();
        switch(op1)
        {
        case 1:
            {
                printf("STATUS: Init an AVL tree\n");
                tree=Init_AVL(1,0);
                printf("Succeed\n");

                fflush(stdin); getchar();
                break;

            }
        case 2:
            {
                printf("STATUS: Destroy an AVL tree\n");
                if(!tree) printf("There is no tree\n");
                else
                {
                    Destroy_AVL(tree);
                    tree=NULL;
                    printf("Succeed\n");
                }

                fflush(stdin); getchar();
                break;


            }
        case 3:
            {
                printf("STATUS: Search a node in AVL tree\n");
                printf("input the key: ");
                int key;
                scanf("%d",&key);
                if(tree)
                {
                    AVL_Node_Ptr node=Search_AVL(tree->root, key);
                    if(!node)
                    {
                        printf("no node found\n");
                    }
                    else
                    {
                        if(node->left_child)
                        {
                            printf("left child key: %d\n",node->left_child->key);
                        }
                        if(!node->left_child)
                        {
                            printf("no left child\n");
                        }
                        if(node->right_child)
                        {
                            printf("right child key: %d\n",node->right_child->key);
                        }
                        else printf("no right child\n");

                    }
                }
                else printf("There is no tree\n");

                fflush(stdin); getchar();
                break;

            }

        case 4:
            {
                printf("STATUS: Insert a node to AVL tree\n");
                printf("input the key: ");
                int key;
                scanf("%d",&key);
                if(tree)
                {
                    Insert_AVL(tree,key);
                    printf("Insert done\n");

                }
                else printf("There is no tree\n");

                fflush(stdin); getchar();
                break;


            }

        case 5:
            {
                printf("STATUS: Delete a node in AVL tree\n");
                printf("input the key: ");
                int key;
                scanf("%d",&key);
                if(tree)
                {
                    Delete_AVL(tree,key);
                    printf("Deleted\n");

                }
                else printf("There is no tree\n");

                fflush(stdin); getchar();
                break;

            }
        case 6:
            {
                printf("STATUS: Traverse the AVL tree(inorder)\n");
                if(tree) Traverse_avl_for_test(tree->root);
                else printf("There is no tree\n");


                fflush(stdin); getchar();
                break;

            }
        case 0:
            {
                break;
            }
        }


    }


}

else
{
    Set_Ptr* set_ptr_array=NULL;
    int set_num=0;
    int array_long=0;

    FILE* set_file=fopen("set_data.dat","rb");
    if(set_file)
    {
        fread(&set_num,sizeof(int),1,set_file);
        array_long=set_num;

        set_ptr_array=(Set_Ptr*)malloc(sizeof(Set_Ptr)*set_num);
        int i;
        for(i=0;i<set_num;i++)
        {
            set_ptr_array[i]=load_set(set_file);

        }
        printf("File loaded\nPress ENTER to continue\n"); getchar();
        fclose(set_file);
    }
    else
    {
        set_ptr_array=(Set_Ptr*)malloc(sizeof(Set_Ptr)*5);
        array_long=5;
        set_num=0;
        int i;
        for(i=0;i<5;i++)
        {
            set_ptr_array[i]=NULL;
        }

    }

    int op2=1;

    while(op2)
    {
        system("cls");
        printf("\n\n");
        printf("              Set Operations             \n\n");
        printf("     1. set_init          2. set_destroy    \n");
        printf("     3. set_insert        4. set_remove     \n");
        printf("     5. set_intersection  6. set_union    \n");
        printf("     7. set_difference    8. set_size     \n");
        printf("     9. set_member       10. set_subset   \n");
        printf("    11. set_equal        12. show all the set                 \n");
        printf("    13. save data        14. traverse set                   \n");
        printf("     0. Exit                               \n\n");
        printf("    Choose your operation[0~13]:");
        scanf("%d",&op2); getchar();
        switch(op2)
        {
        case 1:
            {
                printf("STATUS: Init a set\n");
                if(set_num+1>array_long)
                {
                    set_ptr_array=(Set_Ptr*)realloc(set_ptr_array,sizeof(set_num+1));
                    array_long++;
                }

                set_ptr_array[set_num]=init_set(1,set_num+1);
                if(set_ptr_array[set_num])
                {
                    printf("Succeed\n");
                    set_num++;
                }
                else
                {
                    printf("failed\n");
                }


                fflush(stdin); getchar();
                break;

            }
        case 2:
            {
                printf("STATUS: Destroy a set\n");
                if(set_num)
                {
                    printf("There are %d sets, input the number of the target set:",set_num);
                    int number;
                    scanf("%d",&number); fflush(stdin);
                    set_destroy(set_ptr_array[number-1]);
                    set_ptr_array[number-1]=NULL;

                    set_num--;

                    printf("succeed\n");

                }

                else printf("There is no set\n");

                fflush(stdin); getchar();
                break;


            }
        case 3:
            {
                printf("STATUS: Insert an element to a set\n");
                if(set_num)
                {
                    printf("There are %d sets, input the number of the target set:",set_num);
                    int number;
                    scanf("%d",&number); fflush(stdin);

                    int key;
                    printf("input the key of the element: ");
                    scanf("%d",&key);

                    set_insert(set_ptr_array[number-1],key);

                    printf("succeed\n");

                }

                else printf("There is no set\n");

                fflush(stdin); getchar();
                break;

            }

        case 4:
            {
                printf("STATUS: Remove an element in a set\n");
                if(set_num)
                {
                    printf("There are %d sets, input the number of the target set:",set_num);
                    int number;
                    scanf("%d",&number); fflush(stdin);

                    int key;
                    printf("input the key of the element: ");
                    scanf("%d",&key);

                    set_remove(set_ptr_array[number-1],key);

                    printf("succeed\n");

                }

                else printf("There is no set\n");

                fflush(stdin); getchar();
                break;


            }

        case 5:
            {
                printf("STATUS: Get intersection of two sets\n");
                if(set_num-1)
                {
                    printf("There are %d sets, input the number of the set one:",set_num);
                    int number1;
                    scanf("%d",&number1); fflush(stdin);
                    printf("set2: ");
                    int number2;
                    scanf("%d",&number2); fflush(stdin);

                    Set_Ptr intersection=Set_intersection(set_ptr_array[number1-1],set_ptr_array[number2-1]);

                    printf("intersection: \n");
                    Traverse_avl_for_test(intersection->Tree->root);


                }

                else printf("There is no enough set\n");

                fflush(stdin); getchar();
                break;

            }
        case 6:
            {
                printf("STATUS: Get union of two sets\n");
                if(set_num-1)
                {
                    printf("There are %d sets, input the number of the set one:",set_num);
                    int number1;
                    scanf("%d",&number1); fflush(stdin);
                    printf("set2: ");
                    int number2;
                    scanf("%d",&number2); fflush(stdin);

                    Set_Ptr sunion=Set_union(set_ptr_array[number1-1],set_ptr_array[number2-1]);

                    printf("union: \n");
                    Traverse_avl_for_test(sunion->Tree->root);

                }

                else printf("There is no enough set\n");

                fflush(stdin); getchar();
                break;

            }
        case 7:
            {
                printf("STATUS: Get difference of two sets\n");
                if(set_num-1)
                {
                    printf("There are %d sets, input the number of the set1:",set_num);
                    int number1;
                    scanf("%d",&number1); fflush(stdin);
                    printf("set2: ");
                    int number2;
                    scanf("%d",&number2); fflush(stdin);

                    Set_Ptr difference=Set_difference(set_ptr_array[number1-1],set_ptr_array[number2-1]);

                    printf("difference (set1-set2): \n");
                    Traverse_avl_for_test(difference->Tree->root);

                }

                else printf("There is no enough set\n");

                fflush(stdin); getchar();
                break;

            }
        case 8:
            {
                printf("STATUS: Get the size of a set\n");
                if(set_num)
                {
                    printf("There are %d sets, input the number of the target set:",set_num);
                    int number;
                    scanf("%d",&number); fflush(stdin);

                    int size;
                    size=set_size(set_ptr_array[number-1]);

                    printf("size: %d\n",size);

                }

                else printf("There is no set\n");

                fflush(stdin); getchar();
                break;
            }
        case 9:
            {
                printf("STATUS: Judge if an element is member of a set\n");
                if(set_num)
                {
                    printf("There are %d sets, input the number of the target set:",set_num);
                    int number;
                    scanf("%d",&number); fflush(stdin);

                    printf("input the target key:");
                    int key;
                    scanf("%d",&key); fflush(stdin);

                    int judge=set_member(set_ptr_array[number-1],key);
                    if(judge) printf("the element is member the set\n");
                    else printf("the element is NOT a member of the set\n");

                }

                else printf("There is no set\n");

                fflush(stdin); getchar();
                break;
            }
        case 10:
            {
                printf("STATUS: Judge if set1 is subset of set2\n");
                if(set_num-1)
                {
                    printf("There are %d sets, input the number of the set1:",set_num);
                    int number1;
                    scanf("%d",&number1); fflush(stdin);
                    printf("set2: ");
                    int number2;
                    scanf("%d",&number2); fflush(stdin);

                    int issub=set_subset(set_ptr_array[number1-1],set_ptr_array[number2-1]);
                    if(issub) printf("set1 is subset of set2\n");
                    else printf("set1 is NOT subset of set2\n");

                }

                else printf("There is no enough set\n");

                fflush(stdin); getchar();
                break;
            }

        case 11:
            {
                printf("STATUS: Judge if set1 is equal to set2\n");
                if(set_num-1)
                {
                    printf("There are %d sets, input the number of the set1:",set_num);
                    int number1;
                    scanf("%d",&number1); fflush(stdin);
                    printf("set2: ");
                    int number2;
                    scanf("%d",&number2); fflush(stdin);

                    int isequal=set_equal(set_ptr_array[number1-1],set_ptr_array[number2-1]);
                    if(isequal) printf("set1 is equal to set2\n");
                    else printf("set1 is DIFFERENT to set2\n");

                }

                else printf("There is no enough set\n");

                fflush(stdin); getchar();
                break;
            }
        case 12:
            {
                if(!set_num) printf("there is no set\n");
                else
                {
                    int i;
                    for(i=1;i<=set_num;i++)
                    {
                        printf("set%d  element number: %d\n",i,set_ptr_array[i-1]->Tree->quantity);
                    }
                }

                fflush(stdin); getchar();
                break;
            }
        case 13:
            {
                if(set_num)
                {
                    FILE* sav=fopen("set_data.dat","wb");
                    fwrite(&set_num,sizeof(int),1,sav);
                    int i;
                    for(i=0;i<set_num;i++)
                    {
                        save_set(set_ptr_array[i],sav);
                    }

                    printf("data saved\n");
                    fclose(sav);
                }
                else printf("There is no set to save\n");

                fflush(stdin); getchar();
                break;
            }
        case 14:
            {
                if(set_num)
                {
                    printf("There are %d sets, input the number of the target set:",set_num);
                    int number;
                    scanf("%d",&number); fflush(stdin);

                    Traverse_avl_for_test(set_ptr_array[number-1]->Tree->root);

                }

                else printf("There is no set\n");

                fflush(stdin); getchar();
                break;

            }
        case 0:
            {
                break;
            }
        }


    }



}


return 0;

}
