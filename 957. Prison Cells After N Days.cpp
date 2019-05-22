// 957. Prison Cells After N Days.cpp
class Solution {
public:
    int vec2int(vector <int> vec){
        int num = 0;
        for(auto i:vec){
            num = num<<1 | i;
        }
        return num;
    }
    vector <int> int2vec(int num){
        vector <int> vec(8, -1);
        int count = 8;
        while(--count >= 0){
            vec[count] =  num & 1;
            num  = num >> 1;
        }
        return vec;
    }
    int getNext(int input){
        vector <int> vec = int2vec(input);
        for(int i=1; i<7; i++){
            if(vec[i-1]%2 == vec[i+1]%2){
                vec[i] = vec[i]==0? 2: 1;
            }else{
                vec[i] = vec[i]==1? 3: 0;
            }
        }
        for(int i=1; i<7; i++){
            if(vec[i] == 2) vec[i] = 1;
            if(vec[i] == 3) vec[i] = 0;
        }
        vec[0] = 0;
        vec[7] = 0;
        return vec2int(vec);
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<int, int> record;
        int cur = vec2int(cells);
        int count = 0;
        while(++count <= N){
            cur = getNext(cur);
            if( record.find(cur) == record.end() ){
                record[cur] = count;
            }else{
                int idx = (N-record[cur]) % (count - record[cur]) + record[cur];
                for(auto &i:record){
                    if(i.second == idx){
                        return int2vec(i.first);
                    }
                }
                break;
            }
        }
        return int2vec(cur);
    }
};