from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
            return
        
        # 1. Find the middle of the list
        slow = fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        # 2. Split and reverse the second half
        current = slow.next
        slow.next = None  # Crucial: cut the first half to avoid cycles
        prev = None
        
        while current:
            next_temp = current.next
            current.next = prev
            prev = current
            current = next_temp
        
        # 3. Interleave/merge the two halves
        first, second = head, prev
        while second:
            temp1, temp2 = first.next, second.next
            first.next = second
            second.next = temp1
            first, second = temp1, temp2