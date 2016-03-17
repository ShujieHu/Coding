class TrieNode {
public:
    // Initialize your data structure here.
    bool iskey;
    TrieNode* children[26];
    TrieNode() {
        //initializze iskey
        iskey = false;
        for (int i = 0; i < 26; i++) {
            //initialize all the children
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        //gonna use a temp node as a iterator
        TrieNode* t = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!t->children[c - 'a']) {
                //children[c - 'a'] does not exists in the structure
                t->children[c - 'a'] = new TrieNode();
            }
            t = t->children[c - 'a'];
        }
        //after the for loop
        t->iskey = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* t = root;
        for (int i = 0; i < word.size(); i++) {
            if (t->children[word[i] - 'a']) {
                //if exists keep looping
                t = t->children[word[i] - 'a'];
            } else {
                return false;
            }
        }
        return t->iskey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* t = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!t->children[prefix[i] - 'a']) {
                //does not exist
                return false;
            } else {
                //does exist, keep looping
                t = t->children[prefix[i] - 'a'];
            }
        }
        return true;
    }

private:
    TrieNode* root;
};
