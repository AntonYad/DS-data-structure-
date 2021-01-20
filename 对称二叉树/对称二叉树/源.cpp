#define _CRT_SECURE_NO_WARNINGS 1

bool isMetric(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else if (p == NULL && q != NULL)
		return false;
	else if (q == NULL && p != NULL)
		return false;
	if ((p->val == q->val) && isMetric(p->left, q->right) && isMetric(p->right, q->left))
		return true;
	else
		return false;
}
bool isSymmetric(struct TreeNode* root) {

	return isMetric(root, root);

}