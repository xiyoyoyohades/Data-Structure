#include"set.h"

Set_Ptr init_set(int type, int ID)
{
    Set_Ptr new_set=(Set_Ptr)malloc(sizeof(Set));
    new_set->Tree=Init_AVL(type,ID);
    new_set->type=type;
    return new_set;
}

void set_destroy(Set_Ptr target)
{
    Destroy_AVL(target->Tree);
    target->Tree=NULL;
}

void set_insert(Set_Ptr set,int content)
{
    Insert_AVL(set->Tree,content);
}

void set_remove(Set_Ptr set,int content)
{
    Delete_AVL(set->Tree,content);
}

void get_intersection(int key,Set_Ptr Another_set,Set_Ptr result)
{
    AVL_Node_Ptr ptr=Search_AVL(Another_set->Tree->root,key);
    if(ptr) Insert_AVL(result->Tree,ptr->key);
}

void get_union(int key,Set_Ptr Another_set,Set_Ptr result)
{
    Insert_AVL(result->Tree,key);
}

void get_difference(int key,Set_Ptr Another_set,Set_Ptr result)
{
    AVL_Node_Ptr ptr=Search_AVL(Another_set->Tree->root,key);
    if(!ptr) Insert_AVL(result->Tree,key);
}

void Traverse_one_set(AVL_Node_Ptr one_set_tree, Set_Ptr another_set, Set_Ptr result, void (*get_result)(int, Set_Ptr ,Set_Ptr))
{
    if(!one_set_tree) return;
    Traverse_one_set(one_set_tree->left_child,another_set,result, get_result);
    get_result(one_set_tree->key,another_set,result);
    Traverse_one_set(one_set_tree->right_child,another_set,result,get_result);
}

Set_Ptr Set_intersection(Set_Ptr set1, Set_Ptr set2)
{
    Set_Ptr new_set=init_set(set1->Tree->type, set1->Tree->ID);
    Traverse_one_set(set1->Tree->root,set2,new_set,get_intersection);
    return new_set;
}

Set_Ptr Set_union(Set_Ptr set1, Set_Ptr set2)
{
    Set_Ptr new_set=init_set(set1->Tree->type, set1->Tree->ID);
    Traverse_one_set(set1->Tree->root,set2,new_set,get_union);
    Traverse_one_set(set2->Tree->root,set1,new_set,get_union);
    return new_set;
}

Set_Ptr Set_difference(Set_Ptr set1, Set_Ptr set2)
{
    Set_Ptr new_set=init_set(set1->Tree->type, set1->Tree->ID);
    Traverse_one_set(set1->Tree->root,set2,new_set,get_difference);
    return new_set;
}

int set_size(Set_Ptr set)
{
    if(!set||!(set->Tree)) return 0;
    return set->Tree->quantity;
}

int set_member(Set_Ptr set, int key)
{
    AVL_Node_Ptr ptr=Search_AVL(set->Tree->root,key);
    if(ptr) return 1;
    else return 0;
}

int set_subset(Set_Ptr set1, Set_Ptr set2)
{
    Set_Ptr new_set=Set_difference(set1,set2);
    if(new_set->Tree->quantity) return 0;
    else return 1;
}

int set_equal(Set_Ptr set1, Set_Ptr set2)
{
    if(set_subset(set1,set2)&&set_subset(set2,set1)) return 1;
    else return 0;
}


