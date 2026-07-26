class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int n1 = series1.size();
        int n2 = series2.size();
        int i = 0, j = 0;
        while (i < n1 || j < n2) {
            int t1 = INT_MAX, t2 = INT_MAX;
            if (i < n1)
                t1 = series1[i][0];
            if (j < n2)
                t2 = series2[j][0];
            if (t1 < t2) {
                ans.push_back({series1[i][0],
                               series1[i][1] + ((j < n2) ? series2[j][1] : 0)});
                i++;
            } else if (t2 < t1) {
                ans.push_back({series2[j][0],
                               series2[j][1] + ((i < n1) ? series1[i][1] : 0)});
                j++;
            } else if (t1 == t2 && t1 != INT_MAX) {
                ans.push_back({series1[i][0], series1[i][1] + series2[j][1]});
                i++;
                j++;
            }
        }
        return ans;
    }
};