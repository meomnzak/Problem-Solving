class Solution {
public:
    bool backspaceCompare(string s, string t) {
       int pointerOne = s.size()-1;
       int pointerTwo = t.size()-1;
       while(pointerOne>=0 || pointerTwo>=0){
           int cntOne = 0;
           while(pointerOne>=0 && (cntOne>0 || s[pointerOne]=='#')){
                if(s[pointerOne]=='#'){
                    cntOne++;
                }else{
                    cntOne--;
                }
               pointerOne--;
           }
           int cntTwo = 0;
           while(pointerTwo>=0 && (cntTwo>0 || t[pointerTwo]=='#')){
                if(t[pointerTwo]=='#'){
                    cntTwo++;
                }else{
                    cntTwo--;
                }
               pointerTwo--;
           }
           if(pointerOne<0 && pointerTwo<0) break;
           if(pointerOne<0 || pointerTwo<0) return false;
           if(s[pointerOne]!=t[pointerTwo]) return false;
           pointerOne--;
           pointerTwo--;
           
       } 
        return true;
    }
};