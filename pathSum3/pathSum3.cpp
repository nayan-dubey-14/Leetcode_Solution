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
    void countPathSum(TreeNode *root,long &sum,int &target,int &result,map<long,long> &m)
    {
        if(root==NULL) return;
        sum+=root->val;
        auto itr=m.find(sum-target);
        if(itr!=m.end())
        {
            result+=itr->second;
        }
        m[sum]+=1;
        countPathSum(root->left,sum,target,result,m);
        countPathSum(root->right,sum,target,result,m);
        m[sum]-=1;
        sum-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        map<long,long> m;
        m[0]=1;
        long sum=0;
        int result=0;
        countPathSum(root,sum,targetSum,result,m);
        return result;
    }
};