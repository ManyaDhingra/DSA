class Solution {
public:
    int product(int num) {
    int p = 1;

    while(num > 0) {
        p *= (num % 10);
        num /= 10;
    }

    return p;
}
    int smallestNumber(int n, int t) {
        int x = n;
        while(true) {

            if(product(x) % t == 0)
                return x;

            x++;
        }
        return 0;
    }
};