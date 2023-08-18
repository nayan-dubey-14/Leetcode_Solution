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
    void findPathSum(TreeNode *root,vector<vector<int>> &result,vector<int> &tmp,int &sum,int &targetSum)
    {
        if(root==NULL) return ;
        sum+=root->val;
        tmp.push_back(root->val);
        findPathSum(root->left,result,tmp,sum,targetSum);
        findPathSum(root->right,result,tmp,sum,targetSum);
        if(root->left==NULL && root->right==NULL) 
        {
            if(sum==targetSum)
            {
                result.push_back(tmp);
            }
        }
        sum-=root->val;
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> tmp;
        int sum=0;
        findPathSum(root,result,tmp,sum,targetSum);
        return result;
        
    }
};