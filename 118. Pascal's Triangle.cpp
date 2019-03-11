// 118. Pascal's Triangle.cpp 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> res;
        vector <int> current = {};
        if(numRows == 0)
            return res;
        current = {1};
        res.push_back(current);
        if(numRows == 1)
            return res;
        current = {1, 1};
        res.push_back(current);
        if(numRows == 2)
            return res;
        vector <int> last = current;
        for(int i=2; i<numRows; i++){
            current = {1};
            for(int j=1; j<i; j++){
                current.push_back(last[j-1] + last[j]);
            }
            current.push_back(1);
            last = current;
            res.push_back(last);
        }
        return res;
    }
};