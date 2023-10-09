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
class BSTIterator {
public:
    stack<TreeNode *> stk;
    BSTIterator(TreeNode* root) {
        pushNodes(root,stk);
    }
    
    int next() {
        TreeNode *tmp=stk.top();
        stk.pop();
        pushNodes(tmp->right,stk);
        return tmp->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }

    void pushNodes(TreeNode *root,stack<TreeNode *> &stk)
    {
        for(;root!=NULL;root=root->left) stk.push(root);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */