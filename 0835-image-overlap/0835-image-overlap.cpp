class Solution {
public:
    int overlapCount(vector<vector<int>>& img1, vector<vector<int>>& img2,
                     int rowOff, int colOff) {
        int count = 0;
        int n = img1.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x2 = i + rowOff;
                int y2 = j + colOff;
                if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n)
                    continue;
                if (img1[i][j] == 1 && img2[x2][y2] == 1)
                    count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverlap = 0;
        for (int rowOff = -n + 1; rowOff < n; rowOff++) {
            for (int colOff = -n + 1; colOff < n; colOff++) {
                int count = overlapCount(img1, img2, rowOff, colOff);
                maxOverlap = max(maxOverlap, count);
            }
        }
        return maxOverlap;
    }
};