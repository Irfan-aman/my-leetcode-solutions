class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        int mini = min(need1, need2);
        int maxi = max(need1, need2);
        ll mixed = (ll)costBoth * mini +
                   (ll)(maxi - mini) * (maxi == need1 ? cost1 : cost2);
        return min({mixed, (ll)costBoth * max(need1, need2),
                    (ll)cost1 * need1 + (ll)cost2 * need2});
    }
};