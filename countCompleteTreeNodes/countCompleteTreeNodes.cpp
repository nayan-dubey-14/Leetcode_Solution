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
    int calLeftHeight(TreeNode *t)
    {
        int h=1;
        while(t!=NULL)
        {
            h++;
            t=t->left;
        }
        return h;
    }
    int calRightHeight(TreeNode *t)
    {
        int h=1;
        while(t!=NULL)
        {
            h++;
            t=t->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=calLeftHeight(root->left);
        int rh=calRightHeight(root->right);
        //if height of left and right subtree is equal means it is full binary tree and 
        //here we apply this formula to cal no of nodes (2^h-1);
        if(lh==rh) return (1<<lh)-1;
        //if it is not equal then we check for its sub-tree
        return 1+countNodes(root->left)+countNodes(root->right);        
    }
    
};