class Solution {
public:
    bool validPalindrome(string s, int l =0, int r = -1, bool isSkip = false) {
         if(r == -1) {
             r=  s.size() -1; 
         }

         while(l < r ) {
            if(s[l] != s[r]) {
                break; 
            }
            l++; r--; 
         }
         if(s[l] == s[r] ) return true; 
         if(l != r && isSkip) return false; 
        return validPalindrome(s, l +1, r, true) || validPalindrome(s, l, r-1, true); 
    }
};