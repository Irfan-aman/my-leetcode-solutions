class Solution {
public:
    typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(
            n,
            0); // ans[i]= for left(freq[nums[i]]*i - summation
                // of(i))+ for right(summation of(i)- freq[nums[i]]*i)

        unordered_map<int, ll> mp;   // <nums[i],summation of(i)>
        unordered_map<int, ll> freq; //<nums[i],freq of nums[i]
        for (int i = 0; i < n; i++) { // left
            if (mp.count(nums[i])) {
                ans[i] += freq[nums[i]] * i - mp[nums[i]];
            }
            mp[nums[i]] += i;
            freq[nums[i]]++;
        }
        mp.clear();
        freq.clear();
        for (int i = n - 1; i >= 0; i--) { // right
            if (mp.count(nums[i])) {
                ans[i] += mp[nums[i]] - freq[nums[i]] * i;
            }
            mp[nums[i]] += i;
            freq[nums[i]]++;
        }

        return ans;
    }
};