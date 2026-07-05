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
        if (dp[i][j] != make_pair(-1,-1))
            return dp[i][j];
        int leftSum = 0, leftPaths = 0;
        int upSum = 0, upPaths = 0;
        int diagSum = 0, diagPaths = 0;
        if (isValid(i - 1, j)) {//UP
            auto [score, paths] = solve(i - 1, j, board);
            leftSum = score;
            leftPaths = paths;
            if (leftPaths > 0) {
                leftSum += getIntFromChar(board[i][j]);
            }
        }
        if (isValid(i, j - 1)) {//LEFT
            auto [score, paths] = solve(i, j - 1, board);
            upSum = score;
            upPaths = paths;
            if (upPaths > 0) {
                upSum += getIntFromChar(board[i][j]);
            }
        }
        if (isValid(i - 1, j - 1)) {//DIAGONAL
            auto [score, paths] = solve(i - 1, j - 1, board);
            diagSum = score;
            diagPaths = paths;
            if (diagPaths > 0) {
                diagSum += getIntFromChar(board[i][j]);
            }
        }

        int bestScore = max({leftSum, upSum, diagSum});
        int bestPaths = 0;

        if (leftPaths > 0 && leftSum == bestScore)
            bestPaths = (bestPaths + leftPaths) % MOD;

        if (upPaths > 0 && upSum == bestScore)
            bestPaths = (bestPaths + upPaths) % MOD;

        if (diagPaths > 0 && diagSum == bestScore)
            bestPaths = (bestPaths + diagPaths) % MOD;

        return dp[i][j]={bestScore, bestPaths};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        N = n;
        dp.assign(n, vector<pair<int,int>>(n, {-1, -1}));
        auto [maxScore, Paths] = solve(n - 1, n - 1, board);
        return {maxScore, Paths};
    }
};