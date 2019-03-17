289. Game of Life.cpp


class Solution {
public:
    int m = 0;
    int n = 0;
    int v(vector<vector<int>>& board, int a, int b){
        if(!(a<0 || a>=m || b<0 || b>=n))
        {
            // cout<<board[a][b]<<">";
            if( board[a][b]==5 || board[a][b]==4 || board[a][b]==1 ){
                return 1;
            }
                
        }
        return 0;
    }
    void update(vector<vector<int>>& board, int i, int j){
        int countALive = v(board, i-1, j-1) + v(board, i-1, j) + 
        v(board, i-1, j+1) + v(board, i, j-1) + 
        v(board, i, j+1) + v(board, i+1, j-1) + 
        v(board, i+1, j) + v(board, i+1, j+1);
        // cout<<countALive<<endl;
        if(countALive==2){
            if(board[i][j] == 0) { board[i][j] = 2; }
            if(board[i][j] == 1) { board[i][j] = 5; }
        }else if(countALive==3){
            if(board[i][j] == 0) { board[i][j] = 3; }
            if(board[i][j] == 1) { board[i][j] = 5; }
        }else{
            if(board[i][j] == 0) { board[i][j] = 2; }
            if(board[i][j] == 1) { board[i][j] = 4; }
        }
            
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        for(int i=0; i<m; i++){
            n = board[0].size();
            for(int j=0; j<n; j++){
                update(board, i, j);
            }
        }
        for(int i=0; i<m; i++){
            n = board[0].size();
            for(int j=0; j<n; j++){
                board[i][j] = board[i][j] % 2;
            }
        }
    }
};