#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED


 #include <stdio.h>
 #include <stdlib.h>
 #include <malloc.h>
 #include <string.h>
 #include "HashTable.h"

#define max(a,b) ((a>b)?a:b)
#define TRUE 1
#define FALSE 0


 typedef struct AVL_Node {
  int key;
  int height;
  struct AVL_Node *left_child;
  struct AVL_Node *right_child;
} AVL_Node, *AVL_Node_Ptr;


typedef struct AVL_Tree {
  int type;
  int ID;
  int quantity;
  struct AVL_Node *root;
} AVL_Tree, *AVL_Tree_Ptr;


AVL_Tree_Ptr Init_AVL(int type,int ID);
void Clear_AVL(AVL_Tree_Ptr tree);
AVL_Node_Ptr Search_AVL(AVL_Node_Ptr root, int key);
void Destroy_AVL(AVL_Tree_Ptr tree);
void Insert_AVL(AVL_Tree_Ptr tree, int key);
void Delete_AVL(AVL_Tree_Ptr tree, int key);
void Traverse_AVL(AVL_Node_Ptr root,HashTable_Ptr hashtable, void (*visit)(int,HashTable_Ptr));

AVL_Node_Ptr clear_tree(AVL_Node_Ptr root);
int get_height(AVL_Node_Ptr root);
AVL_Node_Ptr LLRotate(AVL_Node_Ptr node_a);
AVL_Node_Ptr RRRotate(AVL_Node_Ptr node_a);
AVL_Node_Ptr LRRotate(AVL_Node_Ptr node_a);
AVL_Node_Ptr RLRotate(AVL_Node_Ptr node_a);
AVL_Node_Ptr insert_node(AVL_Node_Ptr root, int key ,int *isdone);
AVL_Node_Ptr delete_node(AVL_Node_Ptr root,AVL_Node_Ptr target);
AVL_Node_Ptr get_min(AVL_Node_Ptr root);
AVL_Node_Ptr get_max(AVL_Node_Ptr root);
void Traverse_avl_for_test(AVL_Node_Ptr root);


#endif // AVL_H_INCLUDED
