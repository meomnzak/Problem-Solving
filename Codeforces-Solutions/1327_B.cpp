#include <bits/stdc++.h>


using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        map<int,int> m;
        map<int,int> prince;
        vector<vector<int>> vec;
        int n;
        cin>>n;
        for(int i = 0 ; i<n; i++){
            m[i+1] = 0;
        }
        int h;
        for(int i = 0 ; i<n ; i++){
            vector<int> temp;
            cin>>h;
            int num;
            for(int j = 0 ;j<h ;j++){
                cin>>num;
                temp.push_back(num);
            }
            vec.push_back(temp);
        }
        for(int i = 0 ;i<n; i++){
            for(int j=0 ;j<vec[i].size(); j++){
                if(m[vec[i][j]]==0){
                    m[vec[i][j]] = 1;
                    prince[i]=1;
                    break;
                }
            }
        }
        bool flag = false;
        for(int i = 0 ;i<n; i++){
            if(prince[i]==0){
                for(auto it = m.begin() ; it != m.end(); it++){
                    if(it->second==0){
                        flag = true;
                        cout<<"IMPROVE"<<endl;
                        cout<<i+1<<" "<<it->first<<endl;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            cout<<"OPTIMAL"<<endl;
        }
    }
    return 0;
}