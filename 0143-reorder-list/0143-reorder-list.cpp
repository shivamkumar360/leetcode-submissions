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
    void reorderList(ListNode* head) {

        if(head==NULL || head->next==NULL)return ;

       ListNode* fast=head;
       ListNode* slow=head;
       while(fast->next != nullptr && fast->next->next != nullptr)
       {
            fast=fast->next->next;
            slow=slow->next;
       }
       ListNode* curr=slow->next;
       while(curr->next!=NULL)
       {
            ListNode* nextp=curr->next;
            curr->next=nextp->next;
            nextp->next=slow->next;
            slow->next=nextp;
       }

       ListNode* prev = head;
        curr = slow->next;

        while (curr != nullptr) {
            ListNode* nextPrev = prev->next;
            ListNode* nextCurr = curr->next;
            slow->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;

            curr = nextCurr;
            prev = nextPrev;
        }

       
        
        


        
    }
};