class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int r,int c,char dig){
        for(int i=0;i<9;i++){
            if(board[i][c]==dig) return false;
        }
        for(int j=0;j<9;j++){
            if(board[r][j]==dig) return false;
        }
        int srow=( r/3) * 3 , scol= (c/3) *3;
        for(int i=srow;i<srow+3;i++){
            for(int j=scol;j<scol+3;j++){
                if(board[i][j]==dig) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int r,int c){
        if(r==9) return true;
        int x=r , y=c+1;
        if(y>8){
            x=r+1;
            y=0;
        }
        if(board[r][c]!='.')  return solve(board,x,y);
        for(char i='1';i<='9';i++){
            if(isSafe(board,r,c,i)){
                board[r][c]=i;
                if(solve(board,x,y)){
                    return true;
                }
                board[r][c]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};