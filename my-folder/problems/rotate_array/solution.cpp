class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for(;k>0;k--){
            nums.insert(nums.begin(),nums[nums.size()-1]);
            nums.pop_back();
        }
    }
};