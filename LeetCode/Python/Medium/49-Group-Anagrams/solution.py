class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result=list()

        hashmap=dict()

        for string in strs:
            sorted_string="".join(sorted(string))

            if sorted_string not in hashmap.keys():
                hashmap[sorted_string]=list()
            
            hashmap[sorted_string].append(string)

        for (key, values) in hashmap.items():
            result.append(values)

        return result