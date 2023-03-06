class Solution {
public:
    const static int N = 52;
    const static int K = 1e5+5;
    int n;
    int k;
    int meme[N];
    
    int solve(int i){
        if(i==1) return k;
        if(i==2) return k*k;
        int &ret = meme[i];
        if(~ret) return ret;
        ret = 0;
        ret = (k-1)*solve(i-1) + (k-1)*solve(i-2);
        return ret;
    }
    
    int numWays(int n, int k) {
        memset(meme,-1,sizeof(meme));
        this->n = n;
        this->k = k;
        return solve(n);
    }
};