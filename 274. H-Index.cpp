// 274. H-Index.cpp

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        for(int i=0; i<citations.size(); i++){
            for(int j=i+1; j<citations.size(); j++){
                if( citations[i] < citations[j] ){
                    int temp = citations[i];
                    citations[i] = citations[j];
                    citations[j] = temp;
                }
            }
            if( citations[i] >= i+1 ){
                ans =  i+1;
            }else{
                break;
            }
            
        }
        return ans;
    }
};
