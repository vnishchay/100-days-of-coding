class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        if m == 0 and n == 0:
            return []

        n1 = m + n -1

        for i in range(n1, -1, -1):

            if n <= 0:
                break
        
            if  m > 0 and nums1[m-1] > nums2[n-1]:
                nums1[i] = nums1[m-1]
                m-=1
            else :
                nums1[i]= nums2[n-1]
                n-=1
        
        return nums1 








        