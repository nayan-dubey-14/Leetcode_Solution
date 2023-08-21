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
    vector<int> rightSideView(TreeNode* root) {
        //level order traversal
        //inserting first right node then left
        //if it is first node then prints its value
        vector<int> result;
        if(root==NULL) return result;
        queue<TreeNode *> q;
        TreeNode *t;
        q.push(root);
        int ic=1;
        int i,j;
        while(!q.empty())
        {
            j=1;
            i=0;
            while(j<=ic)
            {
                t=q.front();
                q.pop();
                if(j==1) result.push_back(t->val);
                if(t->right!=NULL)
                {
                    q.push(t->right);
                    i++;
                }
                if(t->left!=NULL)
                {
                    q.push(t->left);
                    i++;
                }
                j++;
            }
            ic=i;
        }
        return result;
    }

        
    
};