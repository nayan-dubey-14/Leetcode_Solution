/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/
void findAllRootToLeafPath(BinaryTreeNode<int> *root,vector<string> &result,string tmp)
{
if(root==NULL) return;
tmp+=to_string(root->data);
tmp+=" ";
findAllRootToLeafPath(root->left,result,tmp);
findAllRootToLeafPath(root->right,result,tmp);
if(root->left==NULL && root->right==NULL)
{
   result.push_back(tmp);
    return;
}
}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    vector<string> result;
    string tmp="";
    findAllRootToLeafPath(root,result,tmp);
    return result;

    
}