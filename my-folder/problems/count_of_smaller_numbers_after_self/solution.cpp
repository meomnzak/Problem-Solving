class Solution {
public:
    
    struct BIT{
        vector<int> v;
        int sz;
        
        BIT(int n){
            v.resize(n);
            sz = n;
        }
        
        int get(int i){
            int ret = 0;
            for(++i ; i ; i-= i&-i)
                ret+=v[i-1];
            return ret;
        }
        
        void update(int i , int x){
            for(++i ; i<=sz ; i+= i&-i)
                v[i-1] += x;
        }
        
        
    };
    
    
    vector<int> countSmaller(vector<int>& nums) {
        unordered_map<int,int> mp;
        int id = 0;
        vector<int> vec = nums;
        sort(vec.begin(),vec.end());
        for(int i = 0 ; i<vec.size() ; i++){
            if(mp.find(vec[i])==mp.end())
                mp[vec[i]] = id++;
        }
        BIT bit(id+1);
        vector<int> sol;
        for(int i = nums.size()-1 ; i>=0 ; i--){
            sol.push_back(bit.get(mp[nums[i]]-1));
            bit.update(mp[nums[i]],1);
        }
        reverse(sol.begin(),sol.end());
        return sol;
        
    }
};