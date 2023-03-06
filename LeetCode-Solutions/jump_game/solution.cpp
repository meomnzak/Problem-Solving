class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximumJump = 1;
        for(int i = 0 ; i<nums.size() ; i++){
            maximumJump = max(maximumJump-1,nums[i]);
            if(nums[i]==0 && maximumJump==0 && i!=nums.size()-1){
                return false;
            }
        }
        return true;
    }
};