#include <stdio.h>
#include <Windows.h>
#include "container.h"

#define TREE_SIZE 15

const char* KEYS_A[TREE_SIZE] = {
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
};

const char* KEYS_B[TREE_SIZE] = {
    "o",
    "n",
    "m",
    "l",
    "k",
    "j",
    "i",
    "h",
    "g",
    "f",
    "e",
    "d",
    "c",
    "b",
    "a",
};

const char* KEYS_C[TREE_SIZE] = {
    "a",
    "o",
    "b",
    "n",
    "c",
    "m",
    "d",
    "l",
    "e",
    "k",
    "f",
    "j",
    "g",
    "i",
    "h",
};

const char* KEYS_D[TREE_SIZE] = {
    "o",
    "a",
    "n",
    "b",
    "m",
    "c",
    "l",
    "d",
    "k",
    "e",
    "j",
    "f",
    "i",
    "g",
    "h",
};

const char* KEYS_E[TREE_SIZE] = {
    "h",
    "d",
    "l",
    "b",
    "f",
    "j",
    "n",
    "a",
    "c",
    "e",
    "g",
    "i",
    "k",
    "m",
    "o",
};

const char* VALUES[TREE_SIZE] = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15"
};

int main() {
    BinaryTree* tree = new_empty_tree();
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    delete_tree(&tree);
    
    tree = new_root("username", "Chigozie Agomo");
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    delete_tree(&tree);
    
    tree = new_tree(TREE_SIZE, KEYS_A, VALUES);
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    delete_tree(&tree);
    
    tree = new_tree(TREE_SIZE, KEYS_B, VALUES);
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    delete_tree(&tree);
    
    tree = new_tree(TREE_SIZE, KEYS_C, VALUES);
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    delete_tree(&tree);
    
    tree = new_tree(TREE_SIZE, KEYS_D, VALUES);
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    delete_tree(&tree);
    
    tree = new_tree(TREE_SIZE, KEYS_E, VALUES);
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    printf("\n");
    print_tree_value(tree, "f");
    print_tree_value(tree, "i");
    
    remove_tree(&tree, "l");
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    
    set_tree_value(tree, "d", "1999");
    set_tree_value(tree, "zero", "My Final Value");
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    
    insert_tree(&tree, new_tree(TREE_SIZE / 2, KEYS_B, VALUES));
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    
    insert_tree(&tree, new_tree(TREE_SIZE, KEYS_A, VALUES));
    printf("\n");
    print_tree(tree);
    print_tree_size(tree);
    print_tree_height(tree);
    delete_tree(&tree);
    
	return 0;
}
