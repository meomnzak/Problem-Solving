#include <bits/stdc++.h>



using namespace std;
int main(){

    
    string s;
    cin>>s;
    int low = 0;
    int high = 0;
    int unknown = 0;
    int complete = 0;
    int n = s.size();
    bool flag = false;
    string ans;
    int Lbound;
    map<char,int> m;
        for(int i = 0  ; i<26 ; i++){
                m['A'+i] = 0;
        }
    while(low<n){
        
        while(true){
            if(high==n || (m[s[high]]==1&&low!=high )){
                break;
            }
            complete++;
            if(s[high]=='?'){
                unknown++;
            }else{
                m[s[high]]= 1;
            }
            if(complete==26){
                flag = true;
                break;
            }
            high++;
        }
        if(flag){
            ans = s.substr(low,26);
            Lbound=low;
            
            break;
            
        }
        complete = 0;
        low++;
        high = low;
        for(int i = 0  ; i<26 ; i++){
                m['A'+i] = 0;
        }
        
    }
    if(flag){
        for(int w = 0 ; w<s.size() ; w++){
            if(w==Lbound){
                for(int i = 0 ; i<ans.size() ; i++){
                    if(ans[i]=='?'){
                        for(auto it=m.begin() ; it!=m.end() ; it++){
                            if(it->second==0 && it->first!='?'){
                                cout<<it->first;
                                m[it->first]=1;
                                break;
                            }
                        }
                    }else{
                        cout<<ans[i];
                    }
                }
                w+=25;
            }else{
                if(s[w]=='?'){
                    cout<<'A';
                }else{
                    cout<<s[w];
                }
                
            }
        }
    }
       else{
        cout<<-1<<endl;
    }
    return 0;
}