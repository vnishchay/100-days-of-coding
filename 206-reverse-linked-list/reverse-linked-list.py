# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:   

        # 1 , 2 , 3 , 4 

        # none, 1, 2 , 3 , 4 
        # 3 -> 2 -> 1 -> none

        
        prev = None 

        while head:
            
            node = head 
            nx = head.next
            head.next = prev 
            prev = node
            head = nx  
        
        return prev 
        