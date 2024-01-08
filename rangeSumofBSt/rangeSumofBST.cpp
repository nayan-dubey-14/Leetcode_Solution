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
    void calSum(TreeNode *root,int low,int high,int &sum)
    {
        if(root==NULL) return;
        calSum(root->left,low,high,sum);
        calSum(root->right,low,high,sum);
        if(low<=root->val && root->val<=high) sum+=root->val;
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        calSum(root,low,high,sum);
        return sum;
    }
};