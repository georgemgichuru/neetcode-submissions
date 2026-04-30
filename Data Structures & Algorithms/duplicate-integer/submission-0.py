from collections import defaultdict
# Traverse through the nums array and check if the number is 
# repeated updating the hashmap in the process
class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hashmap = defaultdict(int)
        if nums is not None:
            for i in nums:
                hashmap[i] += 1
            
            ret:bool = any(value > 1 for value in hashmap.values())
            return ret