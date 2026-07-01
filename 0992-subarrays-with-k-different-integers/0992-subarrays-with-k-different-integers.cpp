class Solution {
public:
    int atMost(vector<int>& nums, int k) {  //count the total no. of subarray of 
                                            //atmost(max) k size , All possible 1-k size
        int n = nums.size();
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        while (j < n) {
            mp[nums[j]]++;
            while (i < n && mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};