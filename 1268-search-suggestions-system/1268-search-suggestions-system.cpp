class TrieNode{
public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch){
            data = ch;
            for(int i = 0; i<26 ; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};
class Solution {
    TrieNode* root = new TrieNode('\0');
public:
    void ins(TrieNode* root, string word){
        for(char ch : word){
            int index = ch - 'a';
            if(root -> children[index] == NULL){
                root -> children[index] = new TrieNode(ch);
            }
            root= root-> children[index];
        }
        root -> isTerminal = true;
    }
    vector<vector<string>> sujj(string searchWord){
        TrieNode* prev = root;
        string prefix = "";
        vector<vector<string>> op;

        for(int i = 0 ; i < searchWord.length(); i++){

        char lastch = searchWord[i];
        prefix.push_back(lastch);

        TrieNode* curr = NULL;

        if(prev != NULL)
            curr = prev->children[lastch - 'a'];

        vector<string> temp;

        if(curr != NULL){
            prnSujj(curr, temp, prefix);
            prev = curr;
        }
        else{
            prev = NULL;   
        }
            op.push_back(temp);
            temp.clear();
        }
        return op;

    }
    void prnSujj(TrieNode* curr, vector<string>& temp, string prefix){

        if(temp.size() == 3)
            return;

        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(int i = 0; i < 26; i++){

            if(curr->children[i] != NULL){

                char ch = 'a' + i;
                prnSujj(curr->children[i], temp, prefix + ch);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for(int i = 0 ; i< products.size(); i++){
            string word = products [i];
            ins(root , word);
        }
        return sujj(searchWord);
        
    }
};