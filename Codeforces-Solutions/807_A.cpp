#include <bits/stdc++.h>


using namespace std;
int main(){
    bool flag = false;
    int n;
    cin>>n;
    int num1;
    int num2;
    vector<int> vec;
    for(int i = 0 ; i<n ; i++){
        cin>>num1>>num2;
        vec.push_back(num1);
        if(num1!=num2){
            flag = true;
            break;
        }
    }
    if(flag){
        cout<<"rated"<<endl;
    }else{
        vector<int> temp = vec;
        sort(temp.begin(),temp.end(),greater<int>());
        if(temp==vec){
            cout<<"maybe"<<endl;
        }else{
            cout<<"unrated"<<endl;
        }
    }
    return 0;
}