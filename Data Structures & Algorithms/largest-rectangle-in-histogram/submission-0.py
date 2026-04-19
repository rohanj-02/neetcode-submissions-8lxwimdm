class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        max_area = 0

        for i, _ in enumerate(heights):
            while stack and heights[stack[-1]] > heights[i]:
                h = heights[stack.pop()]
                left = stack[-1] if stack else -1
                w = i - left - 1
                max_area = max(max_area, h * w)
            stack.append(i)

        n = len(heights)
        while stack:
            h = heights[stack.pop()]
            left = stack[-1] if stack else -1
            w = n - left - 1
            max_area = max(max_area, h * w)
        return max_area