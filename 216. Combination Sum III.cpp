// 216. Combination Sum III.cpp
class Solution {
public:
    void backtrack(vector<vector<int>> &results, vector<int> &result, int begin, int k, int n){
        if(k==0&&n==0){
            results.push_back(result);
            return;
        }
        for(int i=begin; i<=10-k&&k>=0; i++){
            result.push_back(i);
            backtrack(results, result, i+1, k-1, n-i); //only collect number begind i, avoid duplicte
            result.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> result;
        backtrack(results, result, 1, k, n);
        return results;
    }
};