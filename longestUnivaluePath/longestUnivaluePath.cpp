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
    int findLongestUnivaluePath(TreeNode *root,int &result)
    {
        if(root==NULL) return 0;
        int left=findLongestUnivaluePath(root->left,result);
        int right=findLongestUnivaluePath(root->right,result);
        if(left!=0 && right!=0 && root->val==root->left->val && root->val==root->right->val)
        {
            result=max(result,left+right);
            return 1+max(left,right);
        }
        if(left!=0 && root->val==root->left->val)
        {
            result=max(result,left);
            return 1+left;
        }
        if(right!=0 && root->val==root->right->val)
        {
            result=max(result,right);
            return 1+right;
        }
        return 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        int result=0;
        findLongestUnivaluePath(root,result);
        return result;
        
    }
};