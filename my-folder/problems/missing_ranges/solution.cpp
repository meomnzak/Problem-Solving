class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> vec;
        nums.insert(nums.begin(),lower-1);
        nums.push_back(upper+1);
        for(int i = 0 ; i<nums.size()-1 ; i++){
            if(nums[i+1]-nums[i]!=1){
                string s = to_string(nums[i]+1);
                string t = to_string(nums[i+1]-1);
                if(s==t){
                    vec.push_back(s);
                }else{
                    vec.push_back(s+"->"+t);
                }
            }
        }
        return vec;
    }
};