class Solution {
public:
    
    const static int N = 1e5+1;
    
    int n;
    
    int meme[N][2][3];
    
    int MOD = 1e9+7;
    
    int solve(int idx, int As, int Ls){
        if(idx==n) return 1;
        int &ret = meme[idx][As][Ls];
        if(~ret) return ret;
        ret = 0;
        if(As<1){
            ret = ((ret%MOD) + (solve(idx+1,As+1,0)%MOD))%MOD;
        }
        ret = ((ret%MOD) + (solve(idx+1,As,0)%MOD))%MOD;
        if(Ls<2){
            ret = ((ret%MOD) + (solve(idx+1,As,Ls+1)%MOD))%MOD;
        }
        return ret;
    }
    
    int checkRecord(int n) {
        this->n = n;
        memset(meme,-1,sizeof(meme));
        return solve(0,0,0);
    }
};