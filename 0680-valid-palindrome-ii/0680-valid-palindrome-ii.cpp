
class Solution {
public:
    bool ispal(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                string a = s;
                string b = s;

                a.erase(i, 1);
                b.erase(j, 1);

                return ispal(a) || ispal(b);
            }
            i++;
            j--;
        }

        return true;
    }
};
