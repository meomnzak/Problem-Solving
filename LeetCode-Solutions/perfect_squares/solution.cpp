class Solution {
public:
    const static int N = 1e4+7;
    int meme[N];
    int solve(int rem){
        if(rem<0) return 1e9;
        if(rem==0) return 0;
        int &ret = meme[rem];
        if(~ret) return ret;
        ret = 1e9;
        for(int i = 0 ; i<100 ; i++){
            ret = min(ret,solve(rem-(i*i))+1);
        }
        return ret;
    }
    
    int numSquares(int n) {
        memset(meme,-1,sizeof(meme));
        return solve(n);
        
    }
};