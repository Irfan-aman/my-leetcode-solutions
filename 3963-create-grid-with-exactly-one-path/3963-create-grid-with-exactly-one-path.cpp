class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> path(m, string(n, '#'));
        for (int i = 0; i < m; i++) {
            path[i][0] = '.';
        }
        for (int j = 1; j < n; j++) {
            path[m - 1][j] = '.';
        }
        return path;
    }
};