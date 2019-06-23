class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest_sum=nums[0];
        int sum =0;
        for(int i=0 ; i<nums.size() ; i++){
            for(int j = i ; j<nums.size() ; j++){
                sum+= nums[j];
                if(sum>largest_sum){
                    largest_sum=sum;
                }
            }
            sum = 0;
        }
        return largest_sum;
    }
    
};