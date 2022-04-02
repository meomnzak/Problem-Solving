class Solution {
public:
    int n,k,target;
    const static int N = 33;
    const static int M = 1003;
    int meme[N][M];
    const int MOD = 1e9+7;
    
    int solve(int idx, int have){
        if(have>target) return 0;
        if(idx==n) return (have==target);
        int &ret = meme[idx][have];
        if(~ret) return ret;
        ret = 0;
        for(int i = 1 ; i<=k ; i++){
            ret = ((ret%MOD)+(solve(idx+1,have+i)%MOD))%MOD;
        }
        return ret;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(meme,-1,sizeof(meme));
        this->n = n;
        this->k = k;
        this->target = target;
        return solve(0,0);
    }
};