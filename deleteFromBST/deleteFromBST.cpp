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
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root==NULL) return root;
        TreeNode *result=root;
        //if root is the key to delete
        if(root->val==val) 
        {
            return helper(root);
        }
        while(root!=NULL)
        {
            if(root->val>val)
            {
                if(root->left!=NULL && root->left->val==val)
                {
                    root->left=helper(root->left);
                    break;
                }
                else root=root->left;

            }
            else
            {
                if(root->right!=NULL && root->right->val==val)
                {
                    root->right=helper(root->right);
                    break;
                }
                else root=root->right;
            }
        }
        return result;
        
    }
    //this function will make the links between left-subtree rightMostNode and root's rightNode
    TreeNode * helper(TreeNode *root)
    {
        //if root has only 0,1 node;
        if(root->left==NULL) return root->right; 
        if(root->right==NULL) return root->left;
        //if root has both the nodes
        TreeNode *rightChild=root->right;
        TreeNode *lastChild=getRightLastChild(root->left);
        lastChild->right=rightChild;
        return root->left;
    }
    //this function will gives the rightMost Node
    TreeNode * getRightLastChild(TreeNode *root)
    {
        while(root->right!=NULL)
        {
            root=root->right;
        }
        return root;
    }
};