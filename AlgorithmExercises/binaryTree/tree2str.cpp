//https://leetcode.cn/problems/construct-string-from-binary-tree/
//leetcode606.根据二叉树创建字符串

/*思路：
一、前序遍历
二、加括号的时候，注意两点：
1.左右子树都为空时，左右括号都省略；
2.左子树不空，右子树空，右括号省略；
3.左子树空，右子树不空，左括号不能省略。*/

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
    string tree2str(TreeNode* root) {
        if(root == nullptr)
        {
            return string();
        }

        string str;
        str+=to_string(root->val);

        //左子树
        if(root->left || root->right)
        {
            str+='(';
            str+=tree2str(root->left);
            str+=')';
        }

        //右子树
        if(root->right)
        {
            str+='(';
            str+=tree2str(root->right);
            str+=')';
        }

        return str;
    }
};