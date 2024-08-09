//https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//leetcode105.从前序与中序遍历序列构造二叉树


/*思路:前序的数组用来创建树（前序数组可用来确定根节点）；
       中序的数组用来分割左右子树，子树区间确认是否继续递归创建子树，不存在子树空间则子树为空。*/

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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,int& previ,int begin,int end)
    {
        if(begin>end)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[previ++]);
        int i = begin;
        while(i<=end)
        {
            if(inorder[i] == root->val)
            {
                break;
            }
            i++;
        }
        root->left = _buildTree(preorder,inorder,previ,begin,i-1);
        root->right = _buildTree(preorder,inorder,previ,i+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int previ = 0;
        return _buildTree(preorder,inorder,previ,0,inorder.size()-1);
    }
};