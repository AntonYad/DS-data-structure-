#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef struct TreeNode
{
	char val;
	struct TreeNode  *left;
	struct TreeNode  *right;
}TreeNode;
TreeNode* CreatBTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	else
	{
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->val = str[*pi];
		++(*pi);
		root->left = CreatBTree(str, pi);
		root->right = CreatBTree(str, pi);
		return root;
	}
}
void midover(TreeNode* root)
{
	if (root == NULL)
		return;
	midover(root->left);
	printf("%c ", root->val);
	midover(root->right);
}
int main()
{
	char str[100];
	scanf("%s", str);
	int i = 0;
	TreeNode* root = CreatBTree(str, &i);
	midover(root);
	return 0;
}