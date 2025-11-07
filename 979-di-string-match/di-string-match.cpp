class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res;
        int n = s.size(), j = 0;
        for (int i = 0; i <= s.size(); i++) {
            res.push_back(i);
            if (i == n || s[i] == 'I') {
                // reverse the segment from j to i (inclusive)
                reverse(res.begin() + j, res.end());
                j = i + 1;
            }
        }
        return res;
    }
};