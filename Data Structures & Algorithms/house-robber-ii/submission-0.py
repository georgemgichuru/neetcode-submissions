class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        def rob_range(start, end):
            prev2 = prev1 = 0
            for i in range(start, end + 1):
                current = max(prev1, nums[i] + prev2)
                prev2 = prev1
                prev1 = current
            return prev1
        
        return max(rob_range(0, len(nums)-2), rob_range(1, len(nums) - 1))