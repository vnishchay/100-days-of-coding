# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        n = ListNode()
        m = n 

        

        while list1 or list2:
            if list1 and list2:
                if list1.val > list2.val :
                    n.next = list2 
                    n = n.next
                    list2 = list2.next 
                else :
                    n.next = list1
                    n = n.next
                    list1 = list1.next 
            elif list1:
                n.next = list1
                break 
            elif list2 :
                n.next = list2
                break 
            
        return m.next 



        