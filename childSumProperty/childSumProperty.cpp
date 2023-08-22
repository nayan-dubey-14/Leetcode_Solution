/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/
int checkParentSum(Node *root)
{
    if(root==NULL) return 0;
    int left=checkParentSum(root->left);
    if(left==-1) return -1;
    int right=checkParentSum(root->right);
    if(right==-1) return -1;
    if(root->left!=NULL || root->right!=NULL)
    {
        if(left+right!=root->data) return -1;
    }
    return root->data;
}
bool isParentSum(Node *root){
    if(checkParentSum(root)==-1) return false;
    return true;






    
}