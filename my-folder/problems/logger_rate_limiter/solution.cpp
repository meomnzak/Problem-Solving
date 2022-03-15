class Logger {
public:
    unordered_map<string,int> mp;
    
    Logger() {
        mp.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(timestamp>=mp[message]){
            mp[message] = timestamp+10;
            return true;
        }else{
            
            return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */