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
        if(!head || !head->next) return head;
        ListNode newhead;
        ListNode* node1 = head, *node2 = head->next, *pre = &newhead;
        newhead.next = head;
        while(node2 && node2->next)
        {
            node1->next = node2->next;
            node2->next = node1;
            pre->next = node2;
            pre = node1;
            node1=node1->next;
            node2=node1->next;
        }
        if(node2)
        {
            node1->next = nullptr;
            node2->next = node1;
            pre->next = node2;
        }
        return newhead.next;
    }
};