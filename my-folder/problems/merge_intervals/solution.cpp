class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i = 0 ; i<intervals.size() ; i++){
            q.push({intervals[i][0],intervals[i][1]});
        }
        vector<vector<int>> vec;
        while(!q.empty()){
            pair<int,int> cur = q.top();
            q.pop();
            if(q.size()==0){
                vec.push_back({cur.first,cur.second});
            }else{
                pair<int,int> nxt = q.top();
                q.pop();
                if(cur.first==nxt.first){
                    q.push({cur.first,nxt.second});
                }else{
                    if(cur.second>=nxt.first){
                        q.push({cur.first,max(cur.second,nxt.second)});
                    }else{
                        vec.push_back({cur.first,cur.second});
                        q.push(nxt);
                    }
                }
            }
        }
        return vec;
    }
};