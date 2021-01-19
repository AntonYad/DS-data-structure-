#define _CRT_SECURE_NO_WARNINGS 1
void _invertTree(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		struct TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		_invertTree(root->left);
		_invertTree(root->right);
	}
}

struct TreeNode* invertTree(struct TreeNode* root){
	_invertTree(root);
	return root;

}