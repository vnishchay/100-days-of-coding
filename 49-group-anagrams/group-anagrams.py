class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        mp = defaultdict(list)
        for s in strs:
            ss = ''.join(sorted(s))
            mp[ss].append(s)
        
        arr = []
        for _, values in mp.items():
            arr.append(values)
        
        return arr
            

        