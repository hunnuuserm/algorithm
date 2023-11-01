//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//nowcoder.JZ36二叉搜索树与双向链表

//思路:通过定义prev来记录上一个访问的节点，从而与当前节点构成链表中的前后节点。

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	void inOrder(TreeNode* cur,TreeNode*& prev)
	{
		if(cur == nullptr)
		{
			return;
		}

		inOrder(cur->left,prev);
		cur->left=prev;
		if(prev)
		{
			prev->right=cur;
		}
		prev=cur;
		inOrder(cur->right,prev);
	}
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* prev = nullptr;
		inOrder(pRootOfTree,prev);
		TreeNode*cur=pRootOfTree;
		while(cur && cur->left)
		{
			cur=cur->left;
		}
		return cur;
    }
};
