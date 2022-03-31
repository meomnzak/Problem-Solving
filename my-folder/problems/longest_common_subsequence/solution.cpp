class Solution {
public:
    const static int N = 1e3+6;
    
    int meme[N][N];
    
    int solve(int n, int m,string &text1, string &text2){
        if(n==text1.size() || m==text2.size()) return 0;
        int &ret = meme[n][m];
        if(~ret) return ret;
        ret = -1e9;
        if(text1[n]==text2[m]){
            ret = max(ret,solve(n+1,m+1,text1,text2)+1);
        }else{
            ret = max(ret,solve(n,m+1,text1,text2));
            ret = max(ret,solve(n+1,m,text1,text2));
        }
        return ret;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(meme,-1,sizeof(meme));
        return solve(0,0,text1,text2);
    }
};