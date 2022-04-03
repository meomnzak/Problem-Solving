class DetectSquares {
public:
    vector<vector<int>> vec;
    map<pair<int,int>,int> mp;
    DetectSquares() {
        vec.clear();
        mp.clear();
    }
    
    void add(vector<int> point) {
        vec.push_back(point);
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int cnt = 0;
        for(int i = 0 ; i<vec.size() ; i++){
            if(vec[i][1]==point[1] && vec[i][0] != point[0]){
                int dis = vec[i][0]-point[0];
                cnt+= (mp[{vec[i][0],vec[i][1]+dis}]*mp[{point[0],point[1]+dis}]);
                cnt+= (mp[{vec[i][0],vec[i][1]-dis}]*mp[{point[0],point[1]-dis}]);
            }
        }
        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */