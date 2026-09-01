class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;
    struct state {
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int maxEnergy = energy;
        int sr = 0, sc = 0; // starting row and starting column
        int litterBit[20][20];
        int litterCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litterBit[i][j] = litterCount; // 0th pos, 1th ,2nd ,,,etc
                    litterCount++;
                }
            }
        }
        if (litterCount == 0)
            return 0;
        int allCollected = (1 << litterCount) - 1; // 2^litterCount -1
        int moves = 0;
        VVVVB vis(m,
                  VVVB(n, VVB(maxEnergy + 1, VB((1 << litterCount), false))));
        queue<state> q;
        q.push({sr, sc, maxEnergy, 0});
        vis[sr][sc][maxEnergy][0] = true;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                state curr = q.front();
                q.pop();
                int currRow = curr.row;
                int currCol = curr.col;
                if (classroom[currRow][currCol] == 'R') {
                    curr.energyLeft = maxEnergy;
                }
                if (curr.collectedMask == allCollected) {
                    return moves; // return smallest
                }
                if (curr.energyLeft == 0)
                    continue;

                for (int i = 0; i < 4; i++) {
                    int x = currRow + dx[i]; // next row
                    int y = currCol + dy[i]; // next col
                    if (x < 0 || x >= m || y < 0 || y >= n ||
                        classroom[x][y] == 'X')
                        continue;
                    char cell = classroom[x][y];

                    int currEnergy = curr.energyLeft;
                    int currLitterColl = curr.collectedMask;
                    if (cell == 'R')
                        currEnergy = maxEnergy;
                    else if (cell == 'L') {
                        currLitterColl |=
                            (1 << litterBit[x][y]); // nextCollectedLitter
                    }
                    currEnergy--; // nextRemainingEnergy
                    if (!vis[x][y][currEnergy][currLitterColl]) {
                        vis[x][y][currEnergy][currLitterColl] = true;
                        q.push({x, y, currEnergy, currLitterColl});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};