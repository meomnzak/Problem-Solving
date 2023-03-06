#include <bits/stdc++.h>


using namespace std;
int main(){
    int a,b,x;
    cin>>a>>b>>x;
    string s = "";
    bool zero = false;
    int one = max(a,b);
    int two = min(a,b);
    if(a>b){
        zero = true;
    }
    if(zero){
        while(x>1){
            s+="01";
            one-=1;
            two-=1;
            x-=2;
        }
        if(x==0){
            while(two){
                s+='1';
                two--;
            }
            while(one){
                s+='0';
                one--;
            }
        }else{
            while(one){
                s+='0';
                one--;
            }
            while(two){
                s+='1';
                two--;
            }
        }
            
            cout<<s<<endl;
    }else{
        while(x>1){
            s+="10";
            one-=1;
            two-=1;
            x-=2;
        }
        
        if(x==0){
            while(two){
                s+='0';
                two--;
            }
            while(one){
                s+='1';
                one--;
            }
        }else{
            while(one){
                s+='1';
                one--;
            }
            while(two){
                s+='0';
                two--;
            }
        }
            
            cout<<s<<endl;
    }
    return 0;
}