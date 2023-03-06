class Solution {
public:
    
    const static int N = 1e4+7;
    
    int freq[N];
    int meme[N];
    
    int solve(int idx){
        if(idx>=N) return 0;
        int &ret = meme[idx];
        if(~ret) return ret;
        ret = -1e9;
        ret = max(ret,solve(idx+1));
        ret = max(ret,solve(idx+2)+(idx*freq[idx]));
        return ret;
    }
    
    int deleteAndEarn(vector<int>& nums) {
        memset(meme,-1,sizeof(meme));
        for(int i = 0 ; i<nums.size() ; i++){
            freq[nums[i]]++;
        }
        return solve(0);
    }
    
};