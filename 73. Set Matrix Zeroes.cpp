class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ncol = matrix.size();
        int nrow = matrix[0].size();
        vector<bool> col0(ncol, false);
        vector<bool> row0(nrow, false);
        for(int i=0; i<ncol; i++){
            for(int j=0; j<nrow; j++){
                if(matrix[i][j] ==  0){
                    col0[i] = true;
                    row0[j] = true;
                }
            }
        }
        for(int i=0; i<ncol; i++){
            if(col0[i]){
                for(int j=0; j<nrow; j++){
                    matrix[i][j] = 0;                
                }
            }
        }
        for(int i=0; i<nrow; i++){
            if(row0[i]){
                for(int j=0; j<ncol; j++){
                    matrix[j][i] = 0;                
                }
            }
        }
    }
};