class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> result;
        int index = 0;
        for(auto& str:strs){ //=python: for it in strs:
            auto str0 = str;
            sort(str.begin(), str.end()); //sort usage 
            // cout<<str<<endl;
            if(map.find(str) == map.end()){
                map[str] = index;
                result.push_back(vector<string>()); //push empty vector
                result[index].push_back(str0);
                index++;
            }else{
                result[map[str]].push_back(str0); //map[str] refer to index, here means result[index number]
                
            }
        }
        return result;
    }
};