class Solution {
public:
    
        
     bool isIsomorphic(string s, string t) {
        int n = s.size(), m = t.size();
        if(n !=m) return false;
      unordered_map<char,char>mp1,mp2;
      for(int i=0;i<n;i++){
          char ch1 = s[i], ch2 = t[i];
          if(mp1.find(ch1) == mp1.end()){
              if(mp2.find(ch2) == mp2.end()){
                  mp1[ch1] = ch2;
                  mp2[ch2] = ch1;
              }
              else{
                  char x = mp2[ch2];
                  if(x != ch1) return false;
              }
          }
          else{
              if(mp1[ch1] != ch2) return false;
          }
      }
      return true;
    }
};
