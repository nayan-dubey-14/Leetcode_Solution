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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *prev,*curr;
        prev=NULL;
        curr=root;
        while(curr!=NULL)
        {
            prev=curr;
            if(curr->val>val) curr=curr->left;
            else curr=curr->right;
        }
        curr=new TreeNode(val);
        if(prev==NULL) return curr;
        else if(prev->val>val) prev->left=curr;
        else prev->right=curr;
        return root;
    }
};