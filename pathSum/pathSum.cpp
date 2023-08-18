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
    bool hasPath(TreeNode *root,int targetSum,int &sum)
    {
        if(root==NULL) return false;
        sum+=root->val;
        bool left=hasPath(root->left,targetSum,sum);
        if(left==true) return true;
        bool right=hasPath(root->right,targetSum,sum);
        if(right==true) return true;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum) return true;
        }
        sum-=root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return hasPath(root,targetSum,sum);
        
    }
};