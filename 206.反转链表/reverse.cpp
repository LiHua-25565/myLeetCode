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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* last = nullptr;
        ListNode* cur = head;
        ListNode*next = head->next;
        while(next)
        {
            cur->next = last;
            last = cur;
            cur = next;
            next = next->next;
        }
        cur->next = last;
        return cur;
    }
};