// 27. Remove Element.cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        auto i=nums.begin();
        while(i!=nums.end()){
            if(*i == val)
                nums.erase(i);
            else
                ++i;
            // if(i==nums.end())
            //     cout<<*i<<endl;
        }
       
        return nums.size();
    }
    
};