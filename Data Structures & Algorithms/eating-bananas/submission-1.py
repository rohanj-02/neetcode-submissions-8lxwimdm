import math
class Solution:

    def computeNumHours(self, piles: List[int], k: int) -> int:
        ans = 0
        for p in piles:
            ans += math.ceil(p/k)
        return ans

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        maxBananaPile = max(piles)
        l = 1
        r = maxBananaPile
        ans = maxBananaPile

        while l <= r:
            mid = int(l + (r - l)/2)
            hrs = self.computeNumHours(piles, mid)
            if hrs <= h:
                ans = min(ans, mid)
                r = mid - 1
            else:
                l = mid + 1
        return ans
