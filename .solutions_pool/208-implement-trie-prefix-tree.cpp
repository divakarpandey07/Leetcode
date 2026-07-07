class TrieNode {
public:
    
    TrieNode():isWord(false) {   }
    unordered_map<char, TrieNode*> children;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    
    void insert(string s) {
        if (s.size()<=0) return;
        TrieNode * node = root;
        for (int i=0; i<s.size(); i++) {
            if (node->children.find(s[i]) == node->children.end()){
                node->children[s[i]] = new TrieNode();
            }
            node = node->children[s[i]];
        }
        node->isWord = true;
    }

    
    bool search(string key) {
        return retrieve(key, true);
    }

    
    
    bool startsWith(string prefix) {
        return retrieve(prefix, false);
    }

private:

    inline bool retrieve(const string& key, bool isWord) {
        if (key.size() <= 0) return false;
        TrieNode * node = root;
        for (int i=0; i<key.length(); i++) {
            if (node->children.find(key[i]) == node->children.end()) {
                return false;
            }
            node = node->children[key[i]];
        }
        return isWord ? node->isWord : true;
    }

    TrieNode* root;
};