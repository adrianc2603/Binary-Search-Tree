#include "main.h"

/**
 * Create a tree and initialise all its fields. Return a pointer to it
 * Time Complexity: O(1)
 */
tree_t *create_tree() {
    tree_t *tree = malloc(sizeof(tree_t));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

/**
 * Insert element e into the tree
 * Time Complexity: O(h) (h = height of tree. Best case: h = log(n). 
 * Worst case: h = n)
 */
void insert(tree_t *tree, int e) {
    if (tree == NULL) {
        return;
    }

    // Element e already exists in the tree
    if (search(tree, e) != NULL) {
        return;
    }   

    // Create new node
    node_t *new_node = malloc(sizeof(node_t));
    new_node->element = e;
    new_node->parent = NULL;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    // Set new node as root if tree is empty
    if (tree->root == NULL) {
        tree->root = new_node;
        tree->size++;
        return;
    }

    // Find the position of the new node in the tree
    node_t *current_node = tree->root;
    node_t *parent = NULL;

    while (1) {
        parent = current_node;

        // Left subtree
        if (e < parent->element) {
            current_node = current_node->left_child;

            // Add the new node as the left child
            if (current_node == NULL) {
                current_node = new_node;
                new_node->parent = parent;
                parent->left_child = new_node;
                tree->size++;
                return;
            }
        }

        // Right subtree
        else {
            current_node = current_node->right_child;

            // Add the new node as the right child
            if (current_node == NULL) {
                current_node = new_node;
                new_node->parent = parent;
                parent->right_child = new_node;
                tree->size++;
                return;
            }
        }
    }
}

/**
 * Search and return the node containing element e. 
 * Return NULL if the node is not found
 * Time Complexity: O(h) (h = height of tree. Best case: h = log(n). 
 * Worst case: h = n)
 */
node_t *search(tree_t *tree, int e) {
    if (tree == NULL) {
        return NULL;
    }

    // Traverse down the tree, starting at the root
    node_t *current_node = tree->root;
    while (current_node != NULL && current_node->element != e) {

        // Left subtree
        if (e < current_node->element) {
            current_node = current_node->left_child;
        }

        // Right subtree
        else {
            current_node = current_node->right_child;
        }
    }

    // Element not found in tree
    if (current_node == NULL) {
        return NULL;
    }

    return current_node;
}

/**
 * Remove the given node (p) from the tree. Return the root node from each 
 * recursive call. Return NULL if the root or p is NULL
 * Time Complexity: O(h) (h = height of tree. Best case: h = log(n). 
 * Worst case: h = n)
 */
node_t *remove_node(tree_t *tree, node_t *root, node_t *p) {
    if (root == NULL || p == NULL) {
        return NULL;
    }

    // Left subtree
    if (p->element < root->element) {
        root->left_child = remove_node(tree, root->left_child, p);
    }

    // Right subtree
    else if (p->element > root->element) {
        root->right_child = remove_node(tree, root->right_child, p);
    }

    else { // root == p

        // No children
        if (root->left_child == NULL && root->right_child == NULL) {
            free(root);
            root = NULL;
            tree->size--;
            if (tree->size == 0) { // Tree is now empty
                tree->root = NULL;
            }
        }

        // 1 Child (Right)
        else if (root->left_child == NULL) {
            node_t *current_node = root;
            root = root->right_child;
            if (current_node->parent == NULL) { // new root is root of tree
                tree->root = root;
                root->parent = NULL;
            }
            free(current_node);
            tree->size--;
        }

        // 1 Child (Left)
        else if (root->right_child == NULL) {
            node_t *current_node = root;
            root = root->left_child;
            if (current_node->parent == NULL) { // new root is root of tree
                tree->root = root;
                root->parent = NULL;
            }
            free(current_node);
            tree->size--;
        }

        // 2 Children (Right and Left)
        else {
            node_t *min_node = find_minimum(root->right_child); // Min node in 
            root->element = min_node->element;                 // right subtree
            root->right_child = remove_node(tree, root->right_child, min_node);
        }
    }
    return root;
    
}

/** 
 * Find the minimum node in the subtree of p
 * Helper for remove_node
 * Time Complexity: O(h) (h = height of tree). 
 */
node_t *find_minimum(node_t *p) {
    node_t *current_node = p;
    while (current_node != NULL && current_node->left_child != NULL) {
        current_node = current_node->left_child;
    }
    return current_node;
}

/**
 * Return the number of elements in the tree
 * Time Complexity: O(1)
 */
int size(tree_t *tree) {
    if (tree == NULL) {
        return 0;
    }
    return tree->size;
}

/**
 * Return whether the tree stores any elements or not
 * Time Complexity: O(1)
 */
bool is_empty(tree_t *tree) {
    if (tree == NULL) {
        return true;
    }
    return (tree->size == 0);
}

/**
 * Return the root of the tree
 * Time Complexity: O(1)
 */
node_t *root(tree_t *tree) {
    if (tree == NULL) {
        return NULL;
    }
    return tree->root;
}

/**
 * Return the number of children of the given node
 * Time Complexity: O(1)
 */
int num_children(node_t *p) {
    if (p == NULL) {
        return 0;
    }
    if (p->left_child == NULL && p->right_child == NULL) {
        return 0;
    }
      if (p->left_child != NULL && p->right_child != NULL) {
        return 2;
    }
    return 1;
}

/**
 * Return whether the given node is internal or not
 * Time Complexity: O(1)
 */
bool is_internal(node_t *p) {
    if (p == NULL) {
        return false;
    }
    return (p->left_child != NULL || p->right_child != NULL);
}

/**
 * Return whether the given node is external or not
 * Time Complexity: O(1)
 */
bool is_external(node_t *p) {
    if (p == NULL) {
        return true;
    }
    return (p->left_child == NULL && p->right_child == NULL);
}

/**
 * Return whether the given node is the root of the tree or not
 * Time Complexity: O(1)
 */
bool is_root(tree_t *tree, node_t *p) {
    if (tree == NULL || p == NULL) {
        return false;
    }
    return (tree->root == p);
}

/**
 * Perform a pre_order traversal of the tree, visiting the node 
 * and then its children
 * Time Complexity: O(n) 
 */
void pre_order(node_t *p) {
    if (p == NULL) {
        return;
    }
    visit_node(p);
    pre_order(p->left_child);
    pre_order(p->right_child);
}

/**
 * Perform a post_order traversal of the tree, visiting the node's 
 * children and then the node
 * Time Complexity: O(n) 
 */
void post_order(node_t *p) {
    if (p == NULL) {
        return;
    }
    post_order(p->left_child);
    post_order(p->right_child);
    visit_node(p);
}

/**
 * Perform an in_order traversal of the tree, visiting the node's left child, 
 * itself, and then the node's right child
 * Time Complexity: O(n) 
 */
void in_order(node_t *p) {
    if (p == NULL) {
        return;
    }
    in_order(p->left_child);
    visit_node(p);
    in_order(p->right_child);
}

/** 
 * Print to standard output the element stored at the given node
 * Helper for preorder, postorder and inorder
 * Time Complexity: O(1)
 */
void visit_node(node_t *p) {
    if (p == NULL) {
        return;
    }
    printf("%d -- ", p->element);
}

/**
 * Return the depth of the given node in the tree
 * Time Complexity: O(h) (h = height of tree).
 */
int depth(node_t *p) {
    if (p == NULL) {
        return 0;
    }
    if (p->parent == NULL) {
        return 0;
    }
    return depth(p->parent) + 1;
}

/**
 * Return the height of the given node in the tree
 * Time Complexity: O(h) (h = height of tree).
 */
int height(node_t *p) {
    if (p == NULL) {
        return 0;
    }
    if (is_external(p)) {
        return 0;
    }
    int h = 0;
    h = max(h, height(p->left_child));
    h = max(h, height(p->right_child));
    return h + 1;
}

/**
 * Return the maximum number between a and b
 * Helper for height
 * Time Complexity: O(1)
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Free all memory associated with the tree
 * Time Complexity: O(n) (including destroy_node() helper function)
 */
void destroy_tree(tree_t *tree) {
    if (!is_empty(tree)) {
        destroy_node(tree->root);
    }
    free(tree);
}

/**
 * Free each node in the subtree of node p
 * Helper for destroy_tree
 * Time Complexity: O(n) 
 */
void destroy_node(node_t *p) {
    if (p->left_child != NULL) {
        destroy_node(p->left_child);
    }
    if (p->right_child != NULL) {
        destroy_node(p->right_child);
    }
    free(p);
}