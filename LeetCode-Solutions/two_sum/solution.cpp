class Solution {
public:
    vector<int> solution;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0 ; i<nums.size() ; i++){
            for(int j = i+1 ; j<nums.size() ; j++){
                if(nums[i] + nums[j] == target) {
                    
                    solution.push_back(i);
                    solution.push_back(j);

                }
            }
        }
        return solution;
    }
};