class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vec(26,0);
        for(int i = 0 ; i<tasks.size() ; i++){
            vec[tasks[i]-'A']++;
        }
        sort(vec.begin(),vec.end(),greater<int>());
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        int id = 1;
        for(int i = 0 ; i<vec.size() ; i++){
            if(vec[i]==0) continue;
            q.push({id++,vec[i]});
        }
        
        int tim = 0;
        while(!q.empty()){
            tim++;
            int curTime = q.top().first;
            int have = q.top().second;
            q.pop();
            if(curTime>tim) tim = curTime;
            have--;
            if(have>0){
                q.push({curTime+n+1,have});
            }
        }
        return tim;
        
    }
};