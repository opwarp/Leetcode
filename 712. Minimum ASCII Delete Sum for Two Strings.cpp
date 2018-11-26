// 712. Minimum ASCII Delete Sum for Two Strings.cpp
class Solution {
public:
    int dpFind(const string &s1, int n1,const string &s2, int n2, vector<vector<int>> & cache){
        if(cache[n1][n2] != -1)
            return cache[n1][n2];
        int result = 0;
        if(n1>=s1.size() && n2>=s2.size()){
            result = 0;
        }else if(n1 >= s1.size()){
            result = s2[n2] + dpFind(s1,n1,s2,n2+1,cache);
        }else if(n2 >= s2.size()){
            result = s1[n1] + dpFind(s1,n1+1,s2,n2,cache);
        }else{
            if(s1[n1] != s2[n2]){
                result = min( s1[n1] + dpFind(s1,n1+1,s2,n2,cache), s2[n2] + dpFind(s1,n1,s2,n2+1,cache) );
            }else{
                result = dpFind(s1,n1+1,s2,n2+1,cache);
            }
        }
        cache[n1][n2] = result;
        return result;
        
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector <int>> cache(s1.size()+1, vector<int> (s2.size()+1, -1));
        return dpFind(s1,0,s2,0,cache);
    }
};