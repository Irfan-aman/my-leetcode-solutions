class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec(nums.begin(), nums.end());
        sort(vec.begin(), vec.end());
        int groupNo = 0;
        unordered_map<int, int> numtoGroup;
        numtoGroup[vec[0]] = groupNo;
        unordered_map<int, list<int>> grouptoList;
        grouptoList[groupNo].push_back(vec[0]);
        for (int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i - 1]) > limit) {
                groupNo++;
            }
            grouptoList[groupNo].push_back(vec[i]);
            numtoGroup[vec[i]] = groupNo;
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int group = numtoGroup[nums[i]];
            result[i] = grouptoList[group].front();
            grouptoList[group].pop_front();
        }
        return result;
    }
};