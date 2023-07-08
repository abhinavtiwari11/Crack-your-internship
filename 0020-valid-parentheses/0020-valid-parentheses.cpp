class Solution {
public:
    bool isValid(string s) {
        stack<char>r;
        for(int i =0; i<s.size(); i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                r.push(s[i]);
            }
            else{
                if(r.empty())return false;
                char c = r.top(); r.pop();
                if((s[i]==')' && c=='(') or (s[i]=='}' && c=='{') or (s[i]==']' && c=='[')){
                    continue;
                }else return false;
            }
        }
       if(r.empty()){
           return true;
       }else{
           return false;
       }
    
    }
};
