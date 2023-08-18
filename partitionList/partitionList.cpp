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
    ListNode* partition(ListNode* head, int x) {
        ListNode *head1,*head2,*e,*f;
        head1=head2=e=f=NULL;
        for(ListNode *t=head;t!=NULL;t=t->next)
        {
            if(t->val<x)
            {
                if(head1==NULL)
                {
                    head1=t;
                    e=t;
                }
                else
                {
                    e->next=t;
                    e=t;
                }
        }
            else
            {
                if(head2==NULL)
                {
                    head2=t;
                    f=t;
                }
                else
                {
                    f->next=t;
                    f=t;
                }

            }
        }
        if(e!=NULL) e->next=head2;
        if(f!=NULL) f->next=NULL;
        if(e==NULL) return head2;
        else return head1;
        
    }
};