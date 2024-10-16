#
# @lc app=leetcode id=355 lang=python
#
# [355] Design Twitter
#


# @lc code=start


from collections import deque
from heapq import heapify, heappop

class User:
    timeStamp = 0

    def __init__(self, id):
        self.id = id
        self.post = []
        self.follows = set()

    def append_post(self, tweetID):
        self.post.append([User.timeStamp, tweetID])
        User.timeStamp -= 1


class Twitter(object):

    def __init__(self):
        # follower = {}
        # post = deque()
        self.user: dict[int, User] = {}  # {userId:[followerId, post]}

    def postTweet(self, userId, tweetId):
        """
        :type userId: int
        :type tweetId: int
        :rtype: None
        """
        if not self.user.get(userId):
            self.user[userId] = User(userId)

        self.user[userId].append_post(tweetId)

    def getNewsFeed(self, userId):
        """
        :type userId: int
        :rtype: List[int]
        """
        if not self.user.get(userId):
            self.user[userId] = User(userId)

        minHeap = [post for post in self.user[userId].post]
        for followeedId in self.user[userId].follows:
            minHeap += self.user[followeedId].post

        result =[]
        heapify(minHeap)

        while minHeap and len(result) < 10:
            result.append(heappop(minHeap)[1])
            
        return result

    def follow(self, followerId, followeeId):
        """
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        if not self.user.get(followeeId):
            self.user[followeeId] = User(followeeId)
        if not self.user.get(followerId):
            self.user[followerId] = User(followerId)

        self.user[followerId].follows.add(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        if not self.user.get(followeeId):
            self.user[followeeId] = User(followeeId)
        if not self.user.get(followerId):
            self.user[followerId] = User(followerId)

        if followeeId in self.user[followerId].follows:
            self.user[followerId].follows.remove(followeeId)


# Your Twitter object will be instantiated and called as such:
obj = Twitter()
obj.postTweet(1, 5)
print(obj.getNewsFeed(1))
obj.follow(1, 2)
obj.postTweet(2, 6)
print(obj.getNewsFeed(1))
obj.unfollow(1, 2)
print(obj.getNewsFeed(1))
# @lc code=end
