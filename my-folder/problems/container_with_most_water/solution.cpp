class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int,int>> vec;
        int n =height.size();
        for(int i = 0 ; i<n ; i++){
            vec.push_back({height[i],i});
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        int mini = vec[0].second;
        int maxi = vec[0].second;
        int ans = -1;
        for(int i = 1 ; i<vec.size(); i++){
            int one = abs(vec[i].second-mini)*vec[i].first;
            int two = abs(vec[i].second-maxi)*vec[i].first;
            ans = max({ans,one,two});
            mini = min(mini,vec[i].second);
            maxi = max(maxi,vec[i].second);
        }
        return ans;
    }
};