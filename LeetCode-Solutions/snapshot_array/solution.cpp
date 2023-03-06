class SnapshotArray {
public:
    map<pair<int,int>,int> mp;
    vector<vector<int>> indices;
    int snapId;
    int n;
    SnapshotArray(int length) {
        n = length;
        snapId = 0;
        mp.clear();
        indices = vector<vector<int>>(n);
        for(int i = 0 ; i<n ; i++){
            mp[{i,-1}] = 0;
            indices[i].push_back(-1);
        }
    }
    
    void set(int index, int val) {
        mp[{index,snapId}] = val;
        indices[index].push_back(snapId);
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        vector<int> cur = indices[index];
        int idx = upper_bound(cur.begin(),cur.end(),snap_id)-cur.begin();
        int id = cur[idx-1];
        return mp[{index,id}];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */