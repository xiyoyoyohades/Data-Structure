#include "avl.h"

AVL_Tree_Ptr Init_AVL(int type, int ID)
{
    AVL_Tree_Ptr new_tree=(AVL_Tree_Ptr)malloc(sizeof(AVL_Tree));
    if(!new_tree)   return NULL;

    new_tree->type=type;
    new_tree->ID=ID;
    new_tree->root=NULL;
    new_tree->quantity=0;
    return new_tree;

}

AVL_Node_Ptr clear_tree(AVL_Node_Ptr root)
{
  if (root == NULL) return NULL;

  if (root->left_child != NULL)
  {
    root->left_child = clear_tree(root->left_child);
  }
  if (root->right_child != NULL)
  {
    root->right_child = clear_tree(root->right_child);
  }

  AVL_Node_Ptr temp = root;
  root = NULL;
  free(temp);
  return root;
}

void Clear_AVL(AVL_Tree_Ptr tree)
{
    tree->root=clear_tree(tree->root);
    tree->quantity=0;
}

void Destroy_AVL(AVL_Tree_Ptr tree)
{
  tree->root=clear_tree(tree->root);
  free(tree);
}

AVL_Node_Ptr Search_AVL(AVL_Node_Ptr root, int key)
{
  if(root==NULL)   return NULL;
  if(root->key==key)   return root;
  if(root->key>key)  return Search_AVL(root->left_child, key);
  else
  {
      return Search_AVL(root->right_child, key);
  }

}


int get_height(AVL_Node_Ptr root)
{
    if(!root) return 0;
    else return 1 + max(get_height(root->left_child), get_height(root->right_child));
}

AVL_Node_Ptr LLRotate(AVL_Node_Ptr node_a)
{
    AVL_Node_Ptr node_b=node_a->left_child;
    node_a->left_child=node_b->right_child;
    node_b->right_child=node_a;
    node_a->height = 1 + max(get_height(node_a->left_child), get_height(node_a->right_child));
    node_b->height = 1 + max(get_height(node_b->left_child), get_height(node_b->right_child));
    return node_b;
}

AVL_Node_Ptr RRRotate(AVL_Node_Ptr node_a)
{
    AVL_Node_Ptr node_b=node_a->right_child;
    node_a->right_child =node_b->left_child;
    node_b->left_child =node_a;
    node_a->height = 1 + max(get_height(node_a->left_child), get_height(node_a->right_child));
    node_b->height = 1 + max(get_height(node_b->left_child), get_height(node_b->right_child));
    return node_b;
}

AVL_Node_Ptr LRRotate(AVL_Node_Ptr node_a)
{
    node_a->left_child=RRRotate(node_a->left_child);
    return LLRotate(node_a);
}

AVL_Node_Ptr RLRotate(AVL_Node_Ptr node_a)
{
    node_a->right_child=LLRotate(node_a->right_child);
    return RRRotate(node_a);
}

AVL_Node_Ptr insert_node(AVL_Node_Ptr root, int key ,int *isdone)
{
    if(!root)
    {
        root=(AVL_Node_Ptr)malloc(sizeof(AVL_Node));
        root->key=key;
        root->height=0;
        root->left_child=NULL;
        root->right_child=NULL;
    }
    else
    {
            if(key==root->key)
            {
                *isdone=0;
            }

            else if(key<root->key)
            {
                root->left_child = insert_node(root->left_child, key, isdone);
                if(get_height(root->left_child)-get_height(root->right_child)>1)
                {
                    if(key<root->left_child->key)  root=LLRotate(root);
                    else  root=LRRotate(root);
                }
            }

            else
            {
                root->right_child = insert_node(root->right_child, key, isdone);
                if (get_height(root->right_child) - get_height(root->left_child)>1)
                {
                    if (key < root->right_child->key)   root= RLRotate(root);
                    else    root=RRRotate(root);
                }
            }
    }


    root->height = 1 + max(get_height(root->left_child), get_height(root->right_child));
    return root;
}

AVL_Node_Ptr delete_node(AVL_Node_Ptr root,AVL_Node_Ptr target)
{
    if(!root||!target)   return NULL;
    if(target->key <root->key)
    {
        root->left_child=delete_node(root->left_child, target);

        if (get_height(root->right_child)-get_height(root->left_child)>1)
        {
            if (get_height(root->right_child->left_child) > get_height(root->right_child->right_child))
            {
                root=RLRotate(root);
            }
            else    root=RRRotate(root);
        }
    }

    else if (target->key > root->key)
    {
        root->right_child = delete_node(root->right_child, target);

        if (get_height(root->left_child) - get_height(root->right_child)>1)
        {
            if (get_height(root->left_child->left_child) > get_height(root->left_child->right_child))
            {
                root=LLRotate(root);
            }
            else    root=LRRotate(root);
        }
    }

    else
    {

        if (!(root->left_child || root->right_child))
        {
            AVL_Node_Ptr ptr=root;
            root=NULL;
            free(ptr);
        }

        else if (root->left_child && root->right_child)
        {

            if (get_height(root->left_child) > get_height(root->right_child))
            {
                AVL_Node_Ptr max_node = get_max(root->left_child);
                root->key = max_node->key;
                root->left_child = delete_node(root->left_child, max_node);
            }

            else
            {
                AVL_Node_Ptr min_node = get_min(root->right_child);
                root->key = min_node->key;
                root->right_child = delete_node(root->right_child, min_node);
            }
        }

        else
        {
            AVL_Node_Ptr ptr=root;
            if(root->left_child) root=root->left_child;
            else
            {
                root=root->right_child;
            }
            free(ptr);
        }
    }

  return root;
}

void Insert_AVL(AVL_Tree_Ptr tree, int key)
{
    int isdone=TRUE;
    tree->root = insert_node(tree->root, key, &isdone);
    if(isdone)  (tree->quantity)++;
}

void Delete_AVL(AVL_Tree_Ptr tree, int key)
{
    AVL_Node_Ptr target=Search_AVL(tree->root, key);
    if (target)
    {

        tree->root = delete_node(tree->root, target);
        tree->quantity--;
    }
}

AVL_Node_Ptr get_min(AVL_Node_Ptr root)
{
    if(!(root->left_child))   return root;
    else    return get_min(root->left_child);
}

AVL_Node_Ptr get_max(AVL_Node_Ptr root)
{
    if(!(root->right_child))   return root;
    else    return get_max(root->right_child);
}

void Traverse_AVL(AVL_Node_Ptr root,HashTable_Ptr hashtable, void (*visit)(int,HashTable_Ptr))
{
    if(!root)   return;

    Traverse_AVL(root->left_child,hashtable,visit);
    (*visit)(root->key,hashtable);
    Traverse_AVL(root->right_child,hashtable,visit);
}

void Traverse_avl_for_test(AVL_Node_Ptr root)
{
    if(!root) return;
    Traverse_avl_for_test(root->left_child);
    printf("key: %d  height: %d\n",root->key,root->height);
    Traverse_avl_for_test(root->right_child);

}
