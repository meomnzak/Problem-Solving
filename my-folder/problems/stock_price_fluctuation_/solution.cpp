class StockPrice {
public:
    map<int,int> mp;
    priority_queue<pair<int,int>> maxi;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mini;
    int cur;
    StockPrice() {
        mp.clear();
        while(maxi.size()>0) maxi.pop();
        while(mini.size()>0) mini.pop();
        cur = 0;
    }
    
    void update(int timestamp, int price) {
        cur = max(cur,timestamp);
        mp[timestamp] = price;
        maxi.push({price,timestamp});
        mini.push({price,timestamp});
    }
    
    int current() {
        return mp[cur];
    }
    
    int maximum() {
        while(mp[maxi.top().second]!=maxi.top().first){
            maxi.pop();
        }
        return maxi.top().first;
    }
    
    int minimum() {
        while(mp[mini.top().second]!=mini.top().first){
            mini.pop();
        }
        return mini.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */