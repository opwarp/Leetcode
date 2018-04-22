
// class Solution {
// public:
    
//     vector<string> res;
    
//     void genPT(string comb, string add, int m, int r){
//         // cout<< m << " "<<r<<" "<<(  m<=comb.length() ? m-1:comb.length()+1 )<<endl;
    
        
//         if( r<0 || r>(m<=comb.length() ? m-1:comb.length()+1) ){
//             return;
//         }else{
//             comb = comb + add;
//             // cout<< comb <<endl;
//             if( m<2 ){
                
//                 if(r==0){
//                     res.push_back(comb);
//                 }
//                 return;
//             }else{
//                 genPT(comb, "(", m-1, r+1);
//                 genPT(comb, ")", m-1, r-1);
//                 return;
//             }
//         }
        
//     }
    
//     vector<string> generateParenthesis(int n) {
        
//         string s;
//         genPT(s, "(", n*2, 1);
//         return res;
//     }
// };
class Solution {
public:
    
    vector<string> res;
    
    void addPT(string sPT, string PT, int left, int right){
        sPT += PT;
        if(left==0&&right==0){
            res.push_back(sPT);
            return;
        }
        if(left>0) {
            addPT(sPT, "(", left-1, right);
        }
        if(right>left){
            addPT(sPT, ")", left, right-1);
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        string s;
        addPT(s, "(", n-1, n);
        return res;
        
    }
};