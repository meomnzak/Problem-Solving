class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> vec;
        for(int i = 0 ; i<wage.size() ; i++){
            vec.push_back({(wage[i]*1.0)/quality[i],quality[i]});
        }
        sort(vec.begin(),vec.end());
        priority_queue<int> q;
        int qualitySum = 0;
        double ans = 1e9;
        for(int i = 0 ; i<vec.size() ; i++){
            q.push(vec[i].second);
            qualitySum+=vec[i].second;
            if(q.size()>k){
                qualitySum-=q.top();
                q.pop();
            }
            if(q.size()==k){
                ans = min(ans,vec[i].first*qualitySum);
            }
        }
        return ans;
        
    }

    
};