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
    Node solve(vector<vector<int>>& intervals, int i, int k) {
        if (k == 0 || i >= n)
            return Node();
        if (dp[i][k].score != -1) {
            return dp[i][k];
        }
        Node skip = solve(intervals, i + 1, k);
        Node temp = solve(intervals, nextIdx[i], k - 1);
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
        } else { // both score are equal =>chose lexicographically smallest
            result = (skip.idxs < take.idxs) ? skip : take;
        }
        return dp[i][k] = result;
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
        int k = 4;
        dp.assign(n + 1, vector<Node>(k + 1));
        return solve(intervals, 0, k).idxs;
    }
};