#
# @lc app=leetcode id=127 lang=python3
#
# [127] Word Ladder
#

# @lc code=start
from typing import List
from collections import deque


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def diff(s1: str, s2: str):
            cnt = 0
            for i, c in enumerate(s1):
                if c != s2[i]:
                    cnt += 1

                if cnt > 1:
                    return False
            return True

        def bfs(beginWord: str):
            wordListSet = set(wordList)
            queue = deque()
            queue.append((beginWord, 0))

            visited = set()
            visited.add(beginWord)

            while queue:
                currWord, level = queue.popleft()

                if currWord == endWord:
                    return level + 1

                for i in range(len(currWord)):
                    for c in range(26):
                        newWord = currWord[:i] + chr(ord("a") + c) + currWord[i + 1 :]
                        if (
                            newWord in wordListSet
                            and newWord not in visited
                            and diff(currWord, newWord)
                        ):
                            queue.append((newWord, level + 1))
                            visited.add(newWord)

            return 0

        return bfs(beginWord)


# @lc code=end
s = Solution()
print(s.ladderLength("a", "c", ["a", "b", "c"]))
