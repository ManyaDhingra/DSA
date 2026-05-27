class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string sum = "";

        int i =  a.size() - 1;
        int j =  b.size() - 1;

        while(i >= 0 || j >= 0 || carry){
            int add = carry;

            if(i >= 0){
                add += a[i] - '0';
                i--;
            }

            if(j >= 0){
                add += b[j] - '0';
                j--;
            }


            sum += (add % 2) + '0';
            carry = add / 2;
        }

        reverse(sum.begin(), sum.end());
        return sum;
    }
};