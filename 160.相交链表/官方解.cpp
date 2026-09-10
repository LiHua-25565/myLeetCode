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
        while(itA!=itB)
        {
            itA = itA != NULL ? itA->next : headB;
            itB = itB != NULL ? itB->next : headA;
        }
        return itA;
    }
};