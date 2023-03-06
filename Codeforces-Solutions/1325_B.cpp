#include <bits/stdc++.h>


using namespace std;
int main(){
    set<int> st;
    int t;
    cin>>t;
    int n;
    int num;
    while(t--){
        cin>>n;
        for(int i = 0 ;i<n ; i++){
            cin>>num;
            st.insert(num);
        }
        cout<<st.size()<<endl;
        st.clear();
    }
    return 0;
}