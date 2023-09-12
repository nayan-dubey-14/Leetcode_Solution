/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

vector<int> getTopView(TreeNode<int> *root)
{
    int ic=0;
    map<int, map<int,vector<int>>> m;
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    int j,i;
    vector<int> result;
    TreeNode<int> *t=root;
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
            m[c][r].push_back(t->data);
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
        auto v=k.second.begin();
        result.push_back(*(v->second.begin()));
    }
    return result;
}

