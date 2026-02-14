class TrieNode{
public:
    char data;
    TrieNode* children[10];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 10; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode('\0');

    void insert(TrieNode* root, string arr){
        for(char c : arr){
            int index = c - '0';

            if(root->children[index] == NULL){
                root->children[index] = new TrieNode(c);
            }

            root = root->children[index];
        }
        root->isTerminal = true;
    }

    int findPrefix(TrieNode* root, string arr){
        int len = 0;

        for(char c : arr){
            int index = c - '0';

            if(root->children[index] == NULL){
                break;
            }

            len++;
            root = root->children[index];
        }

        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        for(int num : arr1){
            insert(root, to_string(num));
        }

        int ans = 0;

        for(int num : arr2){
            ans = max(ans, findPrefix(root, to_string(num)));
        }

        return ans;
    }
};
