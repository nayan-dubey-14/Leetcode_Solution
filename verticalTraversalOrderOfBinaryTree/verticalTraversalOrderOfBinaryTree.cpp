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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> m;
        int j,i;
        int ic=0;
        TreeNode *t=root;
        vector<vector<int>> result;
        q.push({t,{0,0}});
        ic++;
        while(q.size()!=0)
        {
            j=1;
            i=0;
            while(j<=ic)
            {
                auto p=q.front();
                q.pop();
                t=p.first;
                int c=p.second.first;
                int r=p.second.second;
                m[c][r].insert(t->val);
                if(t->left!=NULL)
                {
                    q.push({t->left,{c-1,r+1}});
                    i++;
                }
                if(t->right!=NULL)
                {
                    q.push({t->right,{c+1,r+1}});
                    i++;
                }
                j++;
            }
            ic=i;
        }
        for(auto k:m)
        {
            vector<int> tmp;
            for(auto v:k.second)
            {
                tmp.insert(tmp.end(),v.second.begin(),v.second.end());
            }
            result.push_back(tmp);
        }
        return result;
        
    }
};