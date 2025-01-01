class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        result: List[List[int]]=list()

        n: int=len(groupSizes)

        hashmap: Dict[int, List[int]]=dict()

        for person in range(0, n):
            group_size: int=groupSizes[person]

            if group_size not in hashmap.keys():
                hashmap[group_size]=list()
            
            hashmap[group_size].append(person)
                
            if len(hashmap[group_size])==group_size:
                result.append(hashmap[group_size])

                del hashmap[group_size]

        return result