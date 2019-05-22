// 89. Gray Code.cpp
class Solution {
public:
    void genGray(vector<int> &preCodes, int n, int count){
        if(count>=n){return;}
        int size = preCodes.size();
        for(int i=size-1; i>=0; i--){
            preCodes.push_back(preCodes[i]|1<<(count));
        }
        genGray(preCodes, n, count+1);
    }
    vector<int> grayCode(int n) {
        vector<int> preCodes{0};
        // preCodes.push_back(0);
        // preCodes.push_back(1);
        int size = preCodes.size();
        // cout<<size<<endl;
        genGray(preCodes, n, 0);
        return preCodes;
    }
};