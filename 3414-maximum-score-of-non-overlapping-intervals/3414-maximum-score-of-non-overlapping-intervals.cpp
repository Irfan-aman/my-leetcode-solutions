class Solution {
public:
    struct Node {
        long long score = -1;
        vector<int> idxs;
    };
    vector<vector<Node>> dp;
    int n;
    vector<int> nextIdx;
    int findNextIdx(vector<vector<int>>& intervals, int endPoint) {
        int st = 0, end = n - 1;
        int result = n;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (intervals[mid][0] > endPoint) {
                result = mid;
                end = mid - 1;
            } else
                st = mid + 1;
        }
        return result;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            int endPoint = intervals[i][1];
            nextIdx[i] = findNextIdx(intervals, endPoint);
        }
        dp.assign(n + 1, vector<Node>(4 + 1));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                Node skip = dp[i + 1][k];
                Node temp = dp[nextIdx[i]][k - 1];
                Node take;
                take.score = intervals[i][2] + temp.score;
                take.idxs = temp.idxs;
                take.idxs.push_back(intervals[i][3]);
                sort(begin(take.idxs), end(take.idxs));
                Node result;
                if (skip.score > take.score) {
                    result = skip;
                } else if (take.score > skip.score) {
                    result = take;
                } else { // both score are equal =>chose lexicographically
                         // smallest
                    result = (skip.idxs < take.idxs) ? skip : take;
                }
                dp[i][k] = result;
            }
        }

        return dp[0][4].idxs;
    }
};