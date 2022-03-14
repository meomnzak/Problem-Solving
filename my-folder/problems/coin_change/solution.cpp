class Solution {
public:
    const static int N = 1e4+6; 
    int meme[13][N];
    int solve(int idx, int have, vector<int> &coins){
        if(have==0) return 0;
        if(idx==coins.size()){
            return 1e9;
        }
        
        int &ret = meme[idx][have];
        if(~ret) return ret;
        ret = 1e9;
        ret = min(ret,solve(idx+1,have,coins));
        if(have-coins[idx]>=0){
            ret = min(ret,1+solve(idx,have-coins[idx],coins));
        }
        return ret;
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(meme,-1,sizeof(meme));
        int val = solve(0,amount,coins);
        return  val == 1e9 ? -1 : val;
    }
};