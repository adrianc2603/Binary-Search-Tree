#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
    int element;
    struct node_t *parent;
    struct node_t *left_child;
    struct node_t *right_child;
} node_t;

typedef struct tree_t {
    node_t *root;
    int size;
} tree_t;

tree_t *create_tree();

void insert(tree_t *tree, int e);

node_t *search(tree_t *tree, int e);

node_t *remove_node(tree_t *tree, node_t *root, node_t *p);

node_t *find_minimum(node_t *p);

int size(tree_t *tree);

bool is_empty(tree_t *tree);

node_t *root(tree_t *tree);

node_t *parent(node_t *p);

int num_children(node_t *p);

bool is_internal(node_t *p);

bool is_external(node_t *p);

bool is_root(tree_t *tree, node_t *p);

node_t *left_child(node_t *p);

node_t *right_child(node_t *p);

void pre_order(node_t *p);

void post_order(node_t *p);

void in_order(node_t *p); 

void visit_node(node_t *p);

int depth(node_t *p);

int height(node_t *p);

int max(int a, int b);

void destroy_tree(tree_t *tree);

void destroy_node(node_t *p);