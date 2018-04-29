class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string maxS, curS;
        for(float i=0; i<n; i+=0.5){
            int left = ceil(i-1), right = floor(i+1);
            // cout<<left<<right<<endl;
            while( left >=0 && right<n ){
                // cout<<s[left]<<s[right]<<endl;
                if( s[left] != s[right] ){
                    break;
                }
                left--;
                right++;
            }
            curS = s.substr(left+1, right-left-1);
            // cout<<curS<<endl;
            // cout<<maxS<<endl;
            
            if(maxS.size() < curS.size()){
                maxS = curS;
            }
        }
        return maxS;
    }
};