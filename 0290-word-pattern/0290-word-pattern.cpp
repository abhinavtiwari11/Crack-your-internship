class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
  vector<string> vs;
        string str;
        for(auto x : s){
           if(x != ' '){
               str = str + x;
            }
            else{
                vs.push_back(str);
                str = "";
            }
        }
        vs.push_back(str);

        if(pattern.length() != vs.size())
        return false;

        map<char , string> CS;
        map<string , char> SC;

        for(int i = 0 ; i < vs.size() ; i++){
            if( CS.count(pattern[i]) || SC.count(vs[i]) ){
                if(CS[pattern[i]] != vs[i] || SC[vs[i]] != pattern[i] )
                return false;
            }
            else{
                CS[pattern[i]] = vs[i];
                SC[vs[i]] = pattern[i];
            }
        }

        return true;
        
    }
};