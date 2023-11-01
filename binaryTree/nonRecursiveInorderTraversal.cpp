//https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
//leetcode94.二叉树的中序遍历（非递归）

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            
            TreeNode* top = st.top();
            st.pop();
            ret.push_back(top->val);

            cur = top->right;
        }
        return ret;
    }
};