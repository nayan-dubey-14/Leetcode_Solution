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
    void findSecondMin(TreeNode *root,int min,int &ans,int &sMin)
    {
        if(root==NULL) return;
        if(min<root->val && root->val<=sMin)
        {
            ans=root->val;
            sMin=root->val;
        }
        findSecondMin(root->left,min,ans,sMin);
        findSecondMin(root->right,min,ans,sMin);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int min=root->val;
        int ans=-1;
        int sMin=INT_MAX;
        findSecondMin(root,min,ans,sMin);
        return ans;
        
    }
};