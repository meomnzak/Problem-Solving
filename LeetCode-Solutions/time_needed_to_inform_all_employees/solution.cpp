class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i = 0 ; i<manager.size() ; i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        int maxi = 0;
        queue<pair<int,int>> q;
        q.push({headID,0});
        while(!q.empty()){
            int u = q.front().first;
            int val = q.front().second;
            maxi = max(maxi,val);
            q.pop();
            for(auto v: adj[u]){
                q.push({v,val+informTime[u]});
            }
        }
        return maxi;
    }
};