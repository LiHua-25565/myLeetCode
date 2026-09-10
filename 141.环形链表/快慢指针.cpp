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
    ListNode* reverseList(ListNode* head,ListNode* end) {
        if(!head) return nullptr;
        ListNode* last = nullptr;
        ListNode* cur = head;
        ListNode*next = head->next;
        while(next != end)
        {
            cur->next = last;
            last = cur;
            cur = next;
            next = next->next;
        }
        cur->next = last;
        return cur;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* fast = head , *slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newhead = reverseList(head,slow);
        if(fast) slow = slow->next;
        while(slow)
        {
            if(slow->val != newhead->val) return false;
            slow = slow->next;
            newhead = newhead->next;
        }
        return true;
    }
};