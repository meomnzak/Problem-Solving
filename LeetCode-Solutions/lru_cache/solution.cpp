class LRUCache {
public:
    int sz;
    int tim;
    int low;
    unordered_map<int,int> logs;
    unordered_map<int,pair<int,int>> cache;
    LRUCache(int capacity) {
        sz = capacity;
        tim = 0;
        low = 0;
        logs.clear();
        cache.clear();
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }else{
            logs[tim] = key; 
            cache[key].second = tim++;
            return cache[key].first;
        }
    }
    
    void put(int key, int value) {
        logs[tim] = key;
        cache[key] = {value,tim++};
        while(cache.size()>sz){
            int lowKey = logs[low];
            if(cache[lowKey].second==low){
                cache.erase(lowKey);
                // logs.erase(low);
            }
            low++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */