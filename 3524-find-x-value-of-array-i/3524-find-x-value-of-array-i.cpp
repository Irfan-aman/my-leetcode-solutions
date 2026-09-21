class Solution {
public:
    typedef long long ll;
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> res(k, 0);
        vector<ll> prevCnt(k, 0);
        for (int i = 0; i < n; i++) {
            vector<ll> currentCnt(k, 0);
            int currentElemRemainder = nums[i] % k;
            currentCnt[currentElemRemainder]++;
            for (int oldRem = 0; oldRem < k; oldRem++) {
                ll newRem = ((ll)oldRem * nums[i]) % k;
                currentCnt[newRem] += prevCnt[oldRem];
            }
            prevCnt = move(currentCnt);
            for (int x = 0; x < k; x++) {
                res[x] += prevCnt[x];
            }
        }
        return res;
    }
};