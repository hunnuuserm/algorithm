//https://leetcode.cn/problems/binary-tree-level-order-traversal/
//leetcode102.二叉树的层序遍历

/*思路：
1.借助栈进行层序遍历；
2.用一个变量levelCount记录每一层的节点数量。*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return ret;
    }
};