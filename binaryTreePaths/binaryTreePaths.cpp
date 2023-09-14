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
    void allPaths(TreeNode *root,vector<string> &result,string str)
    {
        if(root==NULL) return;
        if(str.size()==0) str+=to_string(root->val);
        else str+="->"+to_string(root->val);
        allPaths(root->left,result,str);
        allPaths(root->right,result,str);
        if(root->left==NULL && root->right==NULL)
        {
            result.push_back(str);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string s="";
        allPaths(root,result,s);
        return result;
    }
};