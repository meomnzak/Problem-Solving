#include <bits/stdc++.h>


using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> vec;
        int num;
        cin>>num;
        int multi = 1;
        while(num!=0){
            int val = (num%10);
            val*=multi;
            if(val!=0){
                vec.push_back(val);
            }
            
            num/=10;
            multi*=10;
        }
        cout<<vec.size()<<endl;
        for(int i = 0 ; i<vec.size() ; i++){
            cout<<vec[i];
            if(i!=vec.size()-1){
                cout<<" ";
            }
            
        }
        cout<<endl;
    }
    return 0;
}