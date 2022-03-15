class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> vec;
    int idx = 0;
    RandomizedSet() {
        mp.clear();
        vec.clear();
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            mp[val] = idx++;
            vec.push_back(val);
            return 1;
        }else{
            return 0;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return 0;
        }else{
            int cur = mp[val];
            mp[vec.back()] = cur;
            swap(vec[cur],vec.back());
            vec.pop_back();
            mp.erase(val);
            idx--;
            return 1;
        }
    }
    
    int getRandom() {
        int idx = rand()%vec.size();
        return vec[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */