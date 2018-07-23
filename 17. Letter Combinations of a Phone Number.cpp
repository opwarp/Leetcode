class Solution {
private:
  string record[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  
  vector<string> result;
  
  void doStore(const string &digits, int index, const string &s) {
    if (index == digits.size()) {
      result.push_back(s);
      return;
    }
    char c = digits[index++];           // '2'~'9'
    string letters = record[c - '0']; // eg: "abc"/"def"/...
    for ( int i = 0; i < letters.length(); ++i)
      doStore(digits, index, s + letters[i]);
  }
  
public:  
  vector<string> letterCombinations(string digits) {
    if(digits.empty()) return vector<string>();
    doStore(digits, 0, "");
    return result;
  }
};