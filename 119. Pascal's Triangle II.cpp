class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            return vector<int> {1};
        }
        if(rowIndex == 1){
            return vector<int> {1,1};
        }
        vector<int> prev = getRow(rowIndex-1);
        vector<int> curr;
        int n = prev.size();
        curr.push_back(1);
        for(int i=1; i<n; i++){
            curr.push_back(prev[i]+prev[i-1]);
        }
        curr.push_back(1);
        return curr;
    }
};