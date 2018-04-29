class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    cout<<nums[i] + nums[j]<<endl;
                    return vector<int> {i,j};
                }
            }
        }
        return vector<int> {};
    }
};