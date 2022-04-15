class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int one = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int two = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(one==nums.size() || nums[one]!=target) return false;
        return (two-one)>nums.size()/2;
    }
};