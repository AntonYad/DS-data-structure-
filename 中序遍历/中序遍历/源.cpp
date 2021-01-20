#define _CRT_SECURE_NO_WARNINGS 1
int Treesize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + Treesize(root->left) + Treesize(root->right);
}
void _inorderTraversal(struct TreeNode* root, int* array, int* pi)
{
	if (root == NULL)
	{
		return;
	}
	_inorderTraversal(root->left, array, pi);
	array[(*pi)++] = root->val;
	_inorderTraversal(root->right, array, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int size = Treesize(root);
	int* array = (int*)malloc(sizeof(int)*size);
	int i = 0;
	_inorderTraversal(root, array, &i);
	*returnSize = size;
	return array;
}