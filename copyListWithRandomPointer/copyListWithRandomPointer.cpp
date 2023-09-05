/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //T.C=O(n);
        //S.C=O(1);
        
        if(head==NULL) return NULL;
        Node *p2=head;
        Node *p1=head->next;
        Node *tmp,*tmpHead;
        //first making a copy list and inserting node between original list nodes
        while(p2!=NULL)
        {
            tmp=new Node(p2->val);
            p2->next=tmp;
            tmp->next=p1;
            p2=p1;
            if(p1!=NULL) p1=p1->next;
        }
        p2=head;
        p1=head->next->next;
        //second,now assigning the value to random pointers of copy list
        while(p2!=NULL)
        {
            if(p2->random!=NULL)
            {
                p2->next->random=p2->random->next;
            }
            p2=p1;
            if(p1!=NULL) p1=p1->next->next;
        }
        //now changing the links of both copy and original list
        //tmp will iterate on copy list
        //p1,p2 will iterate on original list
        tmpHead=new Node(0);
        tmp=tmpHead;
        p2=head;
        p1=head->next->next;
        while(p2!=NULL)
        {
            tmp->next=p2->next;
            p2->next=p1;
            tmp=tmp->next;
            p2=p1;
            if(p1!=NULL) p1=p1->next->next;
        }
        tmp=tmpHead->next;
        delete tmpHead;
        return tmp;
        
        /*
        //T.C=O(n)+o(n);
        //S.C=O(n)+o(n)
        Node *t,*j,*tmp,*newHead=NULL;
        Node *p1=head;
        unordered_map<Node *,Node *> m1;
        unordered_map<Node *,Node *> m2;
        while(p1!=NULL)
        {
            t=new Node(p1->val);
            if(newHead==NULL)
            {
                newHead=t;
                j=t;
            }
            else
            {
                j->next=t;
                j=t;
            }
            m1.insert(pair<Node *,Node *>(p1,p1->random));
            m2.insert(pair<Node *,Node *>(p1,t));
            p1=p1->next;
        }
        t=newHead;
        j=head;
        while(t!=NULL)
        {
           tmp=m1[j];
           if(tmp!=NULL) 
           {
                p1=m2[tmp];
                t->random=p1;
           }
            t=t->next; //iterating on new list
            j=j->next; //iteration on original given list
        }
        return newHead;
        */
    }
};