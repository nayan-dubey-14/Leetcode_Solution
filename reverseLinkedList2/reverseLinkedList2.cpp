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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode *l,*l2,*p2,*p1,*t;
        int diff;
        p2=head;
        t=NULL;
        //first we kept our p2 pointer at left point and t at previous of p2 pointer
        for(int i=1;i<left;i++)
        {
            t=p2;
            p2=p2->next;
        }
        //this l pointer is the leftmost pointer
        l=t;
        //this l2 is the 2nd leftmost pointer
        l2=p2;
        p1=p2->next;
        diff=right-left+1;
        //here we traverse from left to right point and reverse it
        while(diff!=0)
        {
            p2->next=t;
            t=p2;
            p2=p1;
            if(p1!=NULL) p1=p1->next;
            diff--;
        }
        //changing the links
        if(l!=NULL) l->next=t;
        l2->next=p2;
        //if l is null it means there is no leftmost point(i.e left=1)
        if(l==NULL) return t;
        //here left point is 2
        if(left<=2) return l;
        //if left point is greater than two then we have to return head 
        return head;
    
        
    }
};