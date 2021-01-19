#define _CRT_SECURE_NO_WARNINGS 1
int  TreeDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root){
	if (root == NULL)
	{
		return true;
	}
	if (abs(TreeDepth(root->left) - TreeDepth(root->right))>1)
	{
		return false;
	}
	return isBalanced(root->left) && isBalanced(root->right);

}