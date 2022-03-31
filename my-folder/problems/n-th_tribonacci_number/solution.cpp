class Solution {
public:
    const static int N = 39;
    int meme[N];
    
    int solve(int idx){
        if(idx<=0) return 0;
        if(idx==1) return 1;
        if(idx==2) return 1;
        int &ret = meme[idx];
        if(~ret) return ret;
        ret = 0;
        ret = solve(idx-1)+solve(idx-2)+solve(idx-3);
        return ret;
    }
    
    int tribonacci(int n) {
        memset(meme,-1,sizeof(meme));
        return solve(n);
    }
};