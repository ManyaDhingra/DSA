class Solution {
public:
    int calculate(string s) {

        stack<int> st;

        int result = 0;
        long long num = 0;
        int sign = 1;

        for(int i = 0; i < s.size(); i++){

            char c = s[i];

            // build number
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }

            // plus
            else if(c == '+'){
                result += sign * num;
                num = 0;
                sign = 1;
            }

            // minus
            else if(c == '-'){
                result += sign * num;
                num = 0;
                sign = -1;
            }

            // opening bracket
            else if(c == '('){

                // save current result and sign
                st.push(result);
                st.push(sign);

                // reset
                result = 0;
                sign = 1;
            }

            // closing bracket
            else if(c == ')'){

                result += sign * num;
                num = 0;

                // multiply with sign before bracket
                result *= st.top();
                st.pop();

                // add previous result
                result += st.top();
                st.pop();
            }
        }

        result += sign * num;

        return result;
    }
};