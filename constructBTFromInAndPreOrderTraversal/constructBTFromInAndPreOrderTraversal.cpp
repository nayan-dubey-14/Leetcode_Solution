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
    TreeNode * constructTree(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &m)
    {
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode *root=new TreeNode;
        root->val=preorder[preStart];
        int elem=m[root->val];
        int nElem=elem-inStart;
        root->left=constructTree(preorder,preStart+1,preStart+nElem,inorder,inStart,elem-1,m);
        root->right=constructTree(preorder,preStart+nElem+1,preEnd,inorder,elem+1,inEnd,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        return constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        
        
    }
};