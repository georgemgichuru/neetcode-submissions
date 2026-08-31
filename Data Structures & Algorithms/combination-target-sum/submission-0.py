class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []

        def backtrack(start, target, current):
            if target == 0:
                result.append(current[:])
                return
            if target < 0:
                return
            
            for i in range(start, len(nums)):
                current.append(nums[i])
                backtrack(i, target - nums[i], current)
                current.pop()
        backtrack(0, target, [])
        return result