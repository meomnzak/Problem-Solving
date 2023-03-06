class Solution {
public:
    int reverse(int x) {
        string mini = to_string(INT_MIN);
        string maxi = to_string(INT_MAX);
        string s = to_string(x);
        while(s.size()>1 && s.back()=='0'){
            s.pop_back();
        }
        if(x<0){
            ::reverse(s.begin()+1,s.end());
        }else{
            ::reverse(s.begin(),s.end());
        }
        if(x<0){
            if(s.size()==mini.size() && s>mini){
                return 0;
            }else{
                int num = stoi(s);
                return num;
            }
        }else{
            if(s.size()==maxi.size() && s>maxi){
                return 0;
            }else{
                int num = stoi(s);
                return num;
            }
        }
    }
};