class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int curMax = 0;
        int bestMax = -1e9;
        int bestMin = 1e9;
        int curMin = 0;
        int total = 0;
        
        for(int i = 0 ; i<n ; i++){ 
            curMin = min(curMin+nums[i],nums[i]);
            bestMin = min(bestMin,curMin);
            curMax = max(curMax+nums[i],nums[i]);
            bestMax = max(bestMax,curMax);
            total+=nums[i];
        }
        if(bestMax<0) return bestMax;
        return max(bestMax,total-bestMin);
     
    }
};