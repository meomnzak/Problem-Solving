class Solution {
public:
    int shortestWay(string source, string target) {
        int idx = 0;
        int cnt = 0;
        int warning = 0;
        for(int i = 0 ; i<target.size();){
            bool flag = false;
            for(; idx<source.size() ; idx++){
                if(source[idx]==target[i]){
                    flag = true;
                    idx++;
                    break;
                }
            }
            if(flag){
                i++;
                warning = 0;
            }else{
                warning++;
            }
            if(warning == 2) return -1;
            if(idx==source.size() || i==target.size()){
                cnt++;
            }
            if(idx==source.size()) idx = 0;
        }
        return cnt;
    }
};