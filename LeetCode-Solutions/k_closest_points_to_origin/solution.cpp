class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>> vec;
        for(int i = 0 ; i<points.size() ; i++){
            vec.push_back({points[i][0]*points[i][0] + points[i][1] * points[i][1],i});
        }
        sort(vec.begin(),vec.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i<k ; i++){
            ans.push_back(points[vec[i].second]);
        }
        return ans;
    }
};