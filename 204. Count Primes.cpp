class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<bool> prime(n ,true);
        int np=1;
        int upper = sqrt(n);
        for(int i=3; i<n; i+=2){
            
            if(prime[i]){
                np++;
                if(i>upper)
                    continue;
                for(int j=i*i; j<n; j+=2*i){
                    prime[j] = false;
                }
            }
        }
        return np;
    }
};