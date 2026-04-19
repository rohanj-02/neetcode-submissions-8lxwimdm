class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l = 0
        m = len(matrix) #3
        n = len(matrix[0]) #4
        r =  m * n - 1

        while l <= r:
            mid = int(l + (r - l) / 2)
            c_l = mid // n
            c_r = mid % n
            print(f"{l} {r} {mid} {c_l} {c_r}")
            if matrix[c_l][c_r] == target:
                return True
            elif matrix[c_l][c_r] > target:
                r = mid - 1
            else:
                l = mid + 1
        return False 