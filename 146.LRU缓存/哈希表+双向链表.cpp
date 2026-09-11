class LRUCache {
private:
    struct ListNode
    {
        int key = 2147483647;
        int val = 0;
        ListNode* last = nullptr;
        ListNode* next = nullptr;
        ListNode(int k, int value): key(k),val(value){};
    };
    struct List
    {
        ListNode* end = new ListNode(2147483647,0);
        List()
        {
            end->next = end;
            end->last = end;
        }
        void push_back(ListNode* node)
        {
            node->next = end;
            node->last = end->last;
            end->last->next = node;
            end->last = node;
        }
        ListNode* erase(ListNode* node)
        {
            if(node == end) return nullptr;
            node->last->next = node->next;
            node->next->last = node->last;
            return node;
        }
        void refresh_node(ListNode* node)
        {
            if(node==end) return;
            erase(node);
            push_back(node);
        }
    };

private:
    int capacity = 0;
    unordered_map<int, ListNode*> cache_map;
    List list;
public:
    LRUCache(int capacity) {
        this->capacity = capacity; 
    }
    
    int get(int key) {
        if(cache_map.find(key) != cache_map.end())
        {
            ListNode* node = cache_map[key];
            list.refresh_node(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        if(cache_map.find(key) != cache_map.end())
        {
            ListNode* node = cache_map[key];
            node->val = value;
            list.refresh_node(node);
        }
        else
        {
            ListNode* node = new ListNode(key,value);
            cache_map[key] = node;
            list.push_back(node);
            if(cache_map.size()>capacity)
            {
                ListNode* temp = list.end->next;
                list.erase(temp);
                cache_map.erase(temp->key);
                delete temp;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */