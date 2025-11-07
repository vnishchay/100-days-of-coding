class Solution {
public:
// s, 
bool checkValidString(string s) {
    int cmin = 0, cmax = 0;
    for (char c : s) {
        if (c == '(') {
            cmin++; cmax++;
        } else if (c == ')') {
            cmin--; cmax--;
        } else { // '*'
            cmin--;    // treat '*' as ')'
            cmax++;    // or treat '*' as '('
        }
        if (cmax < 0) return false;         // Too many ')'
        cmin = std::max(cmin, 0);           // Clamp to 0, can't be less
    }
    return cmin == 0;                       // All '(' are matched
}

};