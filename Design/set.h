#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include "avl.h"

#define Friends 1
#define Followers 2
#define Following 3


typedef struct Set {
  AVL_Tree_Ptr Tree;
  int type;
} Set, *Set_Ptr;

typedef struct Hobby_node{
    char hobby[20];
    int num;
}hobby_node, *hobby_ptr;

void get_intersection(int key,Set_Ptr Another_set,Set_Ptr result);
void get_union(int key,Set_Ptr Another_set,Set_Ptr result);
void get_difference(int key,Set_Ptr Another_set,Set_Ptr result);
void Traverse_one_set(AVL_Node_Ptr one_set_tree, Set_Ptr another_set, Set_Ptr result, void (*get_result)(int, Set_Ptr ,Set_Ptr));

Set_Ptr init_set(int type, int ID);
void set_destroy(Set_Ptr target);
void set_insert(Set_Ptr set,int content);
void set_remove(Set_Ptr set,int content);
Set_Ptr Set_intersection(Set_Ptr set1, Set_Ptr set2);
Set_Ptr Set_union(Set_Ptr set1, Set_Ptr set2);
Set_Ptr Set_difference(Set_Ptr set1, Set_Ptr set2);
int set_size(Set_Ptr set);
int set_member(Set_Ptr set, int key);
int set_subset(Set_Ptr set1, Set_Ptr set2);
int set_equal(Set_Ptr set1, Set_Ptr set2);


#endif // SET_H_INCLUDED
