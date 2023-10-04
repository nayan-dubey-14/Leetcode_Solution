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
    void flatten(TreeNode* root) {
        TreeNode *curr=root;
        TreeNode *prev;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
               // cout<<curr->val<<endl;
                curr=curr->right;
            }
            else
            {
                prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr) 
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=curr;
                   // cout<<curr->val<<endl;
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    prev->left=NULL;
                    TreeNode *tmp=curr->right;
                    curr->right=curr->left;
                    prev->right=tmp;
                    curr->left=NULL;
                    curr=tmp;
                }
            }
        }
        return;
        
    }
};