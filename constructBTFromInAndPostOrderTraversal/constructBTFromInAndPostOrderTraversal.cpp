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
    TreeNode * constructTree(vector<int> &postOrder,int postStart,int postEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &m)
    {
        if(postStart>postEnd || inStart>inEnd) return NULL;
        TreeNode *root=new TreeNode;
        root->val=postOrder[postEnd];
        int elem=m[root->val];
        int nElem=elem-inStart;
        root->left=constructTree(postOrder,postStart,postStart+nElem-1,inorder,inStart,elem-1,m);
        root->right=constructTree(postOrder,postStart+nElem,postEnd-1,inorder,elem+1,inEnd,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m;
        //reverse(postorder.begin(),postorder.end());
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        return constructTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,m);
        
    }
};