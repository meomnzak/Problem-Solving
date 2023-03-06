class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        int other = -1;
        int sol = 1e9;
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = i+1 ; j<n ; j++){
                if(nums[i]<nums[j]){
                    sol = min(sol,nums[i]);
                    other = j;
                }
            }
            if(sol!=1e9){
                idx = i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
        }else{
            swap(nums[idx],nums[other]);
            sort(nums.begin()+idx+1,nums.end());
        }
       
        
        
    }
};