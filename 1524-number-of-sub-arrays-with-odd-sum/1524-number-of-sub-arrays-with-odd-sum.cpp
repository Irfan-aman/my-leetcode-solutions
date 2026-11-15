class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0, sum = 0, evenCnt = 1, oddcnt = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum % 2 == 0) {
                evenCnt++;
                res = (res + oddcnt) % MOD;
            } else {
                oddcnt++;
                res = (res + evenCnt) % MOD;
            }
        }
        return res;
    }
};