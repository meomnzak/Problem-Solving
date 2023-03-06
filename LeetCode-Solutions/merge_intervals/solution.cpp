class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> cur = intervals[0];
        int i = 1;
        int n = intervals.size();
        if(n==1) return intervals;
        while(i<n){
            while(i<n && cur[1]>=intervals[i][0]){
                cur[1] = max(cur[1],intervals[i][1]);
                i++;
            }
            ans.push_back(cur);
            if(i<n){
                cur = intervals[i];
            }
        }
        return ans;
    }
};