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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root==NULL) return result;
        queue<TreeNode *> q;
        TreeNode *t=root;
        int ic,i,j;
        int largest;
        q.push(t);
        ic=1;
        while(q.size()!=0)
        {
            i=0;
            j=1;
            largest=q.front()->val;
            while(j<=ic)
            {
                t=q.front();
                q.pop();
                if(t->val>largest) largest=t->val;
                if(t->left!=NULL)
                {
                    q.push(t->left);
                    i++;
                }
                if(t->right!=NULL)
                {
                    q.push(t->right);
                    i++;
                }
                j++;
            }
            ic=i;
            result.push_back(largest);
        }
        return result;
    }
};