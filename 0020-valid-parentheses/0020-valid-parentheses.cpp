class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If opening bracket, push to stack
            if (ch == '[' || ch == '(' || ch == '{') {
                st.push(ch);
            }
            // If closing bracket, check for matching opening bracket
            else {
                if (!st.empty()) {
                    char top = st.top();
                    if ((ch == ']' && top == '[') ||
                        (ch == '}' && top == '{') ||
                        (ch == ')' && top == '(')) {
                        st.pop(); // Matching pair
                    } else {
                        return false; // Mismatch
                    }
                } else {
                    return false; // Stack empty but closing bracket found
                }
            }
        }

        // If stack is empty, all brackets matched
        return st.empty();
    }
};
