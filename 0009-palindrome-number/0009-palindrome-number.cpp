class Solution {
    int reverse(int x){
        int ans = 0;
        while(x != 0){
            int d = x%10;
            if(ans > INT_MAX/10 || ans < INT_MIN/10){
            return 0;
            }

            ans = ans*10+d;
            x /= 10;
        }
        return ans;

    }
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if(reverse(x) == x){
            return true;
        }
        return 0;
    }
};