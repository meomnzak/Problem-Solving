class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i<tops.size() ; i++){
            mp[tops[i]]++;
            if(tops[i]!=bottoms[i]){
                mp[bottoms[i]]++;
            }
        }
        int ans = 1e9;
        bool flag = false;
        for(int i = 1 ; i<=6 ; i++){
            if(mp[i]==tops.size()){
                flag = true;
                int up = 0;
                int down = 0;
                for(int j = 0 ; j<tops.size() ; j++){
                    if(tops[j]==i) up++;
                    if(bottoms[j]==i) down++;
                }
                ans = min(ans,min((int)tops.size()-up,(int)tops.size()-down));
            }
        }
        if(!flag) return -1;
        return ans;
    }
};