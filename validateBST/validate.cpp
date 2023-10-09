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
    bool validBST(TreeNode *root,long min,long max)
    {
        if(root==NULL) return true;
        if(root->val>=max || root->val<=min) return false;
        bool left=validBST(root->left,min,root->val);
        if(left==false) return false;
        bool right=validBST(root->right,root->val,max);
        if(right==false) return false;
        return true; 
    }
    bool isValidBST(TreeNode* root) {
        return validBST(root,LONG_MIN,LONG_MAX);
        
    }
};