class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vec;
        unordered_map<int,int> mp;
        for(int i = 0 ; i< n ; i++){
            mp[nums[i]] = i;
        }
        map<vector<int>,int> check;
        set<int> st;
        for(int i = 0 ; i<n ; i++){
            if(st.insert(nums[i]).second){
                 for(int j = i+1 ; j<n ; j++){
                int summ = nums[i]+nums[j];
                int rem = -1*summ;
                if(mp.find(rem)!=mp.end()){
                    if(mp[rem]>j){
                        vector<int> temp;
                        temp= {nums[i],nums[j],rem};
                        sort(temp.begin(),temp.end());
                        if(check.find(temp)==check.end()){
                            vec.push_back(temp);
                            check[temp] = 1;
                        }
                        
                    }
                }
            }
            }
           
        }
        
        
        return vec;
    }
};