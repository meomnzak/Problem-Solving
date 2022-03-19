class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<pair<int,int>,int> mp;
        for(int i = 0 ; i<points.size() ; i++){
            mp[{points[i][0],points[i][1]}] = 1;
        }
        int ans = 1e9;
        for(int i = 0 ; i<points.size() ; i++){
            for(int j = i+1 ; j<points.size() ; j++){
                if(points[i][0]==points[j][0] || points[i][1] == points[j][1]) continue;
                pair<int,int> third = {points[i][0],points[j][1]};
                pair<int,int> fourth = {points[j][0],points[i][1]};
                if(mp.find(third)==mp.end() || mp.find(fourth)==mp.end()) continue;
                int height = abs(points[i][1]-third.second);
                int width = abs(points[i][0]-fourth.first);
                int area = width*height;
                ans = min(ans,area);
            }
        }
        if(ans==1e9) return 0;
        return ans;
        
    }
};