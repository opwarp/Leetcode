// class Solution(object):
//     def numIslands(self, grid):
//         def sink(i,j):
//             grid[i][j] ='0'
//             for x,y in zip([i,i,i+1,i-1],[j+1,j-1,j,j]):
//                 if 0<=x<len(grid) and 0<=y<len(grid[0]) and grid[x][y] =='1':sink(x,y)
//             return 1
//         return 0 if not grid else sum(
//             sink(x,y) if grid[x][y]=='1' else 0 
//             for x in range(len(grid)) 
//             for y in range(len(grid[0])))

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int r,int c){
        if( grid[i][j] == '0' || grid[i][j] == '2'){
            return;
        }
        if(grid[i][j] == '1'){
           grid[i][j] = '2';
        }
        if(i<r-1){
            dfs(grid,i+1,j,r,c);
        }
        if(j<c-1){
            dfs(grid,i,j+1,r,c);
        }
        if(i>0){
            dfs(grid,i-1,j,r,c);
        }
        if(j>0){
            dfs(grid,i,j-1,r,c);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = 0;
        if(r>0) c = grid[0].size();
        
        int k = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j,r,c);
                    k++;
                }
            }
        }
        return k;
        
    }
};