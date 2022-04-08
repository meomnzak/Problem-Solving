class Solution {
public:
    
   int target;
    
    
    
    map<pair<int,int>,int> vis;
    int bfs(){
        queue<pair<int,int>> q;
        q.push({0,1});
        int lvl = 0;
        vis[{0,1}] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> u = q.front();
                int curDist = u.first;
                int curSpeed = u.second;
                if(curDist==target) return lvl;
                q.pop();
                int newDist = curDist+curSpeed;
                int newSpeed = curSpeed*2;
                if(!vis[{newDist,newSpeed}] && abs(newDist) <= 2*target){
                    vis[{newDist,newSpeed}] = 1;
                    q.push({newDist,newSpeed});
                }
                if(curSpeed>0){
                    newSpeed = -1;
                }else{
                    newSpeed = 1;
                }
                if(!vis[{curDist,newSpeed}]){
                    vis[{curDist,newSpeed}] = 1;
                    q.push({curDist,newSpeed});
                }
            }
            lvl++;
        }
        return 0;
    }
    
    int racecar(int target) {
        this->target = target;
        return bfs();
    }
};