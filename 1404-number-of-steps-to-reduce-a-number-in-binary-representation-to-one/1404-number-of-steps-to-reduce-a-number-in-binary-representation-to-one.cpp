class Solution {
public:

    int reduce(string s){
        int num = decimal(s);
        int count = 0;

        while(num != 1){

            if(num % 2 == 0){
                num /= 2;
            }
            else{
                num += 1;
            }

            count++;
        }
        return count;
    }
    int decimal(string s){
        int num = 0;
        for(int i = 0; i<s.length(); i++){
            num = num * 2 + (s[i] - '0');
        }
        return num;
    }
    int numSteps(string s) {
        return reduce(s);
        
    }
};