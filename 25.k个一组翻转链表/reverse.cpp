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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode newhead;
        newhead.next = head;
        ListNode* nextStart = head, *cur = head, *preEnd = &newhead;
        while(nextStart)
        {
            int n = k;
            while(nextStart&&n-->0) nextStart = nextStart->next;
            if(n>0)
            {
                preEnd->next = cur;
                break;
            }

            ListNode* curStart = cur;
            ListNode* pre = nextStart;
            
            while(cur!=nextStart)
            {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            preEnd->next = pre;
            preEnd = curStart;
        }

        return newhead.next;
    }
};