class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode('\0');       
    }

    void insertion(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertion(child, word.substr(1));   // FIXED
    }
    
    void insert(string word) {
        insertion(root, word);       
    }

    bool searching(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return searching(child, word.substr(1));  // FIXED
    }

    bool search(string word) {
        return searching(root, word);
    }

    bool prefixing(TrieNode* root, string word){
        if(word.length() == 0){
            return true;    // FIXED
        }

        int index = word[0] - 'a';

        if(root->children[index] == NULL){
            return false;
        }

        return prefixing(root->children[index], word.substr(1)); // FIXED
    }
    
    bool startsWith(string prefix) {
        return prefixing(root, prefix);
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */