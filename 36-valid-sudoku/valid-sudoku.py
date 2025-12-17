class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [set() for _ in range(9) ]
        col = [set() for _ in range(9)]
        box = [set() for _ in  range(9)]
        # r//3*3 + c // 3 

        for r in range(len(row)):
            for c in range(len(col)):

                val = board[r][c]

                if val == '.':
                    continue

                b = r//3*3 + c//3 

                if val in row[r] or val in col[c] or val in box[b]:
                    return False
                
                box[b].add(val)
                row[r].add(val)
                col[c].add(val)
        
        return True 
 







        