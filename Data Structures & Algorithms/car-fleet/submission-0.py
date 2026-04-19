class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        time_to_reach = []
        for pos, vel in zip(position, speed):
            time_to_reach.append([pos, (target - pos)/ vel])
        
        time_to_reach.sort(key=lambda x: x[0])
        print(time_to_reach)
        stack = []
        ans = 0
        for t in time_to_reach:
            while stack and t[1] >= stack[-1][1]:
                stack.pop()
            stack.append(t)

        return len(stack)