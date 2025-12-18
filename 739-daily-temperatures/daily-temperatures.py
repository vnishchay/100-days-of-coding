class Solution:
    def dailyTemperatures(self, t: List[int]) -> List[int]:
        st = deque([])

        # next greater element.
        arr = [0]*len(t) 

        for i in range(len(t)-1, -1, -1):
            if not st :
                arr[i] = 0
            elif st[-1][0] <= t[i]:
                print(st[-1][0], t[i])
                while st and st[-1][0] <= t[i]:
                    st.pop()
                if st:
                    arr[i] = st[-1][1] - i
                else :
                    arr[i] = 0
            else :
                arr[i] = st[-1][1] - i
        
            st.append([t[i], i])

        return arr  





        