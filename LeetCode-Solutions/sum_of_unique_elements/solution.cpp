class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        
        for(auto it = mp.begin() ; it!=mp.end() ; it++){
            if(it->second==1){
                sum+=it->first;
            }
        }
        return sum;
        
    }
};