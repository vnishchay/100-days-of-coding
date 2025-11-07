class Solution {
public:
    string removeKdigits(string num, int k) {
        string ss;
        for (char digit : num) {
            while (!ss.empty() && k > 0 && ss.back() > digit) {
                ss.pop_back();
                k--;
            }
            ss.push_back(digit);
        }
        // If k > 0, we need to remove more digits from the end
        while (k > 0 && !ss.empty()) {
            ss.pop_back();
            k--;
        }
        // Remove leading zeros
        int nonZeroIdx = 0;
        while (nonZeroIdx < ss.size() && ss[nonZeroIdx] == '0') {
            nonZeroIdx++;
        }
        ss = ss.substr(nonZeroIdx);
        // If string is empty after removing zeros, return "0"
        return ss.empty() ? "0" : ss;
    }
};
