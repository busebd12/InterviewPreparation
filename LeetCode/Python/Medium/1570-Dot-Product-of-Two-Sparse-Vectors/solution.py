class SparseVector:
    def __init__(self, nums: List[int]):
        self.vector=nums

    def get_vector(self) -> List[int]:
        return self.vector

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        dot_product=0
        
        vector1=self.get_vector()

        vector2=vec.get_vector()
        
        n=len(vector1)

        for index in range(0, n):
            product=vector1[index] * vector2[index]

            dot_product+=product

        return dot_product

class SparseVector:
    def __init__(self, nums: List[int]):
        self.non_zero_hashmap=dict()

        for (index, number) in enumerate(nums):
            if number > 0:
                self.non_zero_hashmap[index]=number

    def get_non_zero_hashmap(self) -> Dict[int, int]:
        return self.non_zero_hashmap

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        dot_product=0
        
        vector1_non_zero_hashmap=self.get_non_zero_hashmap()

        vector2_non_zero_hashmap=vec.get_non_zero_hashmap()

        for (index, number) in vector1_non_zero_hashmap.items():
            if index in vector2_non_zero_hashmap.keys():
                product=vector1_non_zero_hashmap[index] * vector2_non_zero_hashmap[index]

                dot_product+=product

        return dot_product