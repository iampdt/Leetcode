 struct TrieNode {
    bool endWord;
    string lastword;
    TrieNode* children[26]; 

    // Constructor for the node to initialize values
    TrieNode() {
        endWord = false;
        lastword = "";
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private: 
TrieNode* root;
public:
    Trie() {

       root = new TrieNode();
        
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            if(curr->children[ch-'a'] == nullptr) 
            {
                curr->children[ch-'a'] = new TrieNode();   
            }
            curr = curr->children[ch-'a'];
        }
        curr->lastword = word;
        curr->endWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            if(curr->children[ch-'a'] == nullptr) return false;
            curr = curr->children[ch-'a'];
        }
        return curr->lastword == word && curr->endWord == true ? true : false;
    }
    
    bool startsWith(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            if(!curr->children[ch-'a']) return false;
            curr = curr->children[ch-'a'];
        }
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