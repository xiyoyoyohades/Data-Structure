#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include "avl.h"
#include "set.h"
#include "HashTable.h"


HashNode_Ptr check_validation(HashTable_Ptr hashtable, int id);

void Add_user(HashTable_Ptr hashtable, int new_id, char* new_name);
int Add_friend(HashTable_Ptr hashtable, int user_id, int friend_id,int flag);
int Add_follower(HashTable_Ptr hashtable, int user_id,int follower_id, int flag);
int Add_following(HashTable_Ptr hashtable, int user_id,int following_id, int flag);
int Add_hobby(HashTable_Ptr hashtable, int user_id, char* new_hobby);

void Delete_user(HashTable_Ptr hashtable, int id);
int Delete_friend(HashTable_Ptr hashtable, int user_id, int friend_id,int flag);
int Delete_follower(HashTable_Ptr hashtable, int user_id, int follower_id,int flag);
int Delete_following(HashTable_Ptr hashtable, int user_id, int following_id,int flag);

void Modify_user_name(HashTable_Ptr hashtable, char* new_name, int id);
void Modify_friend(HashTable_Ptr hashtable, int user_id, int friend_id,int new_friend, int flag);
void Modify_follower(HashTable_Ptr hashtable, int user_id, int follower_id,int new_follower, int flag);
void Modify_following(HashTable_Ptr hashtable, int user_id, int following_id,int new_following, int flag);

void Find_user(HashTable_Ptr hashtable, int id);
void Find_friend(HashTable_Ptr hashtable, int user_id, int friend_id);
void Find_follower(HashTable_Ptr hashtable, int user_id, int follower_id);
void Find_following(HashTable_Ptr hashtable, int user_id, int following_id);

void show_visit(int id, HashTable_Ptr hashtable);

void Common_following(int id1, int id2, HashTable_Ptr hashtable);
int Common_hobby(int id1, int id2, HashTable_Ptr hashtable,int outmode);
int Common_friend_num(int id1, int id2, HashTable_Ptr hashtable);
Set_Ptr Friend_Friend(int id, HashTable_Ptr hashtable);
void Recommend_friend(int id, HashTable_Ptr hashtable);

int file_num();
void modify_file_num(int num,int mode);
#endif // FUNCTION_H_INCLUDED
