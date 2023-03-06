class MyCalendarTwo {
public:
    vector<pair<int,int>> intersections;
    vector<pair<int,int>> intervals;
    MyCalendarTwo() {
        intervals.clear();
        intersections.clear();
    }
    
    bool book(int start, int end) {
        end--;
        for(int i = 0 ; i<intersections.size() ; i++){
            if( !(end<intersections[i].first || start>intersections[i].second) ) return false;
        }
        
        for(int i = 0 ; i<intervals.size() ; i++){
             if( !(end<intervals[i].first || start>intervals[i].second) ){
                 intersections.push_back({max(start,intervals[i].first),min(end,intervals[i].second)});
             }
        }
        
        intervals.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */