class Trie {
private:
    struct Node{
        bool is_end = false;
        unordered_map<char,Node*> children;
    };

    Node* root;

public:
    Trie() {
        root = new Node(0);
    }
    
    void insert(string word) {
        Node* cur = root;
        int i = 0;
        while(i<word.size() && cur->children.find(word[i]) != cur->children.end())
        {
            cur = cur->children[word[i++]];
        }
        for(int j = i; j < word.size(); ++j)
        {
            Node* temp = new Node();
            cur->children[word[j]] = temp;
            cur = temp;
        }
        cur->is_end = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        int i=0;
        while(i<word.size() && cur->children.find(word[i]) != cur->children.end())
        {
            cur = cur->children[word[i++]];
        }
        if(i<word.size()||!cur->is_end) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        int i=0;
        while(i<prefix.size() && cur->children.find(prefix[i]) != cur->children.end())
        {
            cur = cur->children[prefix[i++]];
        }
        if(i<prefix.size()) return false;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */