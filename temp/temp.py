class Solution:
    def isValid(self, s: str):
        st = []
        for char in s:
            if char == "(":
                st.append("(")
            elif not st:
                return False
            else:
                st.pop()
        return len(st) == 0

    def generateParenthesis(self, n: int) -> list[str]:
        ans: list[str] = []

        def dfs(s):
            nonlocal ans
            if len(s) == 2 * n:
                if self.isValid(s):
                    ans.append(s)

                return

            dfs(s + "(")
            dfs(s + ")")

        dfs("")

        return ans

