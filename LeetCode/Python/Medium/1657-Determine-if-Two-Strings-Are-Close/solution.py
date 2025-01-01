class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        w1=len(word1)

        w2=len(word2)

        if w1!=w2:
            return False

        word1_frequency_map=self.build_frequency_map(word1)

        word2_frequency_map=self.build_frequency_map(word2)

        for character in word1_frequency_map.keys():
            if character not in word2_frequency_map.keys():
                return False

        word1_frequencies=[frequency for frequency in word1_frequency_map.values()]

        word2_frequencies=[frequency for frequency in word2_frequency_map.values()]

        word1_frequencies.sort()

        word2_frequencies.sort()

        return word1_frequencies==word2_frequencies

    def build_frequency_map(self, word: string) -> Dict[chr, int]:
        frequency_map=dict()

        for character in word:
            if character not in frequency_map.keys():
                frequency_map[character]=0

            frequency_map[character]+=1

        return frequency_map