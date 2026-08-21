class Solution {
public:
    typedef long long ll;
    ll countSmallerToLeft(vector<int>& coins, ll mid) {
        ll count = 0;
        int n = coins.size();
        int totalExpr = (1 << n) - 1;
        for (int expr = 1; expr <= totalExpr; expr++) {
            int order = 0;
            ll LCM = 0;
            for (int i = 0; i < n; i++) {
                if (expr & (1 << i)) { // ith bit set => means taking ith coins
                    order++;
                    if (LCM == 0) {
                        LCM = coins[i];
                    } else {
                        long long g = gcd(LCM, coins[i]);
                        LCM = LCM / g * coins[i];
                        if (LCM > mid)
                            break;
                    }
                }
            }
            if (LCM > mid)
                continue;
            if ((order & 1) == 0) { // even order=> subtract from count
                count -= mid / LCM;
            } else { // ODD order => add to count
                count += mid / LCM;
            }
        }
        return count;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> filter;
        int maxElem = INT_MIN;
        for (int i = 0; i < n; i++) {
            bool redundant = false;
            for (int& j : filter) {
                if (coins[i] % j == 0) { // coins[i] is redundant => Ex
                                         // filter={2} , coins[i] = 4
                    // =>4%2==0 =>4 is redundant
                    redundant = true;
                }
            }
            if (!redundant) {
                filter.push_back(coins[i]);
                maxElem = max(maxElem, coins[i]);
            }
        }
        coins = filter;
        ll l = 1, r = (ll)maxElem * k;
        ll res = -1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (countSmallerToLeft(coins, mid) >= k) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};