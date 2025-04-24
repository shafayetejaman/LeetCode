class Solution:
    def uniqueXorTriplets(self, nums: list[int]) -> int:
        n = len(nums)
        st = set()

        for i in range(n):
            for j in range(i, n):
                for k in range(j, n):
                    num = nums[i] ^ nums[j] ^ nums[k]
                    st.add(num)

        return len(st)
       
        