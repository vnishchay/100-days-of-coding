class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
        arrr = []

        for ss in strs:
            sorted_s = ''.join(sorted(ss))
            if sorted_s not in mp:
                mp[sorted_s] = []
            mp[sorted_s].append(ss)
        
        for _, values in mp.items():
            arrr.append(values)
        
        return arrr

                    

        



        