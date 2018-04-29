//15. 3Sum.cpp
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end()); //sort vector
//         vector<vector<int>> result;
//         int n = nums.size();
//         int lasti = INT_MIN, lastj = INT_MIN, lastk = INT_MIN;

//         for(int i=0; i<n; i++){
//             // cout<<nums[i]<<',';
//             if(nums[i] == lasti){continue;}//ignore repeat number
//             else{lasti = nums[i];}
//             lastj = INT_MIN;
//             for(int j=i+1; j<n; j++){
//                 if(nums[j] == lastj){continue;}
//                 else{lastj = nums[j];}
//                 lastk = INT_MIN;
//                 for(int k=j+1; k<n; k++){
//                     if(nums[k] == lastk){continue;}
//                     else{lastk = nums[k];}
//                     if(nums[i]+nums[j]+nums[k]==0){

//                         result.push_back(vector<int>{nums[i],nums[j],nums[k]});
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            // if `nums[i]` is positive, there is no need to iterate
            if (nums[i] > 0)
                break;
            
            int target = -nums[i];
            int front = i+1, back = nums.size()-1;
            
            // find solution starting from `nums[i]`
            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    // the whole sum is 0
                    vector<int> triplet{nums[i], nums[front], nums[back]};
                    ans.push_back(triplet);

                    // skip duplicate of number 2 and number 3
                    while (front < back && nums[front] == triplet[1])
                        front++;
                    while (front < back && nums[back] == triplet[2])
                        back--;
                }
            }
            // skip duplicate of number 1
            while (i < nums.size() && nums[i+1] == nums[i])
                i++;
        }
        return ans;
    }
};