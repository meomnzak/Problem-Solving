#include <bits/stdc++.h>


using namespace std;
int main(){
    vector<int> vec;
    int n;
    int k;
    cin>>n>>k;
    int num;
    for(int i = 0 ;i<n; i++){
        cin>>num;
        vec.push_back(num);
    }
    double sum = 0;
    double calc =0;
    double sol = 0;
    

    for(int i= 0 ; i<n; i++){
            for(int j = i ; j<n ; j++){
                sum+=vec[j];
                if(j-i+1>=k){
                    calc = sum/double(j-i+1);
                    sol = max(calc,sol);
                }
            }
            sum = 0;
    }
    cout<< setprecision(15);
    cout<< std::fixed;
    
    cout<<sol<<endl;
    
    return 0;
}