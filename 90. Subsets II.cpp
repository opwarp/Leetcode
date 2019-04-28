// 90. Subsets II.cpp

class Solution {
public:
    vector<vector<int>> fixSizeSubSet(vector<int>& nums, int size, int begin){
        if(size == 0){
            vector<vector<int>> empty={{}};
            return empty;
        }
        vector<vector<int>> assemble;
        int last=INT_MIN;
        for(int i=begin; i<nums.size(); i++){
            if(nums[i] == last){
                continue;
            }
                
            last = nums[i];
            vector<vector<int>> subsets = fixSizeSubSet(nums, size-1, i+1);
            for(auto& subset:subsets){
                subset.push_back(nums[i]);
                assemble.push_back(subset);
            }
        }
        return assemble;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        vector<vector<int>> assemble;
        if (nums.size() == 0) return assemble;
        for(int i=0; i<=nums.size(); i++){
            vector<vector<int>> subsets = fixSizeSubSet(nums, i, 0);
            assemble.insert( assemble.end(), subsets.begin(), subsets.end() );
        }
        return assemble;
    }
};