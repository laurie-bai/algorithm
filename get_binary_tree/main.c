#include "tree.h"

int main(int argc, char *argv[])
{
	char *preorder = "ABDHECFG";
	char *inorder  = "HDBEAFCG";
	
	Node *root = get_binary_tree(preorder, inorder, 8);
	post_order_traverse(root);

	return 0;
}

//@param n: node nums
Node *get_binary_tree(char *preorder, char *inorder, int n)
{
	if (preorder == NULL || preorder == '\0' || n <= 0)
		return NULL;

	Node *root = malloc(sizeof(Node));
	if (root == NULL)
	{
		printf("error: malloc\n");
		exit(-1);
	}
	root->data = *preorder;
	
	int pos = 0; //nums of left child
	while (*(inorder+pos) != root->data)
		pos++;

	//leftchild
	if (pos == 0)
		root->lchild = NULL;
	else
		root->lchild = get_binary_tree(preorder+1, inorder, pos);
	
	//rightchild
	if (n-pos-1 == 0)
		root->rchild = NULL;
	else
		root->rchild = get_binary_tree(preorder+pos+1, inorder+pos+1, n-pos-1);

	return root;
}

void post_order_traverse(Node *node)
{
	if (node == NULL)
		return;
	post_order_traverse(node->lchild);
	post_order_traverse(node->rchild);
	printf("%c\n", node->data);
}
