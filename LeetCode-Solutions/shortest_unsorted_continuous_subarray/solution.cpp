class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(),vec.end());
        int n = vec.size();
        int st = 1;
        int en = 0;
        for(int i = 0 ; i<n ; i++){
            if(vec[i]!=nums[i]){
                st = i;
                break;
            } 
        }
        for(int i = n-1 ; i>=0 ; i --){
            if(vec[i]!=nums[i]){
                en = i;
                break;
            }
        }
        return en-st+1;
    }
};