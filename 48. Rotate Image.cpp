// 48. Rotate Image.cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size()-1;
        int n = (m+2) / 2;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if( m % 2 == 0 && j == n-1) continue;
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[m-j][i];
                matrix[m-j][i] = matrix[m-i][m-j];
                matrix[m-i][m-j] = matrix[j][m-i];
                matrix[j][m-i] = tmp;
            }
        }
       
    }
};