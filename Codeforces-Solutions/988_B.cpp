#include <bits/stdc++.h>


using namespace std;


bool mySort(string s1,string s2){
    return s1.size()<s2.size();
}
int main(){
    vector<string> vec;
    int n;
    cin>>n;
    string name;
    for(int i =0 ; i<n ; i++){
        cin>>name;
        vec.push_back(name);
    }
    sort(vec.begin(),vec.end(),mySort);
    bool flag = true;
    for(int  i =0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(vec[j].find(vec[i]) == string::npos){
                flag = false;
            }
        }
    }
    
    if(!flag){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int  i =0 ; i<n ; i++){
            cout<<vec[i]<<endl;
        }
    }
    return 0;
}