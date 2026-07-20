class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size() , n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int idx=i*n+j;
                idx = (idx + k) % (m * n);
                ans[idx/n][idx%n]=grid[i][j];
            }
        }
        return ans;
    }
};