class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        mp = {}

        for c in s:
            if c in mp:
                mp[c]+=1
            else :
                mp[c]=1
        

        for a in t:
            if a not in mp:
                return False
            elif mp[a] <= 0:
                return False
            else:
                mp[a]-=1
        
        return True
    



        