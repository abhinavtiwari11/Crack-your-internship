class Solution {
public:
    bool is_remaining_palidrome(int l, int r, string s){
        while (r > l){
            if(s[l] == s[r]){
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0; 
        int r = s.length() - 1;
        while(r > l){
            if(s[l] == s[r]){
                l++;
                r--;
            } else {
                return is_remaining_palidrome(l + 1, r, s) || is_remaining_palidrome(l, r - 1, s);
            }
        }
        return true;
    }
};
