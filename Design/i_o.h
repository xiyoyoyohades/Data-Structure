#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

void save_avl(AVL_Node_Ptr root, FILE* fp);
void save_set(Set_Ptr set, FILE* fp);
void save_hash(HashTable_Ptr hashtable, FILE* fp);

AVL_Node_Ptr load_avl(FILE* fp);
Set_Ptr load_set(FILE* fp);
HashTable_Ptr load_hash(FILE* fp);

#endif // IO_H_INCLUDED
