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
    ListNode* swapPairs(ListNode* head) {
        //T.C.=O(N);
        //S.C.=O(N);
        //if 0 or 1 Node is present then we return head;
        if(head==NULL || head->next==NULL) return head;
        ListNode *e,*p2,*p1,*f,*head1,*head2;
        //first we seperate our list into two linked list
        //for eg.1->2->3->4->5->6
        //one list will be = 1->3->5
        //second one will be= 2->4->6
        //for this we take three pointers
        e=head;
        p2=head->next;
        if(p2!=NULL) f=p2->next;
        head1=e;
        head2=p2;
        while(f!=NULL)
        {
            e->next=f;
            f=f->next;
            if(f!=NULL) p2->next=f; //this if condition is applicable when the given list has odd number of nodes,by this condition both the seperate list will points to the last node 
            e=e->next;
            p2=p2->next;
            if(f!=NULL) f=f->next;
        }
        //after seperating we change the links one by one
        //parallely we iterate over both list and change the links
        if(head1!=NULL && head2!=NULL)
        {
            e=head1;
            f=head2;
            p1=head1->next;
            p2=head2->next;
            while(e!=NULL && f!=NULL)
            {
                f->next=e;
                f=p2;
                e->next=f;
                e=p1;
                if(p1!=NULL) p1=p1->next;
                if(p2!=NULL) p2=p2->next;
            }
            
        }
        return head2;
    }
};