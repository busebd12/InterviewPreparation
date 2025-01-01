class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result: List[List[int]]=list()

        used: Set[Tuple[int, ...]]=set()

        combination: List[int]=list()

        total: int=0

        self.solve(candidates, result, used, combination, target, total)

        return result

    def solve(self, candidates: List[int], result: List[List[int]], used: Set[Tuple[int, ...]], combination: List[int], target: int, total: int) -> None:
        if total==target:
            combination_tuple: Tuple[int, ...]=tuple(sorted(combination))

            if combination_tuple not in used:
                result.append(combination.copy())

                used.add(combination_tuple)
            
            return

        for number in candidates:
            if total + number <= target:
                total+=number
                
                combination.append(number)

                self.solve(candidates, result, used, combination, target, total)

                total-=number

                combination.pop()