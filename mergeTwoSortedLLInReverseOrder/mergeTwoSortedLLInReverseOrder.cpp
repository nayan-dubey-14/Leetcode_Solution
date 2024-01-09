class Solution
{
    public:
    Node * reverseList(Node *ptr)
    {
        Node *p1,*p2;
        Node *tmp=NULL;
        p2=ptr;
        p1=p2->next;
        while(p2!=NULL)
        {
            p2->next=tmp;
            tmp=p2;
            p2=p1;
            if(p1!=NULL) p1=p1->next;
        }
        return tmp;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        if(node1==NULL && node2==NULL) return NULL;
        if(node1==NULL && node2!=NULL) return reverseList(node2);
        else if(node1!=NULL && node2==NULL) return reverseList(node1);
        Node *node3,*tmp;
        node3=tmp=NULL;
        while(node1!=NULL && node2!=NULL)
        {
            if(node1->data<node2->data)
            {
                if(node3==NULL)
                {
                    node3=node1;
                    tmp=node1;
                    node1=node1->next;
                    continue;
                }
                else
                {
                    tmp->next=node1;
                    node1=node1->next;
                }
                
            }
            else
            {
                if(node3==NULL)
                {
                    node3=node2;
                    tmp=node2;
                    node2=node2->next;
                    continue;
                }
                else
                {
                    tmp->next=node2;
                    node2=node2->next;
                }
                
            }
            tmp=tmp->next;
        }
        if(node1!=NULL) tmp->next=node1;
        if(node2!=NULL) tmp->next=node2;
        return reverseList(node3);
    }