class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num) ,maxi = s ,mini = s;
        for(char ch : s){
            if(ch!='9'){
                for(char &c : maxi){
                    if(ch==c) c = '9';
                }
                break;
            }
        }
        if (s[0] != '1') {
        char target = s[0];
        for (char &c : mini) {
            if (c == target) c = '1';
        }
    }
        else {
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != '0' && s[i] != '1') {
                char target = s[i];
                for (char &c : mini) {
                    if (c == target) c = '0';
                }
                break;
            }
        }
    }
    int a = stoi(maxi);
    int b = stoi(mini);
    return a - b;
    }
};