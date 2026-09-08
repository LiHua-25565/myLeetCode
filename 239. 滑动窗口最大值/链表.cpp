class Solution {
    struct LinkNode {
        int val;
        LinkNode* next;
        LinkNode(int v = 0, LinkNode* n = nullptr) : val(v), next(n) {}
    };

    LinkNode* head = nullptr;

    void insert(int val) {
        if (!head || val >= head->val) {
            head = new LinkNode(val, head);
            return;
        }
        LinkNode* cur = head;
        while (cur->next && cur->next->val > val) {
            cur = cur->next;
        }
        cur->next = new LinkNode(val, cur->next);
    }

    void remove(int val) {
        if (!head) return;
        if (head->val == val) {
            LinkNode* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        LinkNode* cur = head;
        while (cur->next && cur->next->val != val) {
            cur = cur->next;
        }
        if (cur->next) {
            LinkNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        }
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        head = nullptr; 

        for (int i = 0; i < k; ++i) {
            insert(nums[i]);
        }

        vector<int> ans;
        ans.push_back(head->val); 

        for (int i = k; i < nums.size(); ++i) {
            insert(nums[i]);          
            remove(nums[i - k]);     
            ans.push_back(head->val); 
        }

        while (head) {
            LinkNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        return ans;
    }
};