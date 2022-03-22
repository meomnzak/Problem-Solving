class MovingAverage {
public:
    int n;
    int tot;
    queue<int> q;
    MovingAverage(int size) {
        n = size;
        tot = 0;
    }
    
    double next(int val) {
        q.push(val);
        if(q.size()>n){
            tot-=q.front();
            q.pop();
        }
        tot+=val;
        double res = (tot*1.0)/q.size();
        return res;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */