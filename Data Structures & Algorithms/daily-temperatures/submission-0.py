class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        result = [0] * len(temperatures)
        for i, temp in enumerate(temperatures):
            if stack and stack[-1][0] < temp:
                sub_result = []
                while stack and stack[-1][0] < temp:
                    result[stack[-1][1]] = i - stack[-1][1]
                    # print(f"Popping {stack[-1]} on {temp} with count = {i - stack[-1][1]}")
                    stack.pop()
            stack.append([temp, i])
        return result