#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * TODO: WRITE TESTER CODE
 * TODO: ADD TIME COMPLEXITIES TO MAIN.C FUNCTIONS
 */

void print_tree(node_t *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("Element: %d\n", root->element);

    if (root->left_child != NULL) {
       printf("Left Node of %d - ", root->element); 
       print_tree(root->left_child);
    }

    if (root->right_child != NULL) {
        printf("Right Node of %d - ", root->element); 
        print_tree(root->right_child);
    }
}

void test_insert_search_delete() {
    tree_t *tree = create_tree();

    printf("\nInsert all elements ---\n");                                                 
    insert(tree, 12);                                                                 
    insert(tree, 9);                                                            
    insert(tree, 26);                                                           
    insert(tree, 3);                                                          
    insert(tree, 11);                                                        
    insert(tree, 24);                                                       
    insert(tree, 30);                                                                       
    insert(tree, 2);                                                              
    insert(tree, 5);                                    
    insert(tree, 22);                                   
    insert(tree, 29);                                   
    insert(tree, 31);                                   
    insert(tree, 20);       
    /*
                 _______12_______
                |                |
           _____9____        ____26____
          |          |      |          |
        __3__        11   __24       __30__
       |     |           |          |      |
       2     5        __22         29      31
                     |
                    20
    */                            
    print_tree(tree->root);

    printf("\nRemove 11 ---\n");
    node_t *node = search(tree, 11);     
    remove_node(tree, tree->root, node);                                            
    /*
                 _______12_______
                |                |
           _____9            ____26____
          |                 |          |
        __3__             __24       __30__
       |     |           |          |      |
       2     5        __22         29      31
                     |
                    20
    */                            
    print_tree(tree->root);

    printf("\nRemove 24 ---\n");
    node = search(tree, 24);     
    remove_node(tree, tree->root, node);                                            
    /*
                 _______12_______
                |                |
           _____9            ____26____
          |                 |          |
        __3__             __22       __30__
       |     |           |          |      |
       2     5          20         29      31
    */                            
    print_tree(tree->root);

    printf("\nRemove 30 ---\n");
    node = search(tree, 30);     
    remove_node(tree, tree->root, node);                                            
    /*
                 _______12_______
                |                |
           _____9            ____26____
          |                 |          |
        __3__             __22       __31
       |     |           |          |      
       2     5          20         29      
    */                            
    print_tree(tree->root);

    printf("\nRemove 26 ---\n");
    node = search(tree, 26);     
    remove_node(tree, tree->root, node);                                            
    /*
                 _______12_______
                |                |
           _____9            ____29____
          |                 |          |
        __3__             __22         31
       |     |           |                
       2     5          20               
    */                            
    print_tree(tree->root);

    printf("\nRemove 12 ---\n");
    node = search(tree, 12);     
    remove_node(tree, tree->root, node);                                            
    /*
                 _______20_______
                |                |
           _____9            ____29____
          |                 |          |
        __3__               22         31
       |     |                       
       2     5                        
    */                            
    print_tree(tree->root);

    printf("\nRemove 9 ---\n");
    node = search(tree, 9);     
    remove_node(tree, tree->root, node);                                            
    /*
                 _______20_______
                |                |
           _____3____        ____29____
          |          |      |          |
          2          5      22         31
    */                            
    print_tree(tree->root);

    printf("\nRemove 20 ---\n");
    node = search(tree, 20);     
    remove_node(tree, tree->root, node);                                            
    /*
                 _______22_______
                |                |
           _____3____            29____
          |          |                 |
          2          5                 31
    */                            
    print_tree(tree->root);

    printf("\nRemove 5 ---\n");
    node = search(tree, 5);     
    remove_node(tree, tree->root, node);                                            
    /*
                 _______22_______
                |                |
           _____3                29____
          |                            |
          2                            31
    */                            
    print_tree(tree->root);

    printf("\nRemove 22 ---\n");
    node = search(tree, 22);     
    remove_node(tree, tree->root, node);                                            
    /*
                 _______29_______
                |                |
           _____3                31
          |                           
          2                           
    */                            
    print_tree(tree->root);

    printf("\nRemove 29 ---\n");
    node = search(tree, 29);     
    remove_node(tree, tree->root, node);                                            
    /*
                 _______31
                |                
           _____3                
          |                           
          2                           
    */                            
    print_tree(tree->root);

    printf("\nRemove 31 ---\n");
    node = search(tree, 31);    
    remove_node(tree, tree->root, node);                                            
    /*
                 ______3                
                |                           
                2                           
    */                            
    print_tree(tree->root);

    printf("\nRemove 3 ---\n");
    node = search(tree, 3);    
    remove_node(tree, tree->root, node);                                            
    /*
                       2               
    */                            
    print_tree(tree->root);

    printf("\nRemove 2 ---\n");
    node = search(tree, 2);    
    remove_node(tree, tree->root, node);                                            
    /*
        Tree is empty
    */                            
    print_tree(tree->root);

    printf("\nInsert items into right subtree only ---\n");
    insert(tree, 20);
    insert(tree, 25);
    insert(tree, 30);
    /*
                        20_______
                                 |
                                 25____
                                       |
                                       30
    */                            
    print_tree(tree->root);

    printf("\nRemove 20 ---\n");
    node = search(tree, 20);    
    remove_node(tree, tree->root, node);                                            
    /*
                        25_______
                                 |
                                 30
    */   
    print_tree(tree->root);

    printf("\nRemove 25 ---\n");
    node = search(tree, 25);    
    remove_node(tree, tree->root, node);                                            
    /*
                        30
    */   
    print_tree(tree->root);

    printf("\nRemove 30 ---\n");
    node = search(tree, 30);    
    remove_node(tree, tree->root, node);                                            
    /*
        Tree is empty
    */    
    print_tree(tree->root);

    destroy_tree(tree);
}

void test_all_functions_regular_cases() {
    tree_t *tree = create_tree();

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 0
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 1 (True)
    printf("The root of the tree is %p\n", root(tree)); // The root of the tree is 0x0 (NULL)
    printf("The parent of the root is %p because the root is NULL\n", parent(tree->root)); // The parent of the root is 0x0 (NULL)
    printf("The number of children of the root is %d because the root is NULL\n", num_children(tree->root)); // The number of children of the root is 0
    printf("Is the root internal? %d because the root is NULL\n", is_internal(tree->root)); // Is the root internal? 0 (False)
    printf("Is the root external? %d because the root is NULL\n", is_external(tree->root)); // Is the root external? 1 (True)
    printf("Is the root the root? %d because the root is NULL\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    pre_order(tree->root);
    printf("\n");
    post_order(tree->root);
    printf("The depth of the root is %d because the root is NULL\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d because the root is NULL\n", height(tree->root)); // The height of the root is 0

    insert(tree, 15);
    printf("\n\nThe size of the tree is %d\n", size(tree)); // The size of the tree is 1
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 15 
    printf("The parent of the root is %p\n", parent(tree->root)); // The parent of the root is 0x0 (NULL)
    printf("The number of children of the root is %d\n", num_children(tree->root)); // The number of children of the root is 0
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 0 (False)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 1 (True)
    printf("Is the root the root? %d\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    pre_order(tree->root);
    printf("\n");
    post_order(tree->root);
    printf("The depth of the root is %d because the root is NULL\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d because the root is NULL\n", height(tree->root)); // The height of the root is 0
    print_tree(tree->root);

    insert(tree, 9);
    printf("\n\nThe size of the tree is %d\n", size(tree)); // The size of the tree is 2
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 15 
    printf("The parent of the new node is %d\n", parent(search(tree, 9))->element); // The parent of the new node is 15
    printf("The number of children of the root is %d\n", num_children(tree->root)); // The number of children of the root is 1
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 1 (True)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 0 (False)
    printf("Is the new node internal? %d\n", is_internal(search(tree, 9))); // Is the new node internal? 0 (False)
    printf("Is the new node external? %d\n", is_external(search(tree, 9))); // Is the new node external? 1 (True)
    printf("Is the new node the root? %d\n", is_root(tree, search(tree, 9))); // Is the new node the root? 0 (False)
    pre_order(tree->root);
    printf("\n");
    post_order(tree->root);
    printf("The depth of the root is %d because the root is NULL\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d because the root is NULL\n", height(tree->root)); // The height of the root is 0
    print_tree(tree->root);

    destroy_tree(tree);
}

int main() {

    test_insert_search_delete();

    // test_all_functions_regular_cases();

    return 0;
}