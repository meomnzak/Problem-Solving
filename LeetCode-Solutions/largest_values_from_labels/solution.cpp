class Solution {
public:
    
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>> vec;
        map<int,int> mp;
        int n = values.size();
        for(int i = 0 ; i<n ; i++){
            vec.push_back({values[i],labels[i]});
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        int sum = 0;
        int cnt = 0;
        for(int i = 0 ; i<vec.size() ; i++){
            if(mp[vec[i].second]<useLimit){
                sum+=vec[i].first;
                cnt++;
                mp[vec[i].second]++;
            }
            if(cnt==numWanted) break;
        }
        return sum;
        
    }
};