// class Solution {
// public:
//     bool isValid(string s) {
//         vector<char> left;
//         int balance = 0;
//         int index=0;
//         for(auto c:s){
//             if(c=='(' || c=='[' || c=='}'){
//                 left.push_back(c);
//                 balance++;
//                 index++;
//             }
//             else{
//                 balance--;
//                 if(index>0){
//                     return false;
//                 }
                
//                 char right = left[index--];
//                 cout<<right<<endl;
//                 if( ( c==')' && right!='(' )
//                    ||( c==']' && right!='[' )
//                    ||( c=='}' && right!='{' ) ){
//                     return false;
//                 }
                
//                 }
                    
//             }
            
//         }
//         if(balance<0){
//             return false;
//         }

//     }
// };

class Solution {
 public:
  bool isValid(string s) {
    stack<char> chars;
    unordered_map<char, char> map = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };

    for (char i : s) {
      if (map.find(i) != map.end()) {
        chars.push(i);
      } else if (chars.empty() || map.find(chars.top())->second != i) {
        return false;
      } else {
        chars.pop();
      }
    }

    return chars.empty();
  }
};