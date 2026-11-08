class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> RowAloneServerCol(m, -1), ColServerCount(n, 0);
        int totalServers = 0;
        for (int row = 0; row < m; row++) {
            int countServerInRow = 0;
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    countServerInRow++;
                    RowAloneServerCol[row] = col;
                    ColServerCount[col]++;
                }
            }
            if (countServerInRow > 1) {
                totalServers += countServerInRow;
                RowAloneServerCol[row] = -1;
            }
        }

        for (int row = 0; row < m; row++) {
            int col = RowAloneServerCol[row];
            if (RowAloneServerCol[row] != -1 && ColServerCount[col] > 1) {
                totalServers++;
            }
        }
        return totalServers;
    }
};