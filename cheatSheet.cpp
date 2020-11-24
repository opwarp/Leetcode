int curNum = nums.back(); //get last item
nums.pop_back(); //remove last item
res.push_back( vector <int> ({curNum}) ); //initial array
preCodes.push_back(preCodes[i]|1<<(count));
108
TreeNode* root = new TreeNode(*it);
vector<int>::iterator bgn,
int rsize = end-it-1;
137
n >>= 1;
46
res[j].insert(res[j].end(), curNum);
155
minstack.push_back(x);
int minTop = minstack.back();
160
int res = INT_MIN;
227
#include <string>
#include <sstream> 
int(s[i]-'0');
vector<char>::iterator iter2 = s.begin()+i;
s.erase(iter2);
stringstream ss("+"+s);
while(ss>>op>>num)
232
#include <deque>
deque <int> myQueue;
int pop =  myQueue.front();
myQueue.pop_front();
241
stoi(input)
atoi(input.c_str())
260
#include <iostream>
#include <map>
#include <unordered_set>
map<string, int>::iterator it;
for (auto const& x : symbolTable)
{
    std::cout << x.first  // string (key)
              << ':' 
              << x.second // string's value 
              << std::endl ;
}
hash.find(i)==hash.end()
hash.erase(i);
//init vector with picifitc numbers
return vector<int> {*hash.begin(), *(++hash.begin())};

973
#include <map>
multimap<int, int> m;
