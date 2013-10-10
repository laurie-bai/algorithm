#include "tree.h"

int main()
{
	BiTree tree;
	createBiTree(tree);
	inOrderNonRecursive(tree);
	preOrderNonRecursive(tree);
	postOrderNonRecursive(tree);

	return 0;
}
