class Solution {
public:
    string multiply(string num1, string num2) {
        deque<int> number1;
        deque<int> number2;
        for(int i = 0 ; i<num1.size() ; i++){
            number1.push_back(num1[i]-'0');
        }
        for(int i = 0 ; i<num2.size() ; i++){
            number2.push_back(num2[i]-'0');
        }
        
        vector<deque<int>> vec;
        int cnt = 0;
        for(int i = number1.size()-1 ; i>=0 ; i--){
            
            deque<int> curRes;
            int extra = 0;
            for(int j = number2.size()-1 ; j>= 0 ; j--){
                int res = number2[j]*number1[i];
                res+=extra;
                extra = res/10;
                res%=10;
                curRes.push_front(res);
            }
            curRes.push_front(extra);
            for(int k = 0 ; k<cnt ; k++){
                curRes.push_back(0);
            }
            while(curRes.size()<411){
                curRes.push_front(0);
            }
            vec.push_back(curRes);
            cnt++;
        }
        
        deque<int> finale;
        int extra = 0;
        for(int i = 410; i>=0 ; i--){
            int summ = 0;
            for(int j = 0 ; j<vec.size() ; j++){
                summ+=vec[j][i];
            }
            summ+=extra;
            extra = summ/10;
            summ%=10;
            finale.push_front(summ);
        }
        finale.push_front(extra);
        while(finale.size()>1 && finale.front()==0){
            finale.pop_front();
        }
       
        string go = "";
        for(int i = 0 ; i<finale.size() ; i++){
            go+=finale[i]+'0';
        }
        return go;
    }
};