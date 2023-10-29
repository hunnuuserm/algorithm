//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/submissions/478196237/
//leetcode236.二叉树的最近公共祖先


/*思路:
方法一的思路:
通过观察可以发现一个规则：如果当前节点是p与q的最近公共祖先，
那么p与q一定是一个在当前节点的左子树，一个在当前节点的右子树(或者 当前节点==p或当前节点==q)。
根据这个规则编写代码即可；

方法二思路：
方法一的时间复杂度大约是O(H*N)(H为树的高度，N为节点总数)，
为了把时间复杂度优化到O(N),直接用两个栈分别存储从根节点到p、q的路径，
然后像求链表相交那样求得公共节点，求得的公共节点即最近公共祖先。*/

//方法一:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool find(TreeNode* root,TreeNode* p)
    {
        if(root == nullptr) return false;
        if(root == p) return true;

        return find(root->left,p)||find(root->right,p);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;

        bool pInLeft = find(root->left,p);
        bool pInRight=!pInLeft; 

        bool qInLeft=find(root->left,q);
        bool qInRight=!qInLeft;

        if((pInLeft&&qInRight)||(pInRight&&qInLeft))
        {
            return root;
        }

        if(pInLeft&&qInLeft)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(pInRight&& qInRight)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else
        {
            return nullptr;
        }
    }
};

//方法二:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root,TreeNode* p,stack<TreeNode*>& pStack)
    {
        if(root == nullptr) return false;
        pStack.push(root);
        if(root == p)
        {
            return true;
        }

        if(findPath(root->left,p,pStack)||findPath(root->right,p,pStack))
        {
            return true;
        }
        else
        {
            pStack.pop();
            return false; 
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pStack;
        stack<TreeNode*> qStack;
        findPath(root,p,pStack);
        findPath(root,q,qStack);

        while(pStack.size()!=qStack.size())
        {
            if(pStack.size()>qStack.size())
            {
                pStack.pop();
            }
            else
            {
                qStack.pop();
            }
        }

        while(pStack.top()!=qStack.top())
        {
            pStack.pop();
            qStack.pop();
        }
        return pStack.top();
    }
};