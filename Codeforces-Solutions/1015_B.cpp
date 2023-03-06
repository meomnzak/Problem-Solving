#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    string go;
    string other;
    cin>>go>>other;
    string temp1 = go;
    string temp2 = other;
    sort(temp1.begin(),temp1.end());
    sort(temp2.begin(),temp2.end());
    if(temp1==temp2){
        vector<int> vec;
        for(int i = 0 ; i<n-1 ; i++){
            if(go[i]!=other[i]){
                for(int j = i+1 ; j<n ; j++){
                    if(go[j]==other[i]){
                        for(int k = j ; k>i ; k--){
                            swap(go[k],go[k-1]);
                            vec.push_back(k);
                        }
                        break;
                    }
                }
            }
        }
        cout<<vec.size()<<endl;
        for(int i = 0 ; i<vec.size() ; i++){
            cout<<vec[i];
            if(i!=vec.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    
    return 0;
}