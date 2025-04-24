from typing import List


class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        _sum = sum(nums)
        cnt = 0
        while _sum % k != 0:
            cnt += 1
            _sum -= 1
        return cnt


