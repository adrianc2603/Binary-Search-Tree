#include <stdio.h>
#include <stdlib.h>
#include "main.h"

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

void test_insert_search_delete() {
    tree_t *tree = create_tree();

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
    printf("The number of children of the root is %d because the root is NULL\n", num_children(tree->root)); // The number of children of the root is 0
    printf("Is the root internal? %d because the root is NULL\n", is_internal(tree->root)); // Is the root internal? 0 (False)
    printf("Is the root external? %d because the root is NULL\n", is_external(tree->root)); // Is the root external? 1 (True)
    printf("Is the root the root? %d because the root is NULL\n", is_root(tree, tree->root)); // Is the root the root? 0 (False)
    
    printf("Pre order: ");
    pre_order(tree->root); // Nothing prints
    printf("\n");
    
    printf("Post order: "); 
    post_order(tree->root); // Nothing prints
    printf("\n");
    
    printf("In order: ");
    in_order(tree->root); // Nothing prints
    printf("\n");
    
    printf("The depth of the root is %d because the root is NULL\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d because the root is NULL\n", height(tree->root)); // The height of the root is 0

    // Insert 12
    printf("\nInsert 12 ---\n");
    insert(tree, 12);
    printf("\nThe size of the tree is %d\n", size(tree)); // The size of the tree is 1
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12
    printf("The number of children of the root is %d\n", num_children(tree->root)); // The number of children of the root is 0
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 0 (False)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 1 (True)
    printf("Is the root the root? %d\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    
    printf("Pre order: ");
    pre_order(tree->root); // 12
    printf("\n");
    
    printf("Post order: ");
    post_order(tree->root); // 12
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 12
    printf("\n");
    
    printf("The depth of the new node is %d\n", depth(tree->root)); // The depth of the new node is 1
    printf("The height of the root is %d because the root is NULL\n", height(tree->root)); // The height of the new node is 1
    
    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Insert 9
    printf("\nInsert 9 ---\n");
    insert(tree, 9);
    node_t *node = search(tree, 9);
    printf("\nThe size of the tree is %d\n", size(tree)); // The size of the tree is 2
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12 
    printf("The parent of the new node is %d\n", node->parent->element); // The parent of the new node is 12
    printf("The number of children of the root is %d\n", num_children(tree->root)); // The number of children of the root is 1
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 1 (True)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 0 (False)
    printf("Is the new node internal? %d\n", is_internal(node)); // Is the new node internal? 0 (False)
    printf("Is the new node external? %d\n", is_external(node)); // Is the new node external? 1 (True)
    printf("Is the new node the root? %d\n", is_root(tree, node)); // Is the new node the root? 0 (False)
    
    printf("Pre order: ");
    pre_order(tree->root); // 12 - 9
    printf("\n");
    
    printf("Post order: ");
    post_order(tree->root); // 9 - 12
    printf("\n");
    
    printf("In order: ");
    in_order(tree->root); // 9 - 12
    printf("\n");

    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 1
    printf("The depth of the new node is %d\n", depth(node)); // The depth of the new node is 1
    printf("The height of the new node is %d\n", height(node)); // The height of the new node is 0
    
    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Insert 26
    printf("\nInsert 26 ---\n");
    insert(tree, 26);
    node = search(tree, 9);
    printf("\nThe size of the tree is %d\n", size(tree)); // The size of the tree is 3
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12 
    printf("The parent of the new node is %d\n", node->parent->element); // The parent of the new node is 12
    printf("The number of children of the root is %d\n", num_children(tree->root)); // The number of children of the root is 2
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 1 (True)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 0 (False)
    printf("Is the new node internal? %d\n", is_internal(node)); // Is the new node internal? 0 (False)
    printf("Is the new node external? %d\n", is_external(node)); // Is the new node external? 1 (True)
    printf("Is the new node the root? %d\n", is_root(tree, node)); // Is the new node the root? 0 (False)

    printf("Pre order: ");
    pre_order(tree->root); // 12 - 9 - 26
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 9 - 26 - 12
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 9 - 12 - 26
    printf("\n");
    
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 1
    printf("The depth of the new node is %d\n", depth(node)); // The depth of the new node is 1
    printf("The height of the new node is %d\n", height(node)); // The height of the new node is 0
    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Insert 3
    printf("\nInsert 3 ---\n");
    insert(tree, 3);
    node = search(tree, 3);
    printf("\nThe size of the tree is %d\n", size(tree)); // The size of the tree is 4
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12 
    printf("The parent of the new node is %d\n", node->parent->element); // The parent of the new node is 9
    printf("The number of children of the parent is %d\n", num_children(node->parent)); // The number of children of the parent is 1
    printf("Is the parent internal? %d\n", is_internal(node->parent)); // Is the parent internal? 1 (True)
    printf("Is the parent external? %d\n", is_external(node->parent)); // Is the parent external? 0 (False)
    printf("Is the new node internal? %d\n", is_internal(node)); // Is the new node internal? 0 (False)
    printf("Is the new node external? %d\n", is_external(node)); // Is the new node external? 1 (True)
    printf("Is the new node the root? %d\n", is_root(tree, node)); // Is the new node the root? 0 (False)

    printf("Pre order: ");
    pre_order(tree->root); // 12 - 9 - 3 - 26 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 3 - 9 - 26 - 12
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 9 - 12 - 26
    printf("\n");
    
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 2
    printf("The depth of the new node is %d\n", depth(node)); // The depth of the new node is 2
    printf("The height of the new node is %d\n", height(node)); // The height of the new node is 0
    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Insert 5
    printf("\nInsert 5 ---\n");
    insert(tree, 5);
    node = search(tree, 5);
    printf("\nThe size of the tree is %d\n", size(tree)); // The size of the tree is 5
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12 
    printf("The parent of the new node is %d\n", node->parent->element); // The parent of the new node is 3
    printf("The number of children of the parent is %d\n", num_children(node->parent)); // The number of children of the parent is 1
    printf("Is the parent internal? %d\n", is_internal(node->parent)); // Is the parent internal? 1 (True)
    printf("Is the parent external? %d\n", is_external(node->parent)); // Is the parent external? 0 (False)
    printf("Is the new node internal? %d\n", is_internal(node)); // Is the new node internal? 0 (False)
    printf("Is the new node external? %d\n", is_external(node)); // Is the new node external? 1 (True)
    printf("Is the new node the root? %d\n", is_root(tree, node)); // Is the new node the root? 0 (False)

    printf("Pre order: ");
    pre_order(tree->root); // 12 - 9 - 3 - 5 - 26 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 5 - 3 - 9 - 26 - 12
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 5 - 9 - 12 - 26
    printf("\n");
    
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 3
    printf("The depth of the new node is %d\n", depth(node)); // The depth of the new node is 3
    printf("The height of the new node is %d\n", height(node)); // The height of the new node is 0
    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Insert 2
    printf("\nInsert 2 ---\n");
    insert(tree, 2);
    node = search(tree, 2);
    printf("\nThe size of the tree is %d\n", size(tree)); // The size of the tree is 6
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12 
    printf("The parent of the new node is %d\n", node->parent->element); // The parent of the new node is 3
    printf("The number of children of the parent is %d\n", num_children(node->parent)); // The number of children of the parent is 2
    printf("Is the parent internal? %d\n", is_internal(node->parent)); // Is the parent internal? 1 (True)
    printf("Is the parent external? %d\n", is_external(node->parent)); // Is the parent external? 0 (False)
    printf("Is the new node internal? %d\n", is_internal(node)); // Is the new node internal? 0 (False)
    printf("Is the new node external? %d\n", is_external(node)); // Is the new node external? 1 (True)
    printf("Is the new node the root? %d\n", is_root(tree, node)); // Is the new node the root? 0 (False)

    printf("Pre order: ");
    pre_order(tree->root); // 12 - 9 - 3 - 2 - 5 - 26 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 2 - 5 - 3 - 9 - 26 - 12
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 2 - 3 - 5 - 9 - 12 - 26
    printf("\n");
    
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 3
    printf("The depth of the new node is %d\n", depth(node)); // The depth of the new node is 3
    printf("The height of the new node is %d\n", height(node)); // The height of the new node is 0
    printf("\n");
    print_tree(tree->root);
    printf("\n");
    
    // Finish building the rest of the tree
    printf("\nBuilding the rest of the tree\n");
    build_tree(tree);

    printf("\nThe size of the tree is %d\n", size(tree)); // The size of the tree is 13
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12 

    printf("Pre order: ");
    pre_order(tree->root); // 12 - 9 - 3 - 2 - 5 - 11 - 26 - 24 - 22 - 20 - 30 - 29 - 31 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 2 - 5 - 3 - 11 - 9 - 20 - 22 - 24 - 29 - 31 - 30 - 26 - 12
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 2 - 3 - 5 - 9 - 11 - 12 - 20 - 22 - 24 - 26 - 29 - 30 - 31
    printf("\n");

    node = search(tree, 20);
    printf("The depth of 20 is %d\n", depth(node)); // The depth of 20 is 4
    printf("The height of 20 is %d\n", height(node)); // The height of 20 is 0
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 4

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 20
    node_t *parent_node = node->parent;
    printf("%d has %d children\n", parent_node->element, num_children(parent_node)); // 22 has 1 children
    printf("Is the parent internal? %d\n", is_internal(parent_node)); // Is the parent internal? 1 (True)
    printf("Is the parent external? %d\n", is_external(parent_node)); // Is the parent external? 0 (False)
    printf("The height of the parent is %d\n", height(parent_node)); // The height of the parent is 1
    printf("Removing 20 ---\n");
    remove_node(tree, tree->root, node);
    printf("%d has %d children\n", parent_node->element, num_children(parent_node)); // 22 has 0 children
    printf("Is the parent internal? %d\n", is_internal(parent_node)); // Is the parent internal? 0 (False)
    printf("Is the parent external? %d\n", is_external(parent_node)); // Is the parent external? 1 (True)
    printf("The height of the parent is %d\n", height(parent_node)); // The height of the parent is 0

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 12
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12 

    printf("Pre order: ");
    pre_order(tree->root); // 12 - 9 - 3 - 2 - 5 - 11 - 26 - 24 - 22 - 30 - 29 - 31 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 2 - 5 - 3 - 11 - 9 - 22 - 24 - 29 - 31 - 30 - 26 - 12
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 2 - 3 - 5 - 9 - 11 - 12 - 22 - 24 - 26 - 29 - 30 - 31
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 2
    node = search(tree, 2);
    parent_node = node->parent;
    printf("%d has %d children\n", parent_node->element, num_children(parent_node)); // 3 has 2 children
    printf("Is the parent internal? %d\n", is_internal(parent_node)); // Is the parent internal? 1 (True)
    printf("Is the parent external? %d\n", is_external(parent_node)); // Is the parent external? 0 (False)
    printf("The height of the parent is %d\n", height(parent_node)); // The height of the parent is 1
    printf("Removing 2 ---\n");
    remove_node(tree, tree->root, node);
    printf("%d has %d children\n", parent_node->element, num_children(parent_node)); // 3 has 1 children
    printf("Is the parent internal? %d\n", is_internal(parent_node)); // Is the parent internal? 1 (True)
    printf("Is the parent external? %d\n", is_external(parent_node)); // Is the parent external? 0 (False)
    printf("The height of the parent is %d\n", height(parent_node)); // The height of the parent is 1

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 11
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12 

    printf("Pre order: ");
    pre_order(tree->root); // 12 - 9 - 3 - 5 - 11 - 26 - 24 - 22 - 30 - 29 - 31 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 5 - 3 - 11 - 9 - 22 - 24 - 29 - 31 - 30 - 26 - 12
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 5 - 9 - 11 - 12 - 22 - 24 - 26 - 29 - 30 - 31
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 5
    node = search(tree, 5);
    parent_node = node->parent;
    printf("%d has %d children\n", parent_node->element, num_children(parent_node)); // 3 has 1 children
    printf("Is the parent internal? %d\n", is_internal(parent_node)); // Is the parent internal? 1 (True)
    printf("Is the parent external? %d\n", is_external(parent_node)); // Is the parent external? 0 (False)
    printf("The height of the parent is %d\n", height(parent_node)); // The height of the parent is 1
    printf("Removing 5 ---\n");
    remove_node(tree, tree->root, node);
    printf("%d has %d children\n", parent_node->element, num_children(parent_node)); // 3 has 0 children
    printf("Is the parent internal? %d\n", is_internal(parent_node)); // Is the parent internal? 0 (False)
    printf("Is the parent external? %d\n", is_external(parent_node)); // Is the parent external? 1 (True)
    printf("The height of the parent is %d\n", height(parent_node)); // The height of the parent is 0

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 10
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12 

    printf("Pre order: ");
    pre_order(tree->root); // 12 - 9 - 3 - 2 - 11 - 26 - 24 - 22 - 30 - 29 - 31 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 2 - 3 - 11 - 9 - 22 - 24 - 29 - 31 - 30 - 26 - 12
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 2 - 3 - 9 - 11 - 12 - 22 - 24 - 26 - 29 - 30 - 31
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 26
    node = search(tree, 26);
    parent_node = node->parent;
    printf("%d has %d children\n", parent_node->element, num_children(parent_node)); // 12 has 2 children
    printf("Is the parent internal? %d\n", is_internal(parent_node)); // Is the parent internal? 1 (True)
    printf("Is the parent external? %d\n", is_external(parent_node)); // Is the parent external? 0 (False)
    printf("Removing 26 ---\n");
    remove_node(tree, tree->root, node);
    printf("%d has %d children\n", parent_node->element, num_children(parent_node)); // 12 has 2 children
    printf("Is the parent internal? %d\n", is_internal(parent_node)); // Is the parent internal? 1 (True)
    printf("Is the parent external? %d\n", is_external(parent_node)); // Is the parent external? 0 (False)

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 9
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 12 

    printf("Pre order: ");
    pre_order(tree->root); // 12 - 9 - 3 - 11 - 29 - 24 - 22 - 30 - 31 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 3 - 11 - 9 - 22 - 24 - 31 - 30 - 29 - 12
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 9 - 11 - 12 - 22 - 24 - 29 - 30 - 31
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 12
    printf("Removing 12 ---\n");
    node = search(tree, 12);
    remove_node(tree, tree->root, node);

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 8
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 22
    printf("The root has %d children\n", num_children(tree->root)); // The root has 2 children
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 3
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 1 (False)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 0 (True)
    printf("Is the root the root? %d\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    
    printf("Pre order: ");
    pre_order(tree->root); // 22 - 9 - 3 - 11 - 29 - 24 - 30 - 31 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 3 - 11 - 9 - 24  - 31 - 30 - 29 - 22
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 9 - 11 - 22 - 24 - 29 - 30 - 31
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 22
    printf("Removing 22 ---\n");
    node = search(tree, 22);
    remove_node(tree, tree->root, node);

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 7
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 24
    printf("The root has %d children\n", num_children(tree->root)); // The root has 2 children
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 3
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 1 (False)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 0 (True)
    printf("Is the root the root? %d\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    
    printf("Pre order: ");
    pre_order(tree->root); // 24 - 9 - 3 - 11 - 29  - 30 - 31 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 3 - 11 - 9 -- 31 - 30 - 29 - 24
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 9 - 11 - 24 - 29 - 30 - 31
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 24
    printf("Removing 24 ---\n");
    node = search(tree, 24);
    remove_node(tree, tree->root, node);

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 6
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 29
    printf("The root has %d children\n", num_children(tree->root)); // The root has 2 children
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 2
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 1 (False)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 0 (True)
    printf("Is the root the root? %d\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    
    printf("Pre order: ");
    pre_order(tree->root); // 29 - 9 - 3 - 11 - 30 - 31 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 3 - 11 - 9 - 31 - 30 - 29
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 9 - 11 - 29 - 30 - 31
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 29
    printf("Removing 29 ---\n");
    node = search(tree, 29);
    remove_node(tree, tree->root, node);

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 5
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 30
    printf("The root has %d children\n", num_children(tree->root)); // The root has 2 children
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 2
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 1 (False)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 0 (True)
    printf("Is the root the root? %d\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    
    printf("Pre order: ");
    pre_order(tree->root); // 30 - 9 - 3 - 11 - 31 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 3 - 11 - 9 - 31 - 30
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 9 - 11 - 30 - 31
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 30
    printf("Removing 30 ---\n");
    node = search(tree, 30);
    remove_node(tree, tree->root, node);

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 4
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 31
    printf("The root has %d children\n", num_children(tree->root)); // The root has 1 children
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 2
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 1 (False)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 0 (True)
    printf("Is the root the root? %d\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    
    printf("Pre order: ");
    pre_order(tree->root); // 31 - 9 - 3 - 11 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 3 - 11 - 9 - 31 
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 9 - 11 - 31
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 31
    printf("Removing 31 ---\n");
    node = search(tree, 31);
    remove_node(tree, tree->root, node);

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 3
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 9
    printf("The root has %d children\n", num_children(tree->root)); // The root has 2 children
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 1
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 1 (False)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 0 (True)
    printf("Is the root the root? %d\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    
    printf("Pre order: ");
    pre_order(tree->root); // 9 - 3 - 11 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 3 - 11 - 9
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 9 - 11
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 9
    printf("Removing 9 ---\n");
    node = search(tree, 9);
    remove_node(tree, tree->root, node);

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 2
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 11
    printf("The root has %d children\n", num_children(tree->root)); // The root has 1 children
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 1
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 1 (True)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 0 (False)
    printf("Is the root the root? %d\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    
    printf("Pre order: ");
    pre_order(tree->root); // 11 - 3 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 3 - 11
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3 - 11
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 11
    printf("Removing 11 ---\n");
    node = search(tree, 11);
    remove_node(tree, tree->root, node);

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 1
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 0 (False)
    printf("The root of the tree is %d\n", root(tree)->element); // The root of the tree is 9
    printf("The root has %d children\n", num_children(tree->root)); // The root has 0 children
    printf("The depth of the root is %d\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d\n", height(tree->root)); // The height of the root is 0
    printf("Is the root internal? %d\n", is_internal(tree->root)); // Is the root internal? 0 (False)
    printf("Is the root external? %d\n", is_external(tree->root)); // Is the root external? 1 (True)
    printf("Is the root the root? %d\n", is_root(tree, tree->root)); // Is the root the root? 1 (True)
    
    printf("Pre order: ");
    pre_order(tree->root); // 3 
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // 3
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // 3
    printf("\n");

    printf("\n");
    print_tree(tree->root);
    printf("\n");

    // Remove 3
    printf("Removing 3 ---\n");
    node = search(tree, 3);
    remove_node(tree, tree->root, node);

    printf("The size of the tree is %d\n", size(tree)); // The size of the tree is 0
    printf("Is the tree empty? %d\n", is_empty(tree)); // Is the tree empty? 1 (True)
    printf("The root of the tree is %p\n", root(tree)); // The root of the tree is 0x0 (NULL)
    printf("The number of children of the root is %d because the root is NULL\n", num_children(tree->root)); // The number of children of the root is 0
    printf("Is the root internal? %d because the root is NULL\n", is_internal(tree->root)); // Is the root internal? 0 (False)
    printf("Is the root external? %d because the root is NULL\n", is_external(tree->root)); // Is the root external? 1 (True)
    printf("Is the root the root? %d because the root is NULL\n", is_root(tree, tree->root)); // Is the root the root? 0 (False)
    printf("The depth of the root is %d because the root is NULL\n", depth(tree->root)); // The depth of the root is 0
    printf("The height of the root is %d because the root is NULL\n", height(tree->root)); // The height of the root is 0

    printf("Pre order: ");
    pre_order(tree->root); // Nothing prints
    printf("\n");

    printf("Post order: ");
    post_order(tree->root); // Nothing prints
    printf("\n");

    printf("In order: ");
    in_order(tree->root); // Nothing prints
    printf("\n");

    printf("\n");
    print_tree(tree->root); 
    printf("\n");

    // Added items to tree to ensure destroy_tree freed all memory (no memory leaks)
    build_tree(tree);
    destroy_tree(tree);
}

int main() {

    test_insert_search_delete();

    test_all_functions_regular_cases();

    return 0;
}