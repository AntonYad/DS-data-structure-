#define _CRT_SECURE_NO_WARNINGS 1
bool isSametree(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL&&t == NULL)
	{
		return true;
	}
	if (s == NULL&&t != NULL)
	{
		return false;
	}
	if (s != NULL&&t == NULL)
	{
		return false;
	}
	if (s->val != t->val)
	{
		return false;
	}
	return isSametree(s->left, t->left) && isSametree(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (s == NULL)
	{
		return false;
	}
	if (isSametree(s, t))
	{
		return true;
	}
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}