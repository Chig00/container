#pragma once

typedef struct BinaryTree BinaryTree;

BinaryTree* new_empty_tree();
BinaryTree* new_root(const char* key, const char* value);
BinaryTree* new_tree(int size, const char* const* keys, const char* const* values);

BinaryTree** get_tree(BinaryTree** tree, const char* key);
BinaryTree** get_next_tree(BinaryTree** tree, const char* key);

void insert_tree(BinaryTree** parent, BinaryTree* child);

void remove_tree(BinaryTree** tree, const char* key);
void delete_tree(BinaryTree** tree);

int tree_size(const BinaryTree* tree);
int tree_height(const BinaryTree* tree);

const char* get_tree_value(BinaryTree* tree, const char* key);
void set_tree_value(BinaryTree* tree, const char* key, const char* value);

void print_tree(const BinaryTree* tree);
void print_tree_size(const BinaryTree* tree);
void print_tree_height(const BinaryTree* tree);
void print_tree_value(BinaryTree* tree, const char* key);

#ifdef BINARY_TREE_PRIVATE
void rebalance_tree(BinaryTree**);
void tree_left_left(BinaryTree**);
void tree_right_right(BinaryTree**);
void tree_left_right(BinaryTree**);
void tree_right_left(BinaryTree**);
void print_tree_level(const BinaryTree*, int);
#endif
