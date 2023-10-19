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
    TreeNode * createGreaterBST(TreeNode *root,int &prev)
    {
        if(root==NULL) return NULL;
        createGreaterBST(root->right,prev);
        int tmp=root->val;
        root->val+=prev;
        prev+=tmp;
        createGreaterBST(root->left,prev);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int prev=0;
        return createGreaterBST(root,prev);
    }
};