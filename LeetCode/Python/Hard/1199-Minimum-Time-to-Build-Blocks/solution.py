'''
Solution is based on these resources:

1. https://leetcode.com/problems/minimum-time-to-build-blocks/solutions/387035/python-o-n-log-n-using-huffman-s-algorithm-priority-queue-with-explanation/

2. Video on Huffman coding --> https://www.youtube.com/watch?v=co4_ahEDCho
'''
class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        heapq.heapify(blocks)

        while len(blocks) > 1:
            smaller: int=heapq.heappop(blocks)

            larger: int=heapq.heappop(blocks)

            new_block: int=larger + split

            heapq.heappush(blocks, new_block)

        return blocks[0]