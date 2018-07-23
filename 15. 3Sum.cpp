class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //sort vector
        vector<vector<int>> result;
        int n = nums.size();
        int lasti = 0, lastj = 0, lastk = n-1;
        for(int i=0; i<n-2; i++){
            if( i!=lasti && nums[i] == nums[lasti]){continue;}//ignore repeat number
            else{lasti = i;} //update when firstly meet new number
            lastj = i+1;
            lastk = n-1;
            for(int j=lastj; j<n-1; j++){
                if(j != lastj && nums[j] == nums[lastj]){continue;}
                else{lastj = j;}
                for(int k=lastk; k>j; k--){
                    if(k!= lastk && nums[k] == nums[lastk]){continue;}
                    else{lastk = k;}
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum==0){ result.push_back( vector<int>{ nums[i], nums[j], nums[k] } ); }
                    else if(sum>0) {continue;}
                    else {break;}
                }
            }
        }
        return result;
    }
};


// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         for (int i = 0; i < nums.size(); i++) {
//             // if `nums[i]` is positive, there is no need to iterate
//             if (nums[i] > 0)
//                 break;
            
//             int target = -nums[i];
//             int front = i+1, back = nums.size()-1;
            
//             // find solution starting from `nums[i]`
//             while (front < back) {
//                 int sum = nums[front] + nums[back];
//                 if (sum < target)
//                     front++;
//                 else if (sum > target)
//                     back--;
//                 else {
//                     // the whole sum is 0
//                     vector<int> triplet{nums[i], nums[front], nums[back]};
//                     ans.push_back(triplet);

//                     // skip duplicate of number 2 and number 3
//                     while (front < back && nums[front] == triplet[1])
//                         front++;
//                     while (front < back && nums[back] == triplet[2])
//                         back--;
//                 }
//             }
//             // skip duplicate of number 1
//             while (i < nums.size() && nums[i+1] == nums[i])
//                 i++;
//         }
//         return ans;
//     }
// };