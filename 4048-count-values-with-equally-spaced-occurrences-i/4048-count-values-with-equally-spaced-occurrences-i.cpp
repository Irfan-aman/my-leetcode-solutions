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
            if (pos.size() == 3) {
                if (pos[1] - pos[0] == pos[2] - pos[1])
                    res++;
            }
        }
        return res;
    }
};