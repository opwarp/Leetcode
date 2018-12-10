// 46. Permutations.cpp
class Solution {
public:
    vector<vector<int>> res;
    
    void genPerm(vector<vector<int>> &res, vector<int>& nums){
        if(nums.empty())
            return;
        else{
            int curNum = nums.back();
            // cout<<curNum<<endl;
            nums.pop_back();
            int totalBefore = res.size();
            for(int j=0; j<totalBefore; ++j ){
                for(int i=0; i<res[j].size(); ++i){
                    vector<int> newArray =  res[j];
                    newArray.insert(newArray.begin()+i, curNum);
                    res.push_back(newArray);
                }
                res[j].insert(res[j].end(), curNum);
            }
            genPerm(res, nums);
            return;
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        int curNum = nums.back();
        nums.pop_back();
        res.push_back( vector <int> ({curNum}) );
        genPerm(res, nums);
        return res;
    }
};