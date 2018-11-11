class TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    
    public:
    TrieNode() {
        isEnd = false;
        children = vector<TrieNode*>(26, nullptr);
    }
    
    public:
    bool isWordEnd() {
        return isEnd;
    }
    
    void setEnd() {
        isEnd = true;
    }
    
    TrieNode* get(char c) {
        return children[c - 'a'];
    }
    
    bool contains(char c) {
        return children[c - 'a'] != nullptr;
    }
    
    void put(char c, TrieNode* node) {
        children[c - 'a'] = node;
    }
};

class Trie {
    TrieNode* root;
    
    TrieNode* find(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->contains(c)) {
                node = node->get(c);
            } else {
                node = nullptr;
                return node;
            }
        }
        return node;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->contains(c)) {
                node->put(c, new TrieNode());
            }
            node = node->get(c);
        }
        node->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = find(word);
        return node != nullptr && node->isWordEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = find(prefix);
        return node != nullptr;
    }
};