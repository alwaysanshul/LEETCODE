class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        # 1. Check all remainder
        # 2. Flatten and sort the input
        # 3. Prefix / Suffix Sum

        for row in grid:
            for n in row:
                if n%x != grid[0][0]%x:
                    return -1
        
        nums = sorted([n for row in grid for n in row])

        prefix = 0
        sum_of_array = sum(nums)
        ans = float("inf")
        for i in range(len(nums)):
            leftCost = nums[i]*i - prefix
            rightCost = sum_of_array - prefix - (nums[i] * (len(nums) - i))
            
            operations = (leftCost + rightCost) // x
            ans = min(ans, operations)

            prefix += nums[i]

        return ans