from collections import defaultdict

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = defaultdict(int)   # char -> count in current window
        l = 0                   # left pointer of window
        ans = 0

        for r, ch in enumerate(s):   # r = right pointer
            mp[ch] += 1

            # shrink window while current char is duplicated
            while mp[ch] > 1:
                mp[s[l]] -= 1
                l += 1

            # window [l, r] now has all unique chars
            ans = max(ans, r - l + 1)

        return ans
