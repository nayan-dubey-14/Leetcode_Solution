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
    bool findSmallest(TreeNode *root,int k,int &count,int &result)
    {
        if(root==NULL) return false;
        bool l=findSmallest(root->left,k,count,result);
        if(l==true) return true;
        count++;
        if(count==k)
        {
            result=root->val;
            return true;
        }
        bool r=findSmallest(root->right,k,count,result);
        if(r==true) return true;
        return false;
    }
    int kthSmallest(TreeNode* root, int k) {
        int result=0;
        int count=0;
        findSmallest(root,k,count,result);
        return result;
        
    }
};