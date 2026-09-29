class Solution {
public:
    int m, n;
    int dp[101][101][101];
    bool solve(vector<vector<char>>& grid, int i, int j, int openC) {
        openC += (grid[i][j]=='('?1:-1);
        if(openC<0)return false;
        if(openC>=0 && dp[i][j][openC]!=-1){
            return dp[i][j][openC];
        }
        bool res=false;
        if(i==m-1 && j==n-1)return openC==0;
        if((i+1<m && solve(grid,i+1,j,openC)) || (j+1<n && solve(grid,i,j+1,openC))){
            return res=true;
        }
        dp[i][j][openC]= (res==true?1:0);
        return res;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if(grid[0][0]==')' || grid[m-1][n-1]=='(' || (m+n-1)%2==1){
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, 0);
    }
};