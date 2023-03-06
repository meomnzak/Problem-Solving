class Logger {
public:
    unordered_map<string,int> mp;
    Logger() {
        mp.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message)==mp.end()){
            mp[message] = timestamp+10;
            return true;
        }
        if(timestamp>=mp[message]){
            mp[message] = timestamp+10;
            return true;
        }
        return false;
        
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */