#
# @lc app=leetcode id=735 lang=python3
#
# [735] Asteroid Collision
#


# @lc code=start
# class Solution:
#     def asteroidCollision(self, asteroids: list[int]) -> list[int]:
#         st = []
#         for i in asteroids:
#             if i > 0 or not st:
#                 st.append(i)
#             else:
#                 poped = False
#                 while st:
#                     poped = False
#                     if st[-1] < 0:
#                         st.append(i)
#                         break
#                     elif st[-1] + i < 0:
#                         st.pop()
#                         poped = True
#                     elif st[-1] + i > 0:
#                         break
#                     else:
#                         st.pop()
#                         break
#                 if not st and poped:
#                     st.append(i)
#         return st


class Solution:
    def asteroidCollision(self, asteroids: list[int]) -> list[int]:
        st = []
        for i in asteroids:
            while st and i < 0 < st[-1]:
                if st[-1] > abs(i):
                    break
                elif st[-1] == abs(i):
                    st.pop()
                    break
                else:
                    st.pop()
                    continue
            else:
                st.append(i)
        return st


# @lc code=end

s = Solution()
print(s.asteroidCollision([2, -1, 1, -2]))
