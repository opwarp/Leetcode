// 241. Different Ways to Add Parentheses.cpp
class Solution {
public: 
    vector<int> diffWaysToCompute(string input) {
        auto ind = input.find_first_of("+-*", 0);
        if(ind == string::npos)
            return {stoi(input)};
        vector <int> result;
        while(ind != string::npos){
            vector <int> left = diffWaysToCompute(input.substr(0, ind)), 
            right = diffWaysToCompute(input.substr(ind+1, input.size()-1));
            for (auto i:left){
                for(auto j:right){
                     switch(input[ind]){
                        case '*': result.push_back(i*j);break;
                        case '+': result.push_back(i+j);break;
                        case '-': result.push_back(i-j);break;
                        default : break;
                     }
                }
            }
            ind = input.find_first_of("+-*", ind + 1);
        }
        return result;
    }
};