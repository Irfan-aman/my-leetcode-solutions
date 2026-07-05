class Solution {
public:
    int N;
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> dp;
    int getIntFromChar(char ch) { return ch == 'S' ? 0 : ch - '0'; }
    bool isValid(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }
    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (board[i][j] == 'X')
            return {0, 0};
        else if (board[i][j] == 'E')
            return {0, 1};
        if (dp[i][j] != make_pair(-1, -1))
            return dp[i][j];
        int upScore = 0, upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;

        if (isValid(i - 1, j)) { // UP
            auto [score, paths] = solve(i - 1, j, board);
            upScore = score;
            upPaths = paths;
            if (upPaths > 0)
                upScore += getIntFromChar(board[i][j]);
        }

        if (isValid(i, j - 1)) { // LEFT
            auto [score, paths] = solve(i, j - 1, board);
            leftScore = score;
            leftPaths = paths;
            if (leftPaths > 0)
                leftScore += getIntFromChar(board[i][j]);
        }

        if (isValid(i - 1, j - 1)) { // DIAGONAL
            auto [score, paths] = solve(i - 1, j - 1, board);
            diagScore = score;
            diagPaths = paths;
            if (diagPaths > 0)
                diagScore += getIntFromChar(board[i][j]);
        }

        int bestScore = max({upScore, leftScore, diagScore});
        int bestPaths = 0;

        if (upPaths > 0 && upScore == bestScore)
            bestPaths = (bestPaths + upPaths) % MOD;

        if (leftPaths > 0 && leftScore == bestScore)
            bestPaths = (bestPaths + leftPaths) % MOD;

        if (diagPaths > 0 && diagScore == bestScore)
            bestPaths = (bestPaths + diagPaths) % MOD;

        return dp[i][j] = {bestScore, bestPaths};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        N = n;
        dp.assign(n, vector<pair<int, int>>(n, {-1, -1}));
        auto [maxScore, Paths] = solve(n - 1, n - 1, board);
        return {maxScore, Paths};
    }
};