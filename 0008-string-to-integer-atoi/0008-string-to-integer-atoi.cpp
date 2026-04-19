class Solution {
public:
    int func(string &s, int i , long long num , int sign){
        if(i == s.size() || !isdigit(s[i])){
            return sign* num;
        }

        num = num * 10 + (s[i] - '0');

        if(sign == 1 && num > INT_MAX) return INT_MAX;
        if(sign == -1 && -num < INT_MIN) return INT_MIN;

        return func(s, i+1, num, sign);

    }
    int myAtoi(string s) {

        int i = 0;
        int sign = 1;

        while(i < s.size() && s[i] == ' '){
            i++;
        }

        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
                i++;
            }
        }

        return func(s, i, 0, sign);
       
    }
};