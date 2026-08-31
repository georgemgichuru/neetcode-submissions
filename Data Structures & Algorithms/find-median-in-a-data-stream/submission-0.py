import heapq
class MedianFinder:

    def __init__(self):
        self.small = []
        self.large = []

    def addNum(self, num: int) -> None:
        heapq.heappush(self.small, -num)
        heapq.heappush(self.large, -heapq.heappop(self.small))
# 2. Maintain invariant: len(small) >= len(large)
        if len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def findMedian(self) -> float:
        # Odd number of total elements: root of small heap
        if len(self.small) > len(self.large):
            return float(-self.small[0])
        # Even number of total elements: average of roots
        return (-self.small[0] + self.large[0]) / 2.0