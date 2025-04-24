#
# @lc app=leetcode id=643 lang=python3
#
# [643] Maximum Average Subarray I
#


# @lc code=start
class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        l = r = 0
        sum =0
        ans = float("-inf")
        n = len(nums)

        if len(nums) == 1 and k ==1:
            return nums[0]

        while r < n:
            sum += nums[r]
            if r - l + 1 > k:
                sum -= nums[l]
                l += 1
            if r - l + 1 == k:
                ans = max(ans, sum / k)
            r += 1

        return ans


# @lc code=end
s = Solution()
print(s.findMaxAverage([1,1,1,1,1,1], 4))
