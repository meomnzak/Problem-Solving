class Solution {
public:
    const static int N = 5004;
    
    int meme[N][4][4][4];
    
    int n;
    
    const int MOD = 1e9+7;
    
    int solve(int idx, int l, int mid, int r){
        if(idx==n) return 1;
        int &ret = meme[idx][l][mid][r];
        if(~ret) return ret;
        ret = 0;
        for(int i = 1 ; i<=3 ; i++){
            for(int j = 1 ; j<=3 ; j++){
                for(int k = 1 ; k<=3 ; k++){
                    if(i==j) continue;
                    if(j==k) continue;
                    if(i==l || j==mid || k==r) continue;
                    ret = ((ret%MOD) + (solve(idx+1,i,j,k)%MOD))%MOD; 
                }
            }
        }
        return ret;
    }
    
    int numOfWays(int n) {
        this->n = n;
        memset(meme,-1,sizeof(meme));
        return solve(0,0,0,0);
    }
};