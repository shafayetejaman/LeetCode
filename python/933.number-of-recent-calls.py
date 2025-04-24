#
# @lc app=leetcode id=933 lang=python3
#
# [933] Number of Recent Calls
#

# @lc code=start
from collections import deque


class RecentCounter:

    def __init__(self):
        self.db = deque()

    def ping(self, t: int) -> int:
        self.db.append(t)
        
        while self.db and self.db[0] < t - 3000:
           self.db.popleft() 

        return len(self.db)

# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
# @lc code=end
