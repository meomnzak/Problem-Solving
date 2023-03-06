class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(),nums.end(),target);
        auto it2 = upper_bound(nums.begin(),nums.end(),target);
        if(it1==nums.end() || *it1!=target){
            return {-1,-1};
        }else{
            int one = it1-nums.begin();
            int two = (--it2)-nums.begin();
            return {one,two};
        }
    }
};