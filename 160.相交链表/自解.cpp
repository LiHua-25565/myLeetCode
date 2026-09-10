/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *itA = headA;
        ListNode *itB = headB;
        int m =0,n=0;
        while(itA)
        {
            ++m;
            itA=itA->next;
        }
        while(itB)
        {
            ++n;
            itB=itB->next;
        }
        itA=headA,itB=headB;
        while(m>n)
        {
            --m;
            itA = itA->next;
        }
        while(n>m)
        {
            --n;
            itB = itB->next;
        }
        while(itA&&itB)
        {
            if(itA==itB) return itA;
            itA=itA->next;
            itB = itB->next;
        }
        return 0;
    }
};