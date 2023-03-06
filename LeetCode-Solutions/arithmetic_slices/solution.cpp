class Solution {
public:
    vector<int> nums;
    int n;
    const static int N = 5e3+4;
    int meme[N];
    
    int solve(int idx){
        if(idx==n-1) return 0;
        int &ret = meme[idx];
        if(~ret) return ret;
        ret = 0;
        
        if(nums[idx]-nums[idx-1] == nums[idx+1]-nums[idx]){
            ret+=solve(idx+1)+1;
        }
        
        return ret;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        memset(meme,-1,sizeof(meme));
        this->nums = nums;
        n = nums.size();
        int ans = 0;
        for(int i = 1 ; i<n-1 ; i++){
            ans+=solve(i);
        }
        return ans;
        
        
    }
};