class Solution {
public:
    string nextClosestTime(string time) {
       set<int> st = {time[0]-'0',time[1]-'0',time[3]-'0',time[4]-'0'};
        bool flag = false;
       for(int i = time.size()-1 ; i>=0 ; i--){
           if(time[i]==':') continue;
           int cur= time[i]-'0';
           for(auto elem: st){
               if(elem>cur){
                   if((i==4) || (i==3 && elem<=5) || (i==0 && elem<=2) || (i==1 && ((time[0]-'0')<=1||elem<=3))) {
                       time[i] = elem+'0';
                       for(int j = i+1 ; j<time.size() ; j++){
                           if(time[j]==':') continue;
                           time[j] = *(st.begin())+'0';
                       }
                       flag = true;
                       goto go;
                   }
               }
           }
       } 
        if(!flag){
            for(int j = 0 ; j<time.size() ; j++){
                if(time[j]==':') continue;
                time[j] = (*st.begin())+'0';
            }   
             
        }
        go :{
            return time;        
        };
       
    }
};