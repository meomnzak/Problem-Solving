class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int cur = 1;
        for(int i = 0 ; i<n-1 ; i++){
            if(nums[i]<nums[i+1]){
                cur++;
            }else{
                maxi = max(maxi,cur);
                cur = 1;
            }
        }
        maxi = max(maxi,cur);
        return maxi;
    }
};