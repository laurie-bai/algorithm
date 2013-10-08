#ifndef _TREE_H
#define _TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char   data;
	struct node *lchild;
	struct node *rchild;
	struct node *parent;
} Node;

typedef struct {
	Node *root;
} Tree;

Node *get_binary_tree(char *, char *, int);
void post_order_traverse(Node *);

#endif
