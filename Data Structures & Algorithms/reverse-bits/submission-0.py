class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for _ in range(32):
            # Shift ans left to make room for the next bit
            ans <<= 1
            # Extract the rightmost bit of n and add it to ans
            ans |= (n & 1)
            # Shift n right to process the next bit
            n >>= 1
        return ans
