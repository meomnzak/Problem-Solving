class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int n = nums.size();
        if(n==0){
           int low = lower;
            int high = upper;
            if(low==high){
                ans.push_back(to_string(low));
            }else{
                string s = to_string(low)+"->"+to_string(high);
                ans.push_back(s);
             } 
            return ans;
        }
        if(nums.size() > 0 && lower!=nums[0]){
            int low = lower;
            int high = nums[0]-1;
            if(low==high){
                ans.push_back(to_string(low));
            }else{
                string s = to_string(low)+"->"+to_string(high);
                ans.push_back(s);
             }
        }
        for(int i = 0 ; i<n-1 ; i++){
            if(nums[i]+1 != nums[i+1]){
                int low = nums[i]+1;
                int high = nums[i+1]-1;
                if(low==high){
                    ans.push_back(to_string(low));
                }else{
                    string s = to_string(low)+"->"+to_string(high);
                    ans.push_back(s);
                }
            }
        }
        
        if(nums.size() > 0 && upper!=nums[n-1]){
            int low = nums[n-1]+1;
            int high = upper;
            if(low==high){
                ans.push_back(to_string(low));
            }else{
                string s = to_string(low)+"->"+to_string(high);
                ans.push_back(s);
             }
        }
        return ans;
    }
};