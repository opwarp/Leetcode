// 216. Combination Sum III.cpp
class Solution {
public:
    vector<vector<int>> res;
    void combinationNext(int k, int n, int max, vector<int> lastSet) {
       for (int i=max; i>=1; i--){
           int nextN = n - i;
           if (nextN < k*i-k && nextN > 0){
               vector<int> curSet = lastSet;
               if (k > 2){
                   curSet.push_back(i);
                   //make it sum of one num and the rest, and recurse the rest
                   combinationNext(k-1, nextN, i-1, curSet);
               }
               //end recursion when the rest are 2 numbers
               else if (nextN < i){ //nextN < i ensure no duplicate numbers
                   curSet.push_back(i);
                   curSet.push_back(nextN);
                   res.push_back(curSet);
               }
           }
        } 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curSet;
        combinationNext(k, n, 9, curSet);
        return res;
    }
};