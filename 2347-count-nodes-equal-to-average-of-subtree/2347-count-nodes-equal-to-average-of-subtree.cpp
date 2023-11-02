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
    int findAverage(TreeNode *root,int &result)
    {
        if(root==NULL) return 0;
        int lc=findAverage(root->left,result);
        int rc=findAverage(root->right,result);
        int count=1;
        int sum=root->val;
        if(lc!=0)
        {
            count+=lc;
            sum+=root->left->val;
        }
        if(rc!=0)
        {
            count+=rc;
            sum+=root->right->val;

        }
        int avg=floor((double)sum/count);
        if(avg==root->val) result++;
        root->val=sum;
        return count;
    }
    int averageOfSubtree(TreeNode* root) {
        int result=0;
        findAverage(root,result);
        return result;
        
    }
};