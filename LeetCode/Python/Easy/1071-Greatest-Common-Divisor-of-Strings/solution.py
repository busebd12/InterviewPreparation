class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        result: str=""

        all_prefixes: List[str]=list()

        str1_prefixes: List[str]=self.get_prefixes(str1)

        str2_prefixes: List[str]=self.get_prefixes(str2)

        all_prefixes.extend(str1_prefixes)

        all_prefixes.extend(str2_prefixes)

        for prefix in all_prefixes:
            if self.can_create_string(str1, prefix) and self.can_create_string(str2, prefix):
                if not result or len(result) < len(prefix):
                    result=prefix

        return result

    def get_prefixes(self, string: str) -> List[str]:
        prefixes: List[str]=[string[0 : i + 1] for i in range(0, len(string))]

        return prefixes

    def can_create_string(self, string: str, prefix: str) -> bool:
        candidate: str=""

        while len(candidate) < len(string):
            candidate=candidate + prefix

        return candidate==string