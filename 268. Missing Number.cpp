// 268. Missing Number.cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = (n+1)*n/2;
        for(int i; i<n; i++){
            res = res - nums[i];
        }
        return res;
    }
};