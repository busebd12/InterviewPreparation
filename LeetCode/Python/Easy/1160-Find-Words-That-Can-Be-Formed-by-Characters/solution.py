from collections import Counter

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        result: int=0

        for word in words:
            all_characters_found: bool=True

            frequencies: Counter[chr, int]=Counter(chars)

            for character in word:
                if character not in frequencies.keys() or frequencies[character]==0:
                    all_characters_found=False

                    break
                else:
                    if frequencies[character] > 0:
                        frequencies[character]-=1

            if all_characters_found:
                result+=len(word)

        return result