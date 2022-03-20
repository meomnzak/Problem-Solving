class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        
        int i = 0;
        map<int,int> mp;
        int maxi = 0;
        for(int j = 0 ; j<n ; j++){
            mp[nums[j]]++;
            auto smallest = mp.begin();
            auto largest = mp.rbegin();
            while((largest->first-smallest->first)>limit){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                smallest = mp.begin();
                largest = mp.rbegin();
                i++;
            }
            maxi = max(maxi,j-i+1);
        }
        
        return maxi;
    }
};