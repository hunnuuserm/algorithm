//leetcode 对称二叉树 https://leetcode.cn/problems/symmetric-tree/

//方法二:迭代(迭代方法学会，以前经常写递归，现在迭代也要学会)

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymmetric2(root->left, root->right);
    }
    bool isSymmetric2(TreeNode* left, TreeNode* right)
    {
        stack<TreeNode*> st;
        st.push(left);
        st.push(right);
        while (!st.empty())
        {
            TreeNode* u = st.top();
            st.pop();
            TreeNode* v = st.top();
            st.pop();

            if (u == nullptr && v == nullptr) continue;
            if (u == nullptr || v == nullptr) return false;
            if (u->val != v->val) return false;

            st.push(u->left);
            st.push(v->right);
            st.push(u->right);
            st.push(v->left);
        }
        return true;
    }
};

//方法一:递归

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymmetric2(root->left, root->right);
    }
    bool isSymmetric2(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;

        if (left->val != right->val) return false;

        return isSymmetric2(left->left, right->right)
            && isSymmetric2(left->right, right->left);
    }
};