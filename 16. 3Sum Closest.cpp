// 16. 3Sum Closest.cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int l = 0, r = nums.size()-1;
            while(l < i && r > i && target != ret){
                int cur_ret = nums[i] + nums[l] + nums[r];
                if( abs(target - cur_ret) < abs(target - ret) ){
                    ret = cur_ret;
                }
                if( cur_ret > target ){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ret;
    }
};