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
    TreeNode * findLCA(TreeNode *root,int s,int t)
    {
        if(root==NULL || root->val==s || root->val==t)
        {
            return root;
        }
        TreeNode *l=findLCA(root->left,s,t);
        TreeNode *r=findLCA(root->right,s,t);
        if(l==NULL) return r;
        if(r==NULL) return l;
        else return root;
    }
    bool findPath(TreeNode *root,int t,string &result)
    {
        if(root==NULL) return false;
        if(root->val==t) return true;
        result+="L";
        bool l=findPath(root->left,t,result);
        if(l==true)
        {
            return true;
        }
        result.pop_back();
        result+="R";
        bool r=findPath(root->right,t,result);
        if(r==true)
        {
            return true;
        }
        result.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca=findLCA(root,startValue,destValue);
        string result="";
        findPath(lca,startValue,result);
        for(int i=0;i<result.size();i++) result[i]='U';
        findPath(lca,destValue,result);
        return result;
    }
};