class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i<deck.size() ; i++){
            mp[deck[i]]++;
        }
        
        int ggcd = mp.begin()->second;
        
        for(auto it = mp.begin(); it!= mp.end() ; it++){
            ggcd = __gcd(ggcd,it->second);
        }
        
        return ggcd>1;
        
    }
};