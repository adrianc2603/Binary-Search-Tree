#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "main.h"

/**
 * Helper function to print each node in the tree
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

/**
 * Helper function to insert all items in the tree
 */
void build_tree(tree_t *tree) {
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
}

/**
 * Helper function to insert the given element to the tree
 */
void insert_element(tree_t *tree, int e) {
    printf("\nInsert %d ---\n", e);
    insert(tree, e);
}

/**
 * Helper function to remove the given element from the tree
 */
void remove_element(tree_t *tree, int e) {
    printf("\nRemove %d ---\n", e);
    node_t *node = search(tree, e);   
    remove_node(tree, tree->root, node);   
}

/**
 * Helper function to perform a preorder traversal, printing a new line before
 * and after the traversal is done
 */
void perform_preorder(node_t *root) {
    printf("Pre order: ");
    pre_order(root); 
    printf("\n");
}

/**
 * Helper function to perform a postorder traversal, printing a new line before
 * and after the traversal is done
 */
void perform_postorder(node_t *root) {
    printf("Post order: "); 
    post_order(root); 
    printf("\n");
}

/**
 * Helper function to perform an inorder traversal, printing a new line before
 * and after the traversal is done
 */
void perform_inorder(node_t *root) {
    printf("In order: ");
    in_order(root); 
    printf("\n");
}

/**
 * Helper function to print all nodes in a tree, with a new line printed at 
 * the start and finish of printing
 */
void perform_tree_print(node_t *root) {
    printf("\n");
    print_tree(root);
    printf("\n");
}

void test_insert_search_delete() {
    tree_t *tree = create_tree();

    // Insert all elements into tree
    printf("\nInsert all elements ---\n");                                                 
    build_tree(tree);
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

    // Remove 11
    remove_element(tree, 11);
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

    // Remove 24
    remove_element(tree, 24);
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

    // Remove 30
    remove_element(tree, 30);   
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

    // Remove 26
    remove_element(tree, 26);   
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

    // Remove 12
    remove_element(tree, 12);                                     
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

    // Remove 9
    remove_element(tree, 9);                               
    /*
                 _______20_______
                |                |
           _____3____        ____29____
          |          |      |          |
          2          5      22         31
    */                            
    print_tree(tree->root);

    // Remove 20
    remove_element(tree, 20);                                              
    /*
                 _______22_______
                |                |
           _____3____            29____
          |          |                 |
          2          5                 31
    */                            
    print_tree(tree->root);

    // Remove 5
    remove_element(tree, 5);                                            
    /*
                 _______22_______
                |                |
           _____3                29____
          |                            |
          2                            31
    */                            
    print_tree(tree->root);

    // Remove 22
    remove_element(tree, 22);                                      
    /*
                 _______29_______
                |                |
           _____3                31
          |                           
          2                           
    */                            
    print_tree(tree->root);

    // Remove 29
    remove_element(tree, 29);                                          
    /*
                 _______31
                |                
           _____3                
          |                           
          2                           
    */                            
    print_tree(tree->root);

    // Remove 31
    remove_element(tree, 31);                                        
    /*
                 ______3                
                |                           
                2                           
    */                            
    print_tree(tree->root);

    // Remove 3
    remove_element(tree, 3);                       
    /*
                       2               
    */                            
    print_tree(tree->root);

    // Remove 2
    remove_element(tree, 2);                                            
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

    // Remove 20
    remove_element(tree, 20);                                     
    /*
                        25_______
                                 |
                                 30
    */   
    print_tree(tree->root);

    // Remove 25
    remove_element(tree, 25);                                           
    /*
                        30
    */   
    print_tree(tree->root);

    // Remove 30
    remove_element(tree, 30);                                             
    /*
        Tree is empty
    */    
    print_tree(tree->root);

    destroy_tree(tree);
}

void test_all_functions_regular_cases() {
    tree_t *tree = create_tree();

    assert(size(tree) == 0);
    assert(is_empty(tree) == true);
    assert(root(tree) == NULL);
    assert(num_children(tree->root) == 0);
    assert(is_internal(tree->root) == false);
    assert(is_external(tree->root) == true);
    assert(is_root(tree, tree->root) == false);
    perform_preorder(tree->root); // Nothing prints
    perform_postorder(tree->root); // Nothing prints
    perform_inorder(tree->root); // Nothing prints
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 0);

    // Insert 12
    insert_element(tree, 12);
    assert(size(tree) == 1);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    assert(num_children(tree->root) == 0);
    assert(is_internal(tree->root) == false);
    assert(is_external(tree->root) == true);
    assert(is_root(tree, tree->root) == true);
    perform_preorder(tree->root); // 12
    perform_postorder(tree->root); // 12
    perform_inorder(tree->root); // 12
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 0);
    perform_tree_print(tree->root);

    // Insert 9
    insert_element(tree, 9);
    node_t *node = search(tree, 9);
    assert(size(tree) == 2);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    assert(node->parent->element == 12);
    assert(num_children(tree->root) == 1);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_internal(node) == false);
    assert(is_external(node) == true);
    assert(is_root(tree, node) == false);
    perform_preorder(tree->root); // 12 - 9
    perform_postorder(tree->root); // 9 - 12
    perform_inorder(tree->root); // 9 - 12
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 1);
    assert(depth(node) == 1);
    assert(height(node) == 0);
    perform_tree_print(tree->root);
    
    // Insert 26
    insert_element(tree, 26);
    node = search(tree, 9);
    assert(size(tree) == 3);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    assert(node->parent->element == 12);
    assert(num_children(tree->root) == 2);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_internal(node) == false);
    assert(is_external(node) == true);
    assert(is_root(tree, node) == false);
    perform_preorder(tree->root); // 12 - 9 - 26
    perform_postorder(tree->root); // 9 - 26 - 12
    perform_inorder(tree->root); // 9 - 12 - 26
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 1);
    assert(depth(node) == 1);
    assert(height(node) == 0);
    perform_tree_print(tree->root);
    
    // Insert 3
    insert_element(tree, 3);
    node = search(tree, 3);
    assert(size(tree) == 4);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    assert(node->parent->element == 9);
    assert(num_children(node->parent) == 1);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_internal(node) == false);
    assert(is_external(node) == true);
    assert(is_root(tree, node) == false);
    perform_preorder(tree->root); // 12 - 9 - 3 - 26 
    perform_postorder(tree->root); // 3 - 9 - 26 - 12
    perform_inorder(tree->root); // 3 - 9 - 12 - 26
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 2);
    assert(depth(node) == 2);
    assert(height(node) == 0);
    perform_tree_print(tree->root);
    
    // Insert 5
    insert_element(tree, 5);
    node = search(tree, 5);
    assert(size(tree) == 5);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    assert(node->parent->element == 3);
    assert(num_children(node->parent) == 1);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_internal(node) == false);
    assert(is_external(node) == true);
    assert(is_root(tree, node) == false);
    perform_preorder(tree->root); // 12 - 9 - 3 - 5 - 26 
    perform_postorder(tree->root); // 5 - 3 - 9 - 26 - 12
    perform_inorder(tree->root); // 3 - 5 - 9 - 12 - 26
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 3);
    assert(depth(node) == 3);
    assert(height(node) == 0);
    perform_tree_print(tree->root);

    // Insert 2
    insert_element(tree, 2);
    node = search(tree, 2);
    assert(size(tree) == 6);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    assert(node->parent->element == 3);
    assert(num_children(node->parent) == 2);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_internal(node) == false);
    assert(is_external(node) == true);
    assert(is_root(tree, node) == false);
    perform_preorder(tree->root); // 12 - 9 - 3 - 2 - 5 - 26 
    perform_postorder(tree->root); // 2 - 5 - 3 - 9 - 26 - 12
    perform_inorder(tree->root); // 2 - 3 - 5 - 9 - 12 - 26
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 3);
    assert(depth(node) == 3);
    assert(height(node) == 0);
    perform_tree_print(tree->root);
    
    // Finish building the rest of the tree
    printf("\nBuilding the rest of the tree\n");
    build_tree(tree);
    assert(size(tree) == 13);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    perform_preorder(tree->root); // 12 - 9 - 3 - 2 - 5 - 11 - 26 - 24 - 22 - 20 - 30 - 29 - 31 
    perform_postorder(tree->root); // 2 - 5 - 3 - 11 - 9 - 20 - 22 - 24 - 29 - 31 - 30 - 26 - 12
    perform_inorder(tree->root); // 2 - 3 - 5 - 9 - 11 - 12 - 20 - 22 - 24 - 26 - 29 - 30 - 31
    
    node = search(tree, 20);
    assert(depth(node) == 4);
    assert(height(node) == 0);
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 4);
    perform_tree_print(tree->root);

    // Remove 20
    node_t *parent_node = node->parent;
    assert(num_children(parent_node) == 1);
    assert(is_internal(parent_node) == true);
    assert(is_external(parent_node) == false);
    assert(height(parent_node) == 1);
    remove_element(tree, 20);
    assert(num_children(parent_node) == 0);
    assert(is_internal(parent_node) == false);
    assert(is_external(parent_node) == true);
    assert(height(parent_node) == 0);
    assert(size(tree) == 12);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    perform_preorder(tree->root); // 12 - 9 - 3 - 2 - 5 - 11 - 26 - 24 - 22 - 30 - 29 - 31 
    perform_postorder(tree->root); // 2 - 5 - 3 - 11 - 9 - 22 - 24 - 29 - 31 - 30 - 26 - 12
    perform_inorder(tree->root); // 2 - 3 - 5 - 9 - 11 - 12 - 22 - 24 - 26 - 29 - 30 - 31
    perform_tree_print(tree->root);

    // Remove 2
    node = search(tree, 2);
    parent_node = node->parent;
    assert(num_children(parent_node) == 2);
    assert(is_internal(parent_node) == true);
    assert(is_external(parent_node) == false);
    assert(height(parent_node) == 1);
    remove_element(tree, 2);
    assert(num_children(parent_node) == 1);
    assert(is_internal(parent_node) == true);
    assert(is_external(parent_node) == false);
    assert(height(parent_node) == 1);
    assert(size(tree) == 11);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    perform_preorder(tree->root); // 12 - 9 - 3 - 5 - 11 - 26 - 24 - 22 - 30 - 29 - 31 
    perform_postorder(tree->root); // 5 - 3 - 11 - 9 - 22 - 24 - 29 - 31 - 30 - 26 - 12
    perform_inorder(tree->root); // 3 - 5 - 9 - 11 - 12 - 22 - 24 - 26 - 29 - 30 - 31
    perform_tree_print(tree->root);
    
    // Remove 5
    node = search(tree, 5);
    parent_node = node->parent;
    assert(num_children(parent_node) == 1);
    assert(is_internal(parent_node) == true);
    assert(is_external(parent_node) == false);
    assert(height(parent_node) == 1);
    remove_element(tree, 5);
    assert(num_children(parent_node) == 0);
    assert(is_internal(parent_node) == false);
    assert(is_external(parent_node) == true);
    assert(height(parent_node) == 0);
    assert(size(tree) == 10);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    perform_preorder(tree->root); // 12 - 9 - 3 - 2 - 11 - 26 - 24 - 22 - 30 - 29 - 31 
    perform_postorder(tree->root); // 2 - 3 - 11 - 9 - 22 - 24 - 29 - 31 - 30 - 26 - 12
    perform_inorder(tree->root); // 2 - 3 - 9 - 11 - 12 - 22 - 24 - 26 - 29 - 30 - 31
    perform_tree_print(tree->root);
    
    // Remove 26
    node = search(tree, 26);
    parent_node = node->parent;
    assert(num_children(parent_node) == 2);
    assert(is_internal(parent_node) == true);
    assert(is_external(parent_node) == false);
    remove_element(tree, 26);
    assert(num_children(parent_node) == 2);
    assert(is_internal(parent_node) == true);
    assert(is_external(parent_node) == false);
    assert(size(tree) == 9);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 12);
    perform_preorder(tree->root); // 12 - 9 - 3 - 11 - 29 - 24 - 22 - 30 - 31 
    perform_postorder(tree->root); // 3 - 11 - 9 - 22 - 24 - 31 - 30 - 29 - 12
    perform_inorder(tree->root); // 3 - 9 - 11 - 12 - 22 - 24 - 29 - 30 - 31
    perform_tree_print(tree->root);
    
    // Remove 12
    remove_element(tree, 12);
    assert(size(tree) == 8);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 22);
    assert(num_children(tree->root) == 2);
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 3);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_root(tree, tree->root) == true);
    perform_preorder(tree->root); // 22 - 9 - 3 - 11 - 29 - 24 - 30 - 31 
    perform_postorder(tree->root); // 3 - 11 - 9 - 24  - 31 - 30 - 29 - 22
    perform_inorder(tree->root); // 3 - 9 - 11 - 22 - 24 - 29 - 30 - 31
    perform_tree_print(tree->root);
    
    // Remove 22
    remove_element(tree, 22);
    assert(size(tree) == 7);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 24);
    assert(num_children(tree->root) == 2);
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 3);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_root(tree, tree->root) == true);
    perform_preorder(tree->root); // 24 - 9 - 3 - 11 - 29  - 30 - 31 
    perform_postorder(tree->root); // 3 - 11 - 9 -- 31 - 30 - 29 - 24
    perform_inorder(tree->root); // 3 - 9 - 11 - 24 - 29 - 30 - 31
    perform_tree_print(tree->root);
    
    // Remove 24
    remove_element(tree, 24);
    assert(size(tree) == 6);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 29);
    assert(num_children(tree->root) == 2);
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 2);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_root(tree, tree->root) == true);
    perform_preorder(tree->root); // 29 - 9 - 3 - 11 - 30 - 31 
    perform_postorder(tree->root); // 3 - 11 - 9 - 31 - 30 - 29
    perform_inorder(tree->root); // 3 - 9 - 11 - 29 - 30 - 31
    perform_tree_print(tree->root);

    // Remove 29
    remove_element(tree, 29);
    assert(size(tree) == 5);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 30);
    assert(num_children(tree->root) == 2);
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 2);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_root(tree, tree->root) == true);
    perform_preorder(tree->root); // 30 - 9 - 3 - 11 - 31 
    perform_postorder(tree->root); // 3 - 11 - 9 - 31 - 30
    perform_inorder(tree->root); // 3 - 9 - 11 - 30 - 31
    perform_tree_print(tree->root);

    // Remove 30
    remove_element(tree, 30);
    assert(size(tree) == 4);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 31);
    assert(num_children(tree->root) == 1);
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 2);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_root(tree, tree->root) == true);
    perform_preorder(tree->root); // 31 - 9 - 3 - 11 
    perform_postorder(tree->root); // 3 - 11 - 9 - 31 
    perform_inorder(tree->root); // 3 - 9 - 11 - 31
    perform_tree_print(tree->root);
    
    // Remove 31
    remove_element(tree, 31);
    assert(size(tree) == 3);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 9);
    assert(num_children(tree->root) == 2);
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 1);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_root(tree, tree->root) == true);
    perform_preorder(tree->root); // 9 - 3 - 11 
    perform_postorder(tree->root); // 3 - 11 - 9
    perform_inorder(tree->root); // 3 - 9 - 11
    perform_tree_print(tree->root);

    // Remove 9
    remove_element(tree, 9);
    assert(size(tree) == 2);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 11);
    assert(num_children(tree->root) == 1);
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 1);
    assert(is_internal(tree->root) == true);
    assert(is_external(tree->root) == false);
    assert(is_root(tree, tree->root) == true);
    perform_preorder(tree->root); // 11 - 3 
    perform_postorder(tree->root); // 3 - 11
    perform_inorder(tree->root); // 3 - 11
    perform_tree_print(tree->root);
    
    // Remove 11
    remove_element(tree, 11);
    assert(size(tree) == 1);
    assert(is_empty(tree) == false);
    assert(root(tree)->element == 3);
    assert(num_children(tree->root) == 0);
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 0);
    assert(is_internal(tree->root) == false);
    assert(is_external(tree->root) == true);
    assert(is_root(tree, tree->root) == true);
    perform_preorder(tree->root); // 3 
    perform_postorder(tree->root); // 3 
    perform_inorder(tree->root); // 3 
    perform_tree_print(tree->root);

    // Remove 3
    remove_element(tree, 3);
    assert(size(tree) == 0);
    assert(is_empty(tree) == true);
    assert(root(tree) == NULL);
    assert(num_children(tree->root) == 0);
    assert(depth(tree->root) == 0);
    assert(height(tree->root) == 0);
    assert(is_internal(tree->root) == false);
    assert(is_external(tree->root) == true);
    assert(is_root(tree, tree->root) == false); // Root doesn't exist
    perform_preorder(tree->root); // Nothing prints
    perform_postorder(tree->root); // Nothing prints
    perform_inorder(tree->root); // Nothing prints
    perform_tree_print(tree->root);

    // Added items to tree to ensure destroy_tree freed all memory (no memory leaks)
    build_tree(tree);
    destroy_tree(tree);
}

int main() {

    test_insert_search_delete();

    test_all_functions_regular_cases();

    return 0;
}