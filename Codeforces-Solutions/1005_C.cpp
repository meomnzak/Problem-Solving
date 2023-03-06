#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> vec;
    map<int,int> m;
    int num;
    for(int i = 0 ; i <n ; i++){
        scanf("%d",&num);
        m[num]++;
        vec.push_back(num);
    }
    int val;
    int count = 0;
    bool flag;
    int go;
    for(int i = 0 ; i<n; i++){
            flag = false;
            for(int j = 0 ; j<31 ; j++){
               val = pow(2,j);
               if(val>vec[i]){
                    go = val-vec[i];
                    if(m[go]>0){
                        if(go==vec[i]){
                                if(m[go]>1){
                                    flag= true;
                                    break;
                                }
                        }else{
                            flag= true;
                            break;
                        }
                    }
               }
            }
            if(!flag){
                count++;
            }
    }
    printf("%d\n",count);
    return 0;
}