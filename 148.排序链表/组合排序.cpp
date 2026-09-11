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
    ListNode* _sort_list(ListNode* l1, ListNode* l2)
    {
        ListNode newhead;
        ListNode* cur = &newhead;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                cur->next = l1;
                l1=l1->next;
            }
            else
            {
                cur->next = l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;

        return newhead.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        vector<ListNode*> vec(64);
        ListNode* cur = head;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = nullptr;
            int i = 0;
            while(vec[i])
            {
                cur = _sort_list(cur,vec[i]);
                vec[i] = nullptr;
                ++i;
            }
            vec[i] = cur;
            cur = next;
        }
        
        ListNode* result;
        for(int i = 0; i < 64; ++i)
        {
            if(vec[i]) result = _sort_list(result,vec[i]);
        }
        return result; 
    }
};