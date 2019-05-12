// 59. Spiral Matrix II.cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int addX = 1, addY = 0;
        vector<vector<int>> m(n, vector<int>(n));
        int x = -1, y=0, c=1;
        while(c <= n*n){
            if( x+addX<0 || y+addY<0 || y+addY>n-1 || x+addX>n-1 || m[y+addY][x+addX]!=0){
                
                if(addX == 1&&addY == 0) { addX = 0; addY = 1; }
                else if(addX == 0&&addY == 1){ addX = -1; addY = 0; }
                else if(addX == -1&&addY == 0){addX = 0; addY = -1; }
                else if(addX == 0&&addY == -1){ addX = 1; addY = 0; }
                
            }
            x = x + addX;
            y = y + addY;
            m[y][x] = c++;
        }
        return m;
    }
};