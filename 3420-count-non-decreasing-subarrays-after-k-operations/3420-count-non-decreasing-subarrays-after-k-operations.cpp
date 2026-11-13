class Solution {
public:
    typedef long long ll;
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> prefSum(n, 0);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefSum[i] = prefSum[i - 1] + nums[i];
        auto rangeSum = [&](int i, int j) -> long long {
            if (i > j)
                return 0;
            return prefSum[j] - ((i > 0) ? prefSum[i - 1] : 0);
        };
        vector<int> NGR(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            NGR[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        vector<ll> opers(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int m = NGR[i];
            ll segmentOps = (ll)nums[i] * (m - i) - rangeSum(i, m - 1);
            opers[i] = segmentOps + opers[m];
        }
        ll result = 0;
        int i = 0, j = 0;
        list<int> maxIdx;
        while (j < n) {
            while (!maxIdx.empty() && nums[maxIdx.back()] < nums[j]) {
                maxIdx.pop_back();
            }
            maxIdx.push_back(j);
            while (i <= j) {
                int m = maxIdx.front();
                ll opersCount = ((ll)opers[i] - opers[m]) +
                                ((ll)nums[m] * (j - m + 1) - rangeSum(m, j));
                if (opersCount <= k)
                    break;
                i++;
                if (maxIdx.front() < i) {
                    maxIdx.pop_front();
                }
            }
            result += (j - i + 1);
            j++;
        }
        return result;
    }
};