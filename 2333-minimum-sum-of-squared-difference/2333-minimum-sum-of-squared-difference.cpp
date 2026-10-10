class Solution {
public:
    typedef long long ll;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        int k = k1 + k2;
        int maxDiff = 100000;
        vector<int> diff(maxDiff + 1, 0);
        for (int i = 0; i < n; i++) {
            diff[abs(nums1[i] - nums2[i])]++;
        }
        ll res = 0;
        for (int i = maxDiff; i >= 1; i--) {
            if (diff[i] == 0)
                continue;
            if (k > 0) {
                int countOps = min(diff[i], k);
                diff[i] -= countOps;
                diff[i - 1] += countOps;
                k -= countOps;
            }
            res += (ll)diff[i] * i * i;
        }
        return res;
    }
};