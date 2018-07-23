class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // if(numbers[j]<=target){
                    if(numbers[i]+numbers[j]==target)
                        return vector<int>{i+1,j+1};
                // }
            }
        }
    }
};