class Solution {
public:
    
    const static int N = 1e5+7;
    
    int meme[N][3];
    
    int solve(int idx, bool can,vector<int> &nums){
        if(idx==nums.size()){
            return 0;
        }
        int &ret = meme[idx][can];
        if(~ret) return ret;
        ret = 0;
        ret = solve(idx+1,0,nums);
        if(can){
            ret = max({ret,nums[idx]+solve(idx+1,1,nums)});
        }
        return ret;
    }
    
    int maxSubArray(vector<int>& nums) {
        memset(meme,-1,sizeof(meme));
        int ans = -1e9;
        bool pos = false;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]>=0) pos = true;
            ans = max(ans,solve(i,1,nums));
        }
        
        if(!pos){
            ans = *max_element(nums.begin(),nums.end());
        }
        
        
        return ans;
    }
};