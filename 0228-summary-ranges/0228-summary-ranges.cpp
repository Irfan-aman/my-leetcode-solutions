class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return {};
        if(n==1)return {to_string(nums[0])};
        vector<string> res;
        int a = nums[0], b = nums[0];
        int next = a + 1;
        for (int i = 1; i < n; i++) {
            while (i < n && nums[i] == next) {
                b = next;
                i++;
                if(next<INT_MAX)next++;
            }
            if (a == b) {
                res.push_back(to_string(a));
            } else if (a != b) {
                res.push_back(to_string(a) + "->" + to_string(b));
            }
            if(i<n)a = nums[i];
            b = a;
            if(a<INT_MAX)next = a + 1;
            if (i == n - 1 && nums[n - 1] != nums[n - 2] + 1) {
                res.push_back(to_string(a));
            }
        }
        return res;
    }
};