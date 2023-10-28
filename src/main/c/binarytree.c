#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_TREE_PRIVATE
#include "binarytree.h"

struct BinaryTree {
	const char* key;
	const char* value;
	BinaryTree* left_child;
	BinaryTree* right_child;
};

BinaryTree* new_empty_tree() {
    return NULL;
}

BinaryTree* new_root(const char* key, const char* value) {
    BinaryTree* tree = malloc(sizeof(BinaryTree));
    
    tree->key = key;
    tree->value = value;
    tree->left_child = new_empty_tree();
    tree->right_child = new_empty_tree();
    
    return tree;
}

BinaryTree* new_tree(int size, const char* const* keys, const char* const* values) {
    BinaryTree* tree = new_empty_tree();
    
    for (int i = 0; i < size; ++i) {
        BinaryTree* sub_tree = new_root(keys[i], values[i]);
        insert_tree(&tree, sub_tree);
    }
    
    return tree;
}

BinaryTree** get_tree(BinaryTree** tree, const char* key) {
    BinaryTree** next_tree;
    
    for (
        next_tree = get_next_tree(tree, key);
        next_tree != tree;
        tree = next_tree,
        next_tree = get_next_tree(tree, key)
    );
    
    return next_tree;
}

BinaryTree** get_next_tree(BinaryTree** tree, const char* key) {
    if (*tree) {
        int comparison = strcmp(key, (*tree)->key);
        
        if (comparison < 0) {
            return &(*tree)->left_child;
        } else if (comparison > 0) {
            return &(*tree)->right_child;
        }
    }
    
    return tree;
}

void insert_tree(BinaryTree** parent, BinaryTree* child) {
    if (child) {
        if (child->left_child) {
            insert_tree(parent, child->left_child);
            child->left_child = new_empty_tree();
        }
        
        if (child->right_child) {
            insert_tree(parent, child->right_child);
            child->right_child = new_empty_tree();
        }
        
        if (*parent) {
            BinaryTree** target = get_next_tree(parent, child->key);
            
            if (parent == target) {
                (*parent)->value = child->value;
            } else {
                insert_tree(target, child);
            }
        } else {
            *parent = child;
        }
        
        rebalance_tree(parent);
    }
}

void rebalance_tree(BinaryTree** tree) {
    if (*tree) {
        int left_height = tree_height((*tree)->left_child);
        int right_height = tree_height((*tree)->right_child);
        
        if (left_height >= right_height + 2) {
            left_height = tree_height((*tree)->left_child->left_child);
            right_height = tree_height((*tree)->left_child->right_child);
            
            if (left_height > right_height) {
                tree_left_left(tree);
            } else {
                tree_left_right(tree);
            }
        } else if (left_height + 2 <= right_height) {
            left_height = tree_height((*tree)->right_child->left_child);
            right_height = tree_height((*tree)->right_child->right_child);
            
            if (left_height < right_height) {
                tree_right_right(tree);
            } else {
                tree_right_left(tree);
            }
        }
    }
}

void tree_left_left(BinaryTree** tree) {
    BinaryTree* new_root = (*tree)->left_child;
    (*tree)->left_child = new_root->right_child;
    new_root->right_child = *tree;
    *tree = new_root;
}

void tree_right_right(BinaryTree** tree) {
    BinaryTree* new_root = (*tree)->right_child;
    (*tree)->right_child = new_root->left_child;
    new_root->left_child = *tree;
    *tree = new_root;
}

void tree_left_right(BinaryTree** tree) {
    tree_right_right(&(*tree)->left_child);
    tree_left_left(tree);
}

void tree_right_left(BinaryTree** tree) {
    tree_left_left(&(*tree)->right_child);
    tree_right_right(tree);
}

void remove_tree(BinaryTree** tree, const char* key) {
    delete_tree(get_tree(tree, key));
    rebalance_tree(tree);
}

void delete_tree(BinaryTree** tree) {
    if (*tree) {
        delete_tree(&(*tree)->left_child);
        delete_tree(&(*tree)->right_child);
        free(*tree);
        *tree = new_empty_tree();
    }
}

int tree_size(const BinaryTree* tree) {
    if (tree) {
        return 1 + tree_size(tree->left_child) + tree_size(tree->right_child);
    }
    
    return 0;
}

int tree_height(const BinaryTree* tree) {
    if (tree) {
        int left_height = tree_height(tree->left_child);
        int right_height = tree_height(tree->right_child);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
    
    return 0;
}

const char* get_tree_value(BinaryTree* tree, const char* key) {
    BinaryTree** target = get_tree(&tree, key);
    return *target ? (*target)->value : "";
}

void set_tree_value(BinaryTree* tree, const char* key, const char* value) {
    BinaryTree** target = get_tree(&tree, key);
    
    if (*target) {
        (*target)->value = value;
    }
}

void print_tree(const BinaryTree* tree) {
    print_tree_level(tree, 0);
}

void print_tree_level(const BinaryTree* tree, int level) {
    if (tree) {
        print_tree_level(tree->left_child, level + 1);
        
        for (int i = 0; i < level; ++i) {
            printf(" ");
        }
        
        printf("%s: %s\n", tree->key, tree->value);
        print_tree_level(tree->right_child, level + 1);
    } else if (!level) {
        printf("Empty Tree\n");
    }
}

void print_tree_size(const BinaryTree* tree) {
    printf("%d\n", tree_size(tree));
}

void print_tree_height(const BinaryTree* tree) {
    printf("%d\n", tree_height(tree));
}

void print_tree_value(BinaryTree* tree, const char* key) {
    printf("%s = %s\n", key, get_tree_value(tree, key));
}
