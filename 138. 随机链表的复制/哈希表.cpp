/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* cur = head;
        Node* newhead = new Node(head->val);
        Node* newcur = newhead;
        unordered_map<Node*,Node*> m;
        m[head] = newhead;

        while(cur->next)
        {
            cur = cur->next;
            newcur->next = new Node(cur->val);
            newcur=newcur->next;
            m[cur] = newcur;
        }
        cur = head;
        newcur = newhead;
        while(cur)
        {
            newcur->random = m[cur->random];
            newcur=newcur->next;
            cur=cur->next;
        }
        return newhead;
    }
};