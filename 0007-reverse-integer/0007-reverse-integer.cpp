class Solution {
public:
    int reverse(int x) {
        int ans =0;
        int mx=pow(2,31)-1;
        int mn=-pow(2,31);
        while(x!=0)
        {
             if((ans>(mx/10))||(ans<(mn/10)))
        {
            return 0;
        }


            int d=x%10;
           
            ans=(ans*10)+d;
            x=x/10;
        }
        return ans;
        
    }
};