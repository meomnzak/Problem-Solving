class Solution {
public:
    

    int maxSubArray(vector<int>& nums) {
        int best = -1e9;
        int cur = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            cur = max(cur+nums[i],nums[i]);
            best = max(best,cur);
        }
        return best;
    }
};