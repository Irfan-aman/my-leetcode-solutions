class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> freq(101);
        for (int& x : nums)
            freq[x]++;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int i = 1; i <= 100; i++) {
                if (freq[i]) {
                    ans.push_back(i);
                    freq[i]--;
                }
            }
        }
        return ans;
    }
};