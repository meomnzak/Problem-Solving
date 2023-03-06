class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> vec;
        bool flag = false;
        int i;
        for(i = 0 ; i<intervals.size() ; i++){
            if(intervals[i][0]==newInterval[0]){
                flag = true;
                vec.push_back({intervals[i][0],max(intervals[i][1],newInterval[1])});
                break;
            }else{
                vec.push_back(intervals[i]);
            }
        }
        for(;i<intervals.size() ; i++){
            if(vec.back()[1]>=intervals[i][0]){
                vec.back() = {vec.back()[0],max(vec.back()[1],intervals[i][1])};   
            }else{
                vec.push_back(intervals[i]);
            }
        }
        
        if(flag) return vec;
        vec.clear();
        flag = false;
        if(intervals.size()==0 || newInterval[0]<intervals[0][0]){
            vec.push_back(newInterval);
            flag = true;
        }

        if(flag){
            for(int i = 0 ;i<intervals.size() ; i++){
                if(vec.back()[1]>=intervals[i][0]){
                    vec.back() = {vec.back()[0],max(vec.back()[1],intervals[i][1])};
                    flag = true;
                }else{
                    vec.push_back(intervals[i]);
                }
            }

           return vec;
            
        }
        
        vec.clear();
        flag = false;
        if(newInterval[0]>intervals.back()[0]){
            vec = intervals;
            flag = true;
            vec.push_back(newInterval);
            if(vec[vec.size()-2][1]>=vec.back()[0]){
                vec[vec.size()-2]  = {vec[vec.size()-2][0],max(vec[vec.size()-2][1],vec.back()[1])};
                vec.pop_back();
            }
            return vec;
        }

        
        if(flag) return vec;
        vec.clear();
        
        flag = false;
        i = 0;
        for(i = 0 ; i<intervals.size()-1 ; i++){
            vec.push_back(intervals[i]);
            if(newInterval[0]>intervals[i][0] && newInterval[0]<intervals[i+1][0]){
                flag = true; 
                vec.push_back(newInterval);
                break;
            }
        }
        
        if(vec[vec.size()-2][1]>=vec.back()[0]){
            vec[vec.size()-2]  = {vec[vec.size()-2][0],max(vec[vec.size()-2][1],vec.back()[1])};
            vec.pop_back();
        }

        i++;
        for(;i<intervals.size() ; i++){
            if(vec.back()[1]>=intervals[i][0]){
                vec.back() = {vec.back()[0],max(vec.back()[1],intervals[i][1])};   
            }else{
                vec.push_back(intervals[i]);
            }
        }
        
        return vec;
    }
};