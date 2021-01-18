#define _CRT_SECURE_NO_WARNINGS 1
int maxDepth(struct TreeNode* root){
	int leftsize;
	int rightsize;
	int maxsize;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		leftsize = maxDepth(root->left) + 1;
		rightsize = maxDepth(root->right) + 1;
		maxsize = leftsize>rightsize ? leftsize : rightsize;
	}
	return maxsize;
}