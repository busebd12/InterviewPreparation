class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        result: int=0

        unique_words: Set[str]=set(words)

        max_word_length: int=self.get_max_word_length(unique_words)

        buckets: List[List[str]]=[[] for iteration in range(0, max_word_length + 1)]

        self.fill_buckets(buckets, unique_words)

        word_to_length: Dict[str, int]=dict()

        for word in unique_words:
            word_to_length[word]=1
        
        for length in range(max_word_length - 1, 0, -1):
            if buckets[length]:
                next_length: int=length + 1

                if buckets[next_length]:
                    for before in buckets[length]:
                        length_to_extend_by: int=0

                        for after in buckets[next_length]:
                            if self.comes_after(before, after):
                                length_to_extend_by=max(length_to_extend_by, word_to_length[after])

                        word_to_length[before]+=length_to_extend_by

        for chain_length in word_to_length.values():
            result=max(result, chain_length)

        return result

    def get_max_word_length(self, unique_words: Set[str]) -> int:
        max_word_length: int=0

        for word in unique_words:
            length: int=len(word)

            max_word_length=max(max_word_length, length)

        return max_word_length

    def fill_buckets(self, buckets: List[List[str]], unique_words: Set[str]) -> None:
        for word in unique_words:
            length: int=len(word)

            buckets[length].append(word)

    def comes_after(self, before: str, after: str) -> bool:
        b: int=len(before)

        a: int=len(after)

        i: int=0

        j: int=0

        differences: int=0

        while i < b and j < a:
            if before[i]!=after[j]:
                differences+=1

                if differences > 1:
                    return False
                
                j+=1
            else:
                i+=1

                j+=1

        return i==b