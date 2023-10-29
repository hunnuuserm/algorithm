//https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
//leetcode107.二叉树的层序遍历II

/*这一题是返回自底向上的层序遍历结果，只需在执行leetcode102.二叉树的层序遍历的代码后，
reverse一下最后返回的vector<vector<int>>的二维数组即可。*/


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        int levelCount=q.size();
        while(!q.empty())//while(levelCount)也能通过
        {
            vector<int> v;
            for(int i=0;i<levelCount;i++)
            {
                v.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            levelCount=q.size();
            ret.push_back(v);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};