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
    void sumAll(TreeNode *root,string str,int &result)
    {
        if(root==NULL) return ;
        str+=to_string(root->val);
        sumAll(root->left,str,result);
        sumAll(root->right,str,result);
        if(root->left==NULL && root->right==NULL)
        {
           result+=atoi(str.c_str());
        }
    }
    int sumNumbers(TreeNode* root) {
        string str="";
        int result=0;
        sumAll(root,str,result);
        return result;
        
    }
};