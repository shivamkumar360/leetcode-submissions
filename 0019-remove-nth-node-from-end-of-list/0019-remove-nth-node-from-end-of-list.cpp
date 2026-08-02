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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next==NULL)
        {
            return nullptr;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        int cnt=1;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            cnt++;
            if(cnt>=n+2)
            {
                slow=slow->next;
            }

        }
        if(n==cnt)return head->next;
         slow->next=slow->next->next;
         return head;
        
    }
};