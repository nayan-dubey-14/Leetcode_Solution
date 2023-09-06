/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode *tmp,*tmpHead,*p1,*p2;
        p1=head->next;
        p2=head;
        tmp=NULL;
        int size=0;
        while(p2!=NULL)
        {
            p2->next=tmp;
            tmp=p2;
            p2=p1;
            if(p1!=NULL) p1=p1->next;
            size++;
        }
        tmpHead=tmp;
        tmp=NULL;
        p2=tmpHead;
        p1=tmpHead->next;
        int i=k%size;
        while(i>0 && p2!=NULL)
        {
            p2->next=tmp;
            tmp=p2;
            p2=p1;
            if(p1!=NULL) p1=p1->next;
            i--;
        }
        head=tmp;
        tmp=NULL;
        while(p2!=NULL)
        {
            p2->next=tmp;
            tmp=p2;
            p2=p1;
            if(p1!=NULL) p1=p1->next;
        }
        //if size and k are same means number of steps to rotate is equal to size
        if(size==k || k%size==0) head=tmp;
        else tmpHead->next=tmp;
        return head;
        
        
        
        
        
        
        /*
        //T.C=O(kn);
        //S.C=O(1);
        if(head==NULL || head->next==NULL) return head;
        ListNode *p1,*p2,*tmp;
        while(k>0)
        {
            p2=tmp=p1=head;
            while(p2->next!=NULL)
            {
                tmp=p2;
                p2=p2->next;
            }
            p2->next=p1;
            tmp->next=NULL;
            head=p2;
            k--;
        }
        return head;
        */
    }
};