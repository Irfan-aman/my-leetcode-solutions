class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = target[0], b = target[1], c = target[2];
        bool gotA = false, gotB = false, gotC = false;
        for (auto& t : triplets) {
            int x = t[0], y = t[1], z = t[2];
            if (x > a || y > b || z > c)
                continue;
            if (x == a)
                gotA = true;
            if (y == b)
                gotB = true;
            if (z == c)
                gotC = true;
        }
        return gotA && gotB && gotC;
    }
};