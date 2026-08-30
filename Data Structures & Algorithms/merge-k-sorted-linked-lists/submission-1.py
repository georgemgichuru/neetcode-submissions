# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import heapq
from typing import List, Optional

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """
        Merges k sorted linked lists into one sorted linked list using a min-heap (priority queue).
        
        Time Complexity:  O(N log k) where N is the total number of nodes across all lists,
                          and k is the number of linked lists.
        Space Complexity: O(k) auxiliary space for the heap containing at most k elements at a time.
        """
        heap = []
        for i, node in enumerate(lists):
            if node:
                heapq.heappush(heap, (node.val, i, node))
                
        # Create a dummy node to act as the head anchor for the merged list.
        dummy = ListNode(0)
        tail = dummy
        
        # Process the heap until all nodes from all lists are merged.
        while heap:
            # Pop the smallest available node across all current list heads
            val, i, node = heapq.heappop(heap)
            
            # Append the smallest node to the merged linked list
            tail.next = node
            tail = tail.next
            
            # If the extracted node has a next node, push it into the heap
            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next)) 
                
        # Return the head of the new merged list (skipping the dummy node)
        return dummy.next