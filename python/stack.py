# 946. Validate Stack Sequences
class Solution:
    def validateStackSequences(self, pushed, popped) -> bool:
        st = []

        while pushed or popped:
            if st and st[-1] == popped[0]:
                st.pop()
                popped.pop(0)
            elif pushed:
                st.append(pushed.pop(0))
            else:
                return False

        return True
