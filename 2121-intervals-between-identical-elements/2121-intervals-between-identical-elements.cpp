class Solution {
public:
    typedef long long ll;
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<ll> ans(n, 0);
        unordered_map<int, ll> indexSum;
        unordered_map<int, ll> freq;
        for (int i = 0; i < n; i++) { // for left
            ans[i] = freq[arr[i]] * i - indexSum[arr[i]];
            indexSum[arr[i]] += i;
            freq[arr[i]]++;
        }
        indexSum.clear();
        freq.clear();
        for (int i = n - 1; i >= 0; i--) { // for right
            ans[i] += indexSum[arr[i]] - freq[arr[i]] * i;
            indexSum[arr[i]] += i;
            freq[arr[i]]++;
        }
        return ans;
    }
};