class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        result: int=0

        g: int=len(garbage)

        t: int=len(travel)

        hashmap: Dict[chr, int]=dict()

        for index in range(0, g):
            result+=len(garbage[index])

            if garbage[index].find('G')!=-1:
                hashmap['G']=index
            
            if garbage[index].find('M')!=-1:
                hashmap['M']=index

            if garbage[index].find('P')!=-1:
                hashmap['P']=index

        for (letter, index) in hashmap.items():
            result+=sum(travel[0:index])

        return result