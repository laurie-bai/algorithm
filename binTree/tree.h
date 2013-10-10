#include <iostream>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct BiTNode 
{
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void createBiTree(BiTree &root)
{
	char ch;

	cin >> ch;
	if (ch == '#')
		root = NULL;
	else
	{
		root = (BiTNode *)malloc(sizeof(BiTNode));
		if (root == NULL)
		{
			cout << "error: malloc" << endl;
			exit(-1);
		}
		root->data = ch;
		createBiTree(root->lchild);
		createBiTree(root->rchild);
	}
}

void inOrderRecursive(BiTree root)
{
	if (root == NULL)
		return;
	inOrderRecursive(root->lchild);
	cout << root->data << endl;
	inOrderRecursive(root->rchild);
}

void inOrderNonRecursive(BiTree root)
{
	stack<BiTree> s;
	
	while (root || !s.empty())
	{
		if (root)
		{
			s.push(root);
			root = root->lchild;
		}
		else
		{
			root = s.top();
			s.pop();
			cout << root->data << endl;
			root = root->rchild;
		}
	}
}

void preOrderNonRecursive(BiTree root)
{
	stack<BiTree> s;

	s.push(root);
	while (!s.empty())
	{
		BiTree temp = s.top();
		cout << temp->data << endl;
		s.pop();
		if (temp->rchild)
			s.push(temp->rchild);
		if (temp->lchild)
			s.push(temp->lchild);
	}
}

void postOrderNonRecursive(BiTree root)
{
	stack<BiTree> s1, s2;

	s1.push(root);
	while (!s1.empty())
	{
		BiTree curr = s1.top();
		s1.pop();
		s2.push(curr);
		if (curr->lchild)
			s1.push(curr->lchild);
		if (curr->rchild)
			s1.push(curr->rchild);
	}
	while (!s2.empty())
	{
		cout << s2.top()->data << endl;
		s2.pop();
	}
}
