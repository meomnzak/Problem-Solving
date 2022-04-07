class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0;
        for(int i = 0 ; i<text.size() ; i++){
            if(text[i]==' ')spaces++;
        }
        vector<string> vec;
        stringstream ss(text);
        string word;
        while(ss>>word){
            vec.push_back(word);
        }
        
        if(vec.size()==1){
            string temp = vec[0];
            for(int i = 0 ; i<spaces ; i++){
                temp+=" ";
            }
            return temp;
        }
        
        int oneSpace = spaces/(vec.size()-1);
        int extra = spaces%(vec.size()-1);
        
        string s = "";
        
        for(int i = 0 ; i<vec.size() ; i++){
            s+=vec[i];
            if(i==vec.size()-1){
                for(int j = 0 ; j<extra ; j++){
                    s+=" ";
                }
            }else{
                for(int j = 0 ; j<oneSpace ; j++){
                    s+=" ";
                }
                
            }
        }
        
        return s;
        
    }
};