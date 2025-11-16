class Solution {
public:
    int numSub(string s) {
        long long num = 0; 
        int mod = 1000000007 ; 
        long  long subtr = 0; 
        for(int i = 0; i < s.size(); i ++) {
            if(s[i] == '1'){
                subtr+=1; 
            } else {
                num = num % mod + (subtr*(subtr + 1) / 2) % mod ; 
                subtr = 0; 
            }
        }
        if(subtr > 0) {
            num = num % mod + (subtr*(subtr + 1) / 2 )% mod;
        }
        return num % mod;
    }
};