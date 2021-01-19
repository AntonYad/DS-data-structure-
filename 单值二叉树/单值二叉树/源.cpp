#define _CRT_SECURE_NO_WARNINGS 1
bool _isUnivalTree(struct TreeNode* root, int val)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->val != val)
	{
		return false;
	}
	return _isUnivalTree(root->left, val) && _isUnivalTree(root->right, val);
}

bool isUnivalTree(struct TreeNode* root){
	if (root == NULL)
	{
		return true;
	}
	int val = root->val;
	return _isUnivalTree(root, val);
}