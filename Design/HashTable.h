#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


#define HASH_LENGTH 256

typedef struct HashTable{
    int record_num;
    int length;
    struct HashBlock* Block;
}HashTable, *HashTable_Ptr;

typedef struct HashBlock{
    int Block_record_num;
    struct HashNode* Block_List;
}HashBlock;

typedef struct HashNode{
    int key;
    char name[20];
    struct HashNode* next;
    struct Set* friends;
    struct Set* followers;
    struct Set* following;
    struct Hobby_node* hobby;

}HashNode, *HashNode_Ptr;


int Hash_Function(int key,int length);
HashTable_Ptr Init_HashTable(int length);
int Insert_Hash_Record(HashTable_Ptr hashtable, int key, char* name);
int Delete_Hash_Record(HashTable_Ptr hashtable, int key);
HashNode_Ptr Search_Hash(HashTable_Ptr hashtable, int key);
void Traverse_Hash(HashTable_Ptr hashtable, void (*visit)(HashNode_Ptr));
void Visit_Hash(HashNode_Ptr node);

#endif // HASHTABLE_H_INCLUDED
