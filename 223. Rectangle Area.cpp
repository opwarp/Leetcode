// 223. Rectangle Area.cpp

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int unionArea = (C-A) * (D-B) + (G-E) * (H-F);
        int interArea = 0;
        int result = 0;
        if(E>=C || H<=B || G<=A || F>=D){
            result = unionArea;
        }else{
            int WW = min(C, G) - max(A, E);
            int HH = min(D, H) - max(B, F);
            interArea = WW * HH;
            result = unionArea - interArea;
        }
        // cout<<"unionArea "<<unionArea<<" interArea "<<interArea<<endl;
        return result;
        
    }
};