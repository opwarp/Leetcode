// class Solution {
// public:
//     vector<vector<int>> all_subset;
//     void buildSubSet(vector<int> subset, vector<int> nums, int bgn, int n, int setSize){
//         if(setSize < 0)
//             return;
//         for(int i=bgn; i<n; i++){
            
                
//             subset.push_back(nums[i]);
//             if (setSize == 0){
//                 all_subset.push_back(subset);
//             }
//             buildSubSet(subset, nums, i+1, n, setSize-1);
//             subset.pop_back();
//         }
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> empty;
//         all_subset.push_back(empty);
//         for(int i=0; i<n; i++){
//             vector<int> subset;
//             buildSubSet(subset, nums, 0, n, i);
//         }
//         return all_subset;
        
//     }
// };

class Solution {
public:
    void genSub(vector<vector<int>> &subs, vector<int> &sub, vector<int>& nums, int bgn, int size){
        subs.push_back(sub);
        for(int i=bgn; i<size; i++){
            sub.push_back(nums[i]);
            // cout <<nums[i]<<endl;
            genSub(subs, sub, nums, i+1, size);
            sub.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subs;
        vector<int> sub;
        genSub(subs, sub, nums, 0, n);
        return subs;
    }
    
};