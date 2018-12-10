// 283. Move Zeroes.cpp

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count_0 = 0;
        vector<int> temp1;
        while(nums.begin()!=nums.end()){
            int curNum = nums.back();
            nums.pop_back();
            if (curNum != 0)
                temp1.push_back(curNum);
            else
                count_0++;
        }
        while(temp1.begin()!=temp1.end()){
            nums.push_back(temp1.back());
            temp1.pop_back();
        }
        for(int i=0; i<count_0; i++){
            nums.push_back(0);
        }
    }
};