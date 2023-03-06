#include <bits/stdc++.h>


using namespace std;
int main(){
    map<int,int> m;
    int n;
    int q;
    scanf("%d%d",&n,&q);
    int num;
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&num);
        m[log2(num)]++;
    }
    int val;
    int count;
    while(q--){
        count = 0;
        cin>>val;
        for(int i = 30 ; i>=0 &&val>0 ; i-- ){
            int calc = val/pow(2,i);
            int go = min(m[i],calc);
            count+=go;
            val -= go * pow(2,i);
        }
        if(val>0){
            cout<<-1<<endl;
        }else{
             cout<<count<<endl;
        }
       
    }
    
     
    
        return 0;
}