from typing import List


class Solution:
    def transformArray(self, nums: List[int]) -> List[int]:
        new_nums = [1 for _ in range(len(nums))]
        cnt = sum(1 for x in nums if x % 2 == 0)
        for i in range(len(new_nums)):
            if cnt:
                new_nums[i] = 0
                cnt -= 1
            else:
                break
        return new_nums


s = Solution()
print(s.transformArray([1, 2, 3, 4]))
