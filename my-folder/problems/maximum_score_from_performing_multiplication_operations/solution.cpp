class Solution {
public:
    const static int M = 1e3+7;
    const static int N = 1e5+7;
    
    int meme[M][M];
    
    int solve(int totalTaken, int fromLeft, vector<int>& nums, vector<int>& multipliers){
        if(totalTaken==multipliers.size()) return 0;
        int &ret = meme[totalTaken][fromLeft];
        if(~ret) return ret;
        ret = -2e9;
        int fromRight = nums.size()-(totalTaken-fromLeft) - 1;
        ret = max(ret,solve(totalTaken+1,fromLeft+1,nums,multipliers)+(nums[fromLeft]*multipliers[totalTaken]));
        ret = max(ret,solve(totalTaken+1,fromLeft,nums,multipliers)+(nums[fromRight]*multipliers[totalTaken]));
        return ret;
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(meme,-1,sizeof(meme));
        return solve(0,0,nums,multipliers);
    }
};