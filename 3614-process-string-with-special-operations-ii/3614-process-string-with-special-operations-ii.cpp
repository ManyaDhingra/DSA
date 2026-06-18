class Solution {
public:
    char processStr(string s, long long k) {

        int n = s.size();
        vector<long long> len(n);

        long long cur = 0;
        const long long LIM = 1e15 + 1;

        for(int i = 0; i < n; i++) {

            char c = s[i];

            if(islower(c))
                cur++;

            else if(c == '*') {
                if(cur > 0) cur--;
            }

            else if(c == '#') {
                cur = min(LIM, cur * 2);
            }

            len[i] = cur;
        }

        if(k >= cur)
            return '.';

        for(int i = n - 1; i >= 0; i--) {

            char c = s[i];

            long long prev =
                (i == 0 ? 0 : len[i - 1]);

            if(islower(c)) {

                if(k == prev)
                    return c;
            }

            else if(c == '#') {

                if(prev)
                    k %= prev;
            }

            else if(c == '%') {

                k = prev - 1 - k;
            }

            else { // *

                if(k == prev)
                    return '.';
            }
        }

        return '.';
    }
};