# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        if not head : 
            return None

        # k = 2
        # swapping nodes in linked list. 
        node = head
        lst = head  
        tmp = head 

        while k > 1:
            lst = lst.next 
            k-=1

        kth_from_start = lst  

        while lst.next :
            lst = lst.next
            tmp = tmp.next 
        
        kth_from_end = tmp
        
        kth_from_start.val , kth_from_end.val = kth_from_end.val, kth_from_start.val 

        return head 

                   
            

        