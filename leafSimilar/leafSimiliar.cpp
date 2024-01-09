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
    void makeSeq(TreeNode *root,vector<int> &arr)
    {
        if(root==NULL) return;
        makeSeq(root->left,arr);
        makeSeq(root->right,arr);
        if(root->left==NULL && root->right==NULL) arr.push_back(root->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        vector<int> arr2;
        makeSeq(root1,arr1);
        makeSeq(root2,arr2);
        return arr1==arr2;
    }
};