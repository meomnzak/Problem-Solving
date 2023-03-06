#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i<n ; i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    vector<int> temp(n);
    int first = 0;
    int last = n-1;
    for(int i = 0 ; i<n ; i++){
        if(i%2==0){
            temp[i] = vec[first];
            first++;
        }else{
            temp[i] = vec[last];
            last--;
        }
    }
    
    bool flag = true;
    
    for(int i = 1 ; i<n ; i++){
        if(i%2==1){
            if(temp[i]<temp[i-1]){
                flag = false;
                break;
            }
        }else{
             if(temp[i]>temp[i-1]){
                flag = false;
                break;
            }
        }
    }
    
    if(flag){
         for(int i = 0 ; i<n ; i++){
            cout<<temp[i];
            if(i!=n-1){
                cout<<" ";
            }
        }
    }else{
        cout<<"Impossible";
    }
    cout<<endl;
    return 0;
}