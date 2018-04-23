// class Solution {
// public:
//     int myAtoi(string str) {
//         char num_str[str.size()+1];
//         strcpy(num_str, str.c_str());
//         int n = sizeof(num_str);
//         bool gotC = false;
//         bool gotN = false;
//         bool gotS = false;
//         int num = 0;
//         int symbol = 1;
//         int max = INT_MAX / 10;
//         for(int i=0; i<n; i++){
//             if(!gotC && num_str[i]==' '){
//                 continue;
//             }else{
//                 gotC = true;
//             }
//             if(gotC){
//                 if ( !gotN && (num_str[i] == '-' || num_str[i] == '+') ){
//                     gotN = true;
//                     if(num_str[i] == '-') {
//                         symbol = -1;
//                     }
                    
//                 }else if(num_str[i] >= '0' && num_str[i] <= '9'){
//                     gotN = true;
//                     if(num > max || ( num == max && (num_str[i] - '0') >= 8) ){
//                         cout << "overflow" <<endl;
//                         if(symbol>0){num = INT_MAX;}
//                         else{num = INT_MIN;}
//                         break;
//                     }else{
//                         num = num * 10 + (num_str[i] - '0');
//                     }
//                 }else{
//                     break;
//                 }
                
//             }
//         }
//         num = num * symbol;
//         return num;
//     }
// };

class Solution {
public:
    int myAtoi(string str) {

        int max = INT_MAX / 10;
        int i=0;
        int symbol = 1;
        int num = 0;
        while(str[i] == ' '){i++;}
        //move forward when no ' '
        if((str[i] == '-' || str[i] == '+')){
            if(str[i] == '-') {symbol = -1;}
            i++;
        }//if have symbol
        //i move forward
        while(str[i] >= '0' && str[i] <= '9'){
            if(num > max || ( num == max && (str[i] - '0') >= 8) ){
                cout << "overflow" <<endl;
                if(symbol>0){num = INT_MAX;}
                else{num = INT_MIN;}
                break;
            }else{
                num = num * 10 + (str[i] - '0');
            }
            i++;
        }
        num = num * symbol;
        return num;
    }
};