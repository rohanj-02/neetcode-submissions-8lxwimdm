from collections import deque

class Solution:
    def isStarter(self, ch: str) -> bool:
        return ch in ['(', '{', '[']

    def isValid(self, s: str) -> bool:
        stack = deque()
        starterOf = {
            ')': '(',
            '}': '{',
            ']': '['
        }
        for i in range(0, len(s)):
            if self.isStarter(s[i]):
                stack.append(s[i])
            elif len(stack) > 0 and stack[-1] == starterOf[s[i]]:
                # if stack top is equal to starter opp, pop it
                stack.pop()
            else:
                stack.append(s[i])
        return len(stack) == 0
