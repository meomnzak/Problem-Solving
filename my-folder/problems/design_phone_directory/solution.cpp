class PhoneDirectory {
public:
    unordered_map<int,int> mp;
    vector<int> ids;
    int maxx;
    PhoneDirectory(int maxNumbers) {
        maxx = maxNumbers;
        for(int i = 0 ; i<maxx ; i++){
            ids.push_back(i);
        }
        mp.clear();
    }
    
    int get() {
        if(ids.size()==0) return -1;
        int id = ids.back();
        mp[id] = 1;
        ids.pop_back();
        return id;
    }
    
    bool check(int number) {
        return (mp.find(number)==mp.end());
    }
    
    void release(int number) {
        if(mp.find(number)!=mp.end()){
            mp.erase(number);
            ids.push_back(number);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */