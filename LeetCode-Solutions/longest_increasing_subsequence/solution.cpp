class Solution {
public:
    vector<int> nums;
    const static int N = 2508;
    int meme[N];
    
    int solve(int idx){
        
        int &ret = meme[idx];
        if(~ret) return ret;
        ret = 0;
        for(int prev = 0 ; prev<idx ; prev++){
            if(nums[prev]>=nums[idx]) continue;
            ret = max(ret,solve(prev)+1);
        }
        return ret;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(meme,-1,sizeof(meme));
        this->nums = nums;
        int ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            ans = max(ans,solve(i)+1);
        }
        return ans;
    }
};