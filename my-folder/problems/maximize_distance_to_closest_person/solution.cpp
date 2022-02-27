class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> ones;
        for(int i = 0 ; i<seats.size() ; i++){
            if(seats[i]==1){
                ones.push_back(i);
            }
        }
        int maxi = -1;
        for(int i = 0 ; i<seats.size() ; i++){
            if(seats[i]==0){
                auto before = upper_bound(ones.begin(),ones.end(),i);
                auto after = upper_bound(ones.begin(),ones.end(),i);
                int dis;
                if(before==ones.begin()){
                    dis = abs((*after)-i);
                }else if(after==ones.end()){
                    --before;
                    dis = abs((*before)-i);
                }else{
                    --before;
                    dis = min(abs((*after)-i),abs((*before)-i));
                }
                maxi = max(maxi,dis);
            }
        }
        return maxi;
        
    }
};