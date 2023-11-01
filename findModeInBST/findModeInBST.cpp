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
    void inOrder(TreeNode *root,vector<int> &result)
    {
        if(root==NULL) return;
        inOrder(root->left,result);
        result.push_back(root->val);
        inOrder(root->right,result);
        
    }
    vector<int> findMode(TreeNode* root) {
        int maxCount=0;
        int count=0;
        vector<int> result;
        inOrder(root,result);
        int e=0;
        for(int i=0;i<result.size();i++)
        {
            if(result[e]==result[i]) count++;
            else
            {
                maxCount=max(maxCount,count);
                e=i;
                i--;
                count=0;
            }
        }
        maxCount=max(maxCount,count);
        count=e=0;
        int k=0;
        for(int i=0;i<result.size();i++)
        {
            if(result[e]==result[i]) count++;
            else
            {
                if(count==maxCount) result[k++]=result[e];
                e=i;
                i--;
                count=0;
            }
        }
        if(count==maxCount) result[k++]=result[e];
        result.resize(k);
        return result;
    
        
        
        
    }
};