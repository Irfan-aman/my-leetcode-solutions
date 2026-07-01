class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    bool safeness(vector<vector<int>> &dnt,int n,int sf){
        if(dnt[0][0]<sf) return false;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            if(r==n-1 && c==n-1) return true;
            q.pop();
            for(int i=0;i<4;i++){
                int x=r + dx[i];
                int y=c + dy[i];
                if(x>=0 && x<n && y>=0 && y<n && !vis[x][y] && sf<=dnt[x][y]){
                    vis[x][y]=true;
                    q.push({x,y});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return 0;
        vector<vector<int>> dnt(n,vector<int>(n,-1));//distance to nearest theif for each cell
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) {
                    dnt[i][j]=0;
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x=r + dx[i];
                int y=c + dy[i];
                if(x>=0 && x<n && y>=0 && y<n && !vis[x][y]){
                    dnt[x][y]=dnt[r][c]+1;
                    vis[x][y]=true;
                    q.push({x,y});
                }
            }
        }
        
        int l = 0;
        int r =min(dnt[0][0], dnt[n-1][n-1]);
        int ans=0;
        while(l<=r){
            int mid_sf=(l+r)/2;
            if(safeness(dnt,n,mid_sf)){
                ans=max(ans,mid_sf);
                l=mid_sf+1;
            }else r=mid_sf-1;
        }
        return ans;
    }
};