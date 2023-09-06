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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> result;
        int size=0;
        int times,tmp;
        ListNode *t,*p;
        for(t=head;t!=NULL;t=t->next) size++;
        t=head;
        while(k>0)
        {
            times=ceil((double)size/k);
            tmp=times;
            result.push_back(t);
            while(times>1)
            {
                times--;
                t=t->next;
            }
            if(t!=NULL)
            {
            p=t->next;
            t->next=NULL;
            }
            t=p;
            size-=tmp;
            k--;
        }
        return result;

        
    }
};