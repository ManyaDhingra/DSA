
class Solution {
public:
    unordered_map<int, int> mp;

    int convert(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        for (int i = 1; i < month; i++) {
            day += mp[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        mp[1] = 31;
        mp[2] = 28;
        mp[3] = 31;
        mp[4] = 30;
        mp[5] = 31;
        mp[6] = 30;
        mp[7] = 31;
        mp[8] = 31;
        mp[9] = 30;
        mp[10] = 31;
        mp[11] = 30;
        mp[12] = 31;

        int a1 = convert(arriveAlice);
        int a2 = convert(leaveAlice);
        int b1 = convert(arriveBob);
        int b2 = convert(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        if (start > end)
            return 0;

        return end - start + 1;
    }
};
