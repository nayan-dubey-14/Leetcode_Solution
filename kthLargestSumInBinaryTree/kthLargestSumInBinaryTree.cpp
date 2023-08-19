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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        queue<TreeNode *> q;
        TreeNode *t;
        int i,j,insertionCount=0;
        long long sum;
        t=root;
        q.push(t);
        insertionCount=1;
        while(!q.empty())
        {
            j=1;
            i=0;
            sum=0;
            while(j<=insertionCount)
            {
                t=q.front();
                q.pop();
                sum+=t->val;
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
            insertionCount=i;
            if(pq.size()<k) pq.push(sum);
            else
            {
                if(sum>pq.top()) 
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        if(pq.size()<k) return -1;
        return pq.top();
        
        
    }
};