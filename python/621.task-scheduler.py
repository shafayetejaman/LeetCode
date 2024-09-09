#
# @lc app=leetcode id=621 lang=python
#
# [621] Task Scheduler
#

# @lc code=start

import collections
import heapq


class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        counts = collections.Counter(tasks)
        maxHeap = [-i for i in counts.values()]
        heapq.heapify(maxHeap)

        time = 0
        q = collections.deque()

        while maxHeap or q:
            time += 1

            if maxHeap:
                curr = heapq.heappop(maxHeap) + 1
                if curr:
                    q.append([curr, time + n])

            if q and q[0][1] == time:
                heapq.heappush(maxHeap, q.popleft()[0])

        return time


# @lc code=end
