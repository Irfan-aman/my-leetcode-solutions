class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int a = 0; // dp[i+1]
        int b = 0; // dp[i+2]
        int c = 0; // dp[i+3]
        for (int i = n - 1; i >= 0; i--) {
            int ans = INT_MIN;
            ans = max(ans, stoneValue[i] - a);
            if (i + 2 <= n)
                ans = max(ans, stoneValue[i] + stoneValue[i + 1] - b);
            if (i + 3 <= n)
                ans = max(ans, stoneValue[i] + stoneValue[i + 1] +
                                   stoneValue[i + 2] - c);
            c = b;
            b = a;
            a = ans;
        }
        int diff = a;
        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        else
            return "Tie";
    }
};