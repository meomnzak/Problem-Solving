#include <bits/stdc++.h>


#define endl '\n'



using namespace std;

typedef long long ll;



const int N = 1e5+7;

int arr[N][7];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin>>arr[i][j];
            }
        }
        vector<vector<int>> vec(7);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                if(arr[i][j]==1){
                    vec[j].push_back(i);
                }
            }
        }

        bool flag = false;
        for (int i = 0; i < 5; ++i) {
            for (int j = i+1; j < 5; ++j) {
                if(vec[i].size()>=n/2 && vec[j].size()>=n/2){
                    set<int> st;
                    for (int k = 0; k < vec[i].size(); ++k) {
                        st.insert(vec[i][k]);
                    }
                    for (int k = 0; k < vec[j].size(); ++k) {
                        st.insert(vec[j][k]);
                    }
                    if(st.size()==n){
                        flag = true;
                        goto go;
                    }
                }
            }
        }


        go:{
            if(flag){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        };

    }



}