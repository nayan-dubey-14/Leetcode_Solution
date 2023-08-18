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
    int findMaxPathSum(TreeNode *root,int &result)
    {
        if(root==NULL) return 0;
        int leftValue=max(0,findMaxPathSum(root->left,result));
        int rightValue=max(0,findMaxPathSum(root->right,result));
        result=max(result,(root->val+leftValue+rightValue));
        return max(leftValue,rightValue)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        findMaxPathSum(root,result);
        return result;
        
    }
};