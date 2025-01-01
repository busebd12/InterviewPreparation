class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result: str=""

        empty_string: str=""

        if strs.count(empty_string) > 0:
            return result

        shortest_word=self.get_shortest_word(strs)

        prefixes=self.get_prefixes(shortest_word)

        for prefix in prefixes:
            if self.all_words_have_prefix(strs, prefix)==True:
                result=prefix
            else:
                break

        return result

    def get_shortest_word(self, strs: List[str]) -> str:
        shortest_word: str=strs[0]

        n: int=len(strs)

        for index in range(1, n):
            if len(strs[index]) < len(shortest_word):
                shortest_word=strs[index]
        
        return shortest_word

    def get_prefixes(self, word: str) -> List[str]:
        prefixes: List[str]=list()

        w: int=len(word)

        for index in range(0, w):
            prefix: str=word[0:index + 1]

            prefixes.append(prefix)

        return prefixes

    def all_words_have_prefix(self, strs: List[str], prefix: str) -> bool:
        for word in strs:
            if word.startswith(prefix)==False:
                return False

        return True