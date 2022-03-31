class Solution {
public:
    const static int N = 1004;
    int meme[N];
    
    int solve(int idx, vector<int> & cost){
        if(idx>cost.size()) return 1e9;
        if(idx==cost.size()) return 0;
        int &ret = meme[idx];
        if(~ret) return ret;
        ret = 1e9;
        ret = min(solve(idx+1,cost)+cost[idx],solve(idx+2,cost)+cost[idx]);
        return ret;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(meme,-1,sizeof(meme));
        return min(solve(0,cost),solve(1,cost));
    }
};