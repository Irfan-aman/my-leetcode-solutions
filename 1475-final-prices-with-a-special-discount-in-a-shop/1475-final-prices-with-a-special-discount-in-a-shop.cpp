class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() > prices[i]) {
                s.pop();
            }
            ans[i] = prices[i] - (s.empty() ? 0 : s.top());
            s.push(prices[i]);
        }
        return ans;
    }
};