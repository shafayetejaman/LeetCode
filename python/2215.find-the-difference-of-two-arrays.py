#
# @lc app=leetcode id=2215 lang=python3
#
# [2215] Find the Difference of Two Arrays
#

# @lc code=start
from typing import List


class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        st1 = set(nums1)
        st2 = set(nums2)

        for i in nums1:
            if i in st2:
                st1.discard(i) 
                st2.discard(i) 

        return [list(st1), list(st2)]  

# @lc code=end
