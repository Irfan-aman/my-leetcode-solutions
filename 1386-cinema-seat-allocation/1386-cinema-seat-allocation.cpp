class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        int ans = 0;
        unordered_map<int, vector<int>> mp;
        for (auto& x : reservedSeats) {
            mp[x[0]].push_back(x[1]);
        }
        for (auto& it : mp) {
            vector<bool> Occupied(11, false);
            for (int& x : it.second)
                Occupied[x] = true;
            bool left = true, middle = true, right = true;
            for (int i = 2; i <= 5; i++) {
                if (Occupied[i])
                    left = false;
            }
            for (int i = 4; i <= 7; i++) {
                if (Occupied[i])
                    middle = false;
            }
            for (int i = 6; i <= 9; i++) {
                if (Occupied[i])
                    right = false;
            }
            if (left && right)
                ans += 2;
            else if (left || right || middle)
                ans++;
        }
        ans += (n - mp.size()) * 2;
        return ans;
    }
};
