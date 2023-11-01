//https://leetcode.cn/problems/binary-tree-preorder-traversal/
//leetcode144.二叉树的前序遍历（非递归）

//思路:看笔记

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> st;
        vector<int> ret;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                ret.push_back(cur->val);
                cur=cur->left;
            }

            TreeNode* top = st.top();
            st.pop();
            cur = top->right;
        }
        return ret;

    }
};