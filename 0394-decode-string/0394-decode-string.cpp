
class Solution {
public:
    string decodeString(string s) {
        stack<char> decode;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                decode.push(s[i]);
            }
            else {
                string emp = "";

                while (!decode.empty() && decode.top() != '[') {
                    emp += decode.top();
                    decode.pop();
                }

                decode.pop(); // Remove '['

                reverse(emp.begin(), emp.end());

                string num = "";
                while (!decode.empty() && isdigit(decode.top())) {
                    num += decode.top();
                    decode.pop();
                }

                reverse(num.begin(), num.end());

                int k = stoi(num);

                string repeated = "";
                for (int j = 0; j < k; j++) {
                    repeated += emp;
                }

                for (char c : repeated) {
                    decode.push(c);
                }
            }
        }

        while (!decode.empty()) {
            ans += decode.top();
            decode.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
