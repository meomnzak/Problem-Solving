class Solution {
public:
    // a -> 0;
    // e -> 1;
    // i -> 2;
    // o -> 3;
    // u -> 4;
    
    const static int N = 2e4+7;
    int MOD = 1e9+7;
    int n;
    int meme[N][6];
    
    int solve(int idx, int lst){
        if(idx==n) return 1;
        int &ret = meme[idx][lst];
        if(~ret) return ret;
        ret = 0;
        for(int i = 0 ; i< 5 ; i++){
            if((lst==5)||(lst==0&&i==1)||(lst==1&&(i==0||i==2))||(lst==2&&i!=2)||(lst==3&&(i==2||i==4))||(lst==4&&i==0)){
                ret = ((ret%MOD)+(solve(idx+1,i)%MOD))%MOD;
            }
        }
        return ret;
    }
    
    int countVowelPermutation(int n) {
        memset(meme,-1,sizeof(meme));
        this->n = n;
        return solve(0,5);
    }
};