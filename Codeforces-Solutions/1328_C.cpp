#include <bits/stdc++.h>


using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        bool flag1=false;
        int n;
        cin>>n;
        vector<int> vec(n);
        string s;
        cin>>s;
        for(int i = 0 ; i<n ; i++){
            vec[i]=s[i]-'0';
        }
        vector<int> num1(n,0);
        vector<int> num2(n,0);
        for(int i = 0 ; i<n ; i++){
            if(vec[i]==2){
                if(!flag1){
                    num1[i]=1;
                    num2[i]=1;
                }else{
                    num1[i]=0;
                    num2[i]=2;
                }
                
            }else if(vec[i]==0){
                num1[i]=0;
                num2[i]=0;
            }else{
                if(!flag1){
                    num1[i]=1;
                    num2[i]=0;
                    flag1= true;
                }else{
                    num2[i]=1;
                    num1[i]=0;
                }
            }
        }
        for(int i = 0 ; i<n ; i++){
            cout<<num1[i];
        }
        cout<<endl;
        for(int i = 0 ; i<n ; i++){
            cout<<num2[i];
        }
        cout<<endl;
    }
    return 0;
}