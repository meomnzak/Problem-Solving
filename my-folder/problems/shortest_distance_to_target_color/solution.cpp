class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> vec(3);
        for(int i = 0 ; i<n ; i++){
            vec[colors[i]-1].push_back(i);
        }
        
        vector<int> ans;
        for(int i = 0 ; i<queries.size() ; i++){
            int idx = queries[i][0];
            int target = queries[i][1];
            int low = lower_bound(vec[target-1].begin(),vec[target-1].end(),idx)-vec[target-1].begin();
            int up = upper_bound(vec[target-1].begin(),vec[target-1].end(),idx)-vec[target-1].begin();
            up--;
            if(low==vec[target-1].size()){
                low = 1e9;
            }else{
                low = vec[target-1][low];
            }
            if(up==-1){
                up = 1e9;
            }else{
                up = vec[target-1][up];
            }
            int go = 0;
            int one = abs(low-idx);
            int two = abs(up-idx);
            go = min(one,two);
            if(go>1e5) go = -1;
            ans.push_back(go);
        }
        
        return ans;
    }
};