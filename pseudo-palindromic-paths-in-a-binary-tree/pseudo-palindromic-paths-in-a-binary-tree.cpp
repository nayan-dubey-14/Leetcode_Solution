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
    void countPaths(TreeNode *root,vector<int> &arr,int &count)
    {
        if(root==NULL) return;
        arr[root->val]++;
        countPaths(root->left,arr,count);
        countPaths(root->right,arr,count);
        if(root->left==NULL && root->right==NULL)
        {
        int oddCount=0;
        for(int i:arr) if(i%2!=0) oddCount++;
        if(oddCount==0 || oddCount==1) count++;
        }
        arr[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> arr(10,0);
        int count=0;
        countPaths(root,arr,count);
        return count;
    }
};