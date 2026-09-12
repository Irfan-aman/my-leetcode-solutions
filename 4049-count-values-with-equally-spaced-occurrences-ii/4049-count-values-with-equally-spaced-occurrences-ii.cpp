class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[nums[i]].push_back(i);
        }
        int res = 0;
        for (auto& it : map) {
            auto& pos = it.second;
            if (pos.size() >= 3) {
                int d = pos[1] - pos[0];
                bool flag = false;
                for (int i = 2; i < pos.size(); i++) {
                    if (pos[i] - pos[i - 1] != d) {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    res++;
            }
        }
        return res;
    }
};