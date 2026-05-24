class Solution {
public:
    int count1(int n){
        if(n == 0){
            return 0;
        }

        string ans = "";

        while(n > 0){
            ans += (n%2) + '0';
            n /= 2;
        }

        int count = 0;

        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i] == '1'){
                count++;
            }
        }

        return count;


    }
    int hammingWeight(int n) {

        return count1(n);
        
    }
};