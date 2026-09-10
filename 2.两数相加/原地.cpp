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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1 ,*pre = nullptr;
        int carry = 0;
        while(l1)
        {
            if(l2) {l1->val += l2->val;l2 = l2->next;}
            pre=l1;
            l1 = l1->next;
        }
        if(l2) pre->next = l2;
        l1 = head;
        while(l1)
        {
            l1->val += carry;
            carry = l1->val/10;
            l1->val %= 10;
            pre = l1;
            l1=l1->next;
        }
        if(carry) pre->next=new ListNode(carry);
         
        return head;
    }
};