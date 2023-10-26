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
    void findLeaves(TreeNode *root,pair<int,int> &p,int &max,int h)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) 
        {
            if(h>max) 
            {
                max=h;
                p.first=p.second=root->val;
            }
            if(h==max) p.second=root->val;
        return;
        }
        
        findLeaves(root->left,p,max,h+1);
        findLeaves(root->right,p,max,h+1);
    }
    TreeNode * findLCA(TreeNode *root,int p,int q)
    {
        if(root==NULL || root->val==p || root->val==q)
        {
            return root;
        }
        TreeNode *l=findLCA(root->left,p,q);
        TreeNode *r=findLCA(root->right,p,q);
        if(l==NULL) return r;
        else if(r==NULL) return l;
        else return root;

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<int,int> p;
        int h=0;
        int max=-1;
        findLeaves(root,p,max,h);
        return findLCA(root,p.first,p.second);
    }
};