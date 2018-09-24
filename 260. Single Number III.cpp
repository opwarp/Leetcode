// 260. Single Number III.cpp

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto i:nums){
            if(hash.find(i)==hash.end()) hash.insert(i);
            else hash.erase(i);
        }
        return vector<int> {*hash.begin(), *(++hash.begin())};
    }
};