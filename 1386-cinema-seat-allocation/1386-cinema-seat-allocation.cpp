class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        unordered_map<int, int> mp; //<row,bookedSeatMask>
        for (auto& x : reservedSeats) {
            int row = x[0];
            int seat = x[1];
            mp[row] |= (1 << seat); // mp[row] | (1<<seat)
        }
        int ans = (n - mp.size()) * 2;
        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        for (auto& [row, bookedSeatMask] : mp) {
            bool groupA = (bookedSeatMask & maskA) == 0;
            bool groupB = (bookedSeatMask & maskB) == 0;
            bool groupC = (bookedSeatMask & maskC) == 0;
            if (groupA && groupC)
                ans += 2;
            else if (groupA || groupB || groupC)
                ans++;
        }

        return ans;
    }
};
