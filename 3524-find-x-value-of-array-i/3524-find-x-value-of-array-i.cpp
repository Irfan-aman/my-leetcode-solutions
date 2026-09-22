class Solution {
public:
    typedef long long ll;
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> res(k, 0), prev(k, 0);
        for (int i = 0; i < n; i++) {
            vector<ll> curr(k, 0);
            curr[nums[i] % k]++; // for nums[i]
            for (int oldRem = 0; oldRem <= k - 1; oldRem++) {
                int newRem = ((ll)oldRem * nums[i]) % k;
                curr[newRem] += prev[oldRem];
            }
            prev = curr;
            for (int x = 0; x <= k - 1; x++) {
                res[x] += prev[x];
            }
        }
        return res;
    }
};

// The important correction from your previous version is now here:

// curr[newRem] += prev[oldRem];

// rather than =.

// What prev and curr mean

// At index i:

// prev[r]

// = number of subarrays ending at i-1 whose product % k == r.

// Then for nums[i], every such subarray can be extended:

// int newRem = (1LL * oldRem * nums[i]) % k;
// curr[newRem] += prev[oldRem];

// And this:

// curr[nums[i] % k]++;

// handles the new subarray containing only:

// nums[i]

// Finally:

// for (int x = 0; x < k; x++)
//     res[x] += prev[x];

// adds all subarrays ending at the current position to the global answer.

// Example

// Suppose:

// nums = [2, 3]
// k = 5

// After 2:

// prev = [0,0,1,0,0]

// because [2] % 5 = 2.

// Now process 3:

// Single element:

// [3] -> remainder 3

// Extend [2]:

// 2 * 3 = 6
// 6 % 5 = 1

// So:

// curr[3]++
// curr[1] += prev[2]

// giving:

// [2] -> 2
// [3] -> 3
// [2,3] -> 1

// Exactly what we want.

// Complexity

// Your solution is:

// Time: O(nk)
// Space: O(k)

// And this part:

// prev = curr;

// is perfectly fine. Since k can be relatively small/controlled depending on
// the problem constraints, there's no issue.

// You can also write the loops more idiomatically as:

// for (int oldRem = 0; oldRem < k; oldRem++)

// instead of:

// oldRem <= k - 1

// but that's purely stylistic.

// Final verdict: Correct DP, O(nk) time, O(k) space.