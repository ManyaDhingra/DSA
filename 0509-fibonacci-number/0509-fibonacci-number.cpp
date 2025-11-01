class Solution {
public:
    int fib(int n) {
        // Base case
        if (n == 0 || n == 1)
            return n;

        // Create an array initialized to -1
        static int arr[100];
        for (int i = 0; i < 100; i++)
            arr[i] = -1;

        // Memoization check
        if (arr[n] != -1)
            return arr[n];

        // Recursive relation
        arr[n] = fib(n - 1) + fib(n - 2);

        return arr[n];
    }
};
