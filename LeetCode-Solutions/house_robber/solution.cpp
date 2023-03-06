class Solution {
public:
    const static int N = 107;
    int meme[N];
    
    int solve(int idx, vector<int> &nums){
        if(idx>=nums.size()) return 0;
        int &ret = meme[idx];
        if(~ret) return ret;
        ret = 0;
        ret = max(solve(idx+1,nums),solve(idx+2,nums)+nums[idx]);
        return ret;
    }
    
    int rob(vector<int>& nums) {
        memset(meme,-1,sizeof(meme));
        return solve(0,nums);
    }
};