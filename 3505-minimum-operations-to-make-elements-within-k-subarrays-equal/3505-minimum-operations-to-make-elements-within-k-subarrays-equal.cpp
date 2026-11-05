class Solution {
public:
    typedef long long ll;
    int n, x, k;
    vector<ll> minOps;
    ll dp[16][100001];
    ll solve(int count, int i) {
        if (count == k)
            return 0;
        int remSubarr = k - count;
        int totalElem = remSubarr * x;
        int lastIdx = i + totalElem - 1;
        if (lastIdx >= n)
            return 1e16;
        if (dp[count][i] != -1)
            return dp[count][i];
        ll result = minOps[i] + solve(count + 1, i + x);
        result = min(result, solve(count, i + 1));
        return dp[count][i] = result;
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        n = nums.size();
        this->x = x;
        this->k = k;
        minOps.resize(n);
        int i = 0, j = 0;
        ll leftSum = 0, rightSum = 0;
        multiset<int> left, right;
        while (j < n) {
            if (left.size() <= right.size()) {
                left.insert(nums[j]);
                leftSum += nums[j];
            } else {
                right.insert(nums[j]);
                rightSum += nums[j];
            }
            // balancing
            if (!left.empty() && !right.empty()) {
                int maxLeft = *left.rbegin();
                int minRight = *right.begin();
                if (maxLeft > minRight) {
                    left.erase(left.find(maxLeft));
                    left.insert(minRight);
                    right.erase(right.find(minRight));
                    right.insert(maxLeft);
                    leftSum += minRight - maxLeft;
                    rightSum += maxLeft - minRight;
                }
            }
            if (j - i + 1 == x) {
                int median = *left.rbegin();
                minOps[i] = rightSum - leftSum +
                            (ll)(left.size() - right.size()) * median;
                if (left.find(nums[i]) != left.end()) {
                    left.erase(left.find(nums[i]));
                    leftSum -= nums[i];
                } else {
                    right.erase(right.find(nums[i]));
                    rightSum -= nums[i];
                }
                i++;
            }
            j++;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};