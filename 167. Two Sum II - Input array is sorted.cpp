class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j=n-1;
        int res;
        while(i !=j ){
            res = numbers[i] + numbers[j];
            if(res > target) j--;
            else if (res < target) i++;
            else return (vector <int> {i+1, j+1});
            
        }
        
    }
};