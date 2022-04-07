class Solution {
public:
    
    struct package{
        int dist, workId,bikeId;
        package(int d,int w,int b){
            dist = d;
            workId = w;
            bikeId = b;
        }
    };
    
    bool static mySort(package p1, package p2){
        if(p1.dist!=p2.dist) return p1.dist<p2.dist;
        if(p1.bikeId!=p2.bikeId)  return p1.bikeId<p2.bikeId; 
        return p1.workId<p2.workId;
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<package> vec;
        for(int i = 0 ; i<workers.size() ; i++){
            for(int j =0 ; j<bikes.size() ; j++){
                int d = abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                vec.push_back(package(d,i,j));
            }
        }
        vector<int> ans(workers.size());
        sort(vec.begin(),vec.end(),mySort);
        unordered_map<int,int> visWork;
        unordered_map<int,int> visBike;
        for(int i = 0 ; i<vec.size() ; i++){
            if(visWork[vec[i].workId] || visBike[vec[i].bikeId]) continue;
            ans[vec[i].workId] = vec[i].bikeId;
            visWork[vec[i].workId] = 1;
            visBike[vec[i].bikeId] = 1;
        }
        return ans;
    }
};