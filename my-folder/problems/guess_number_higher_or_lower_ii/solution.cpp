class Solution {
public:
    
    const static int N = 202;
    int meme[N][N];
    int solve(int s, int e){
        if(s>=e) return 0;
        int &ret = meme[s][e];
        if(~ret) return ret;
        ret = INT_MAX;
        for(int i = s ; i<=e ; i++){
            int temp = i+max(solve(s,i-1),solve(i+1,e));
            ret = min(ret,temp);
        }
        return ret;
    }
    
    int getMoneyAmount(int n) {
        memset(meme,-1,sizeof(meme));
        return solve(1,n);
    }
};