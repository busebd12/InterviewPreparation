from collections import deque

class Solution:
    def pathSum(self, nums: List[int]) -> int:
        result=0

        hashmap=dict()

        for number in nums:
            depth, position, value=self.get_triplet(number)

            key=(depth, position)

            hashmap[key]=value

        root_depth, root_position, root_value=self.get_triplet(nums[0])

        queue=deque()

        queue.append((root_depth, root_position, root_value))

        while queue:
            q_size=len(queue)

            for iteration in range(0, q_size):
                node_depth, node_position, node_value=queue.popleft()

                child_depth=node_depth + 1

                left_child_position=(node_position * 2) - 1

                right_child_position=node_position * 2

                left_child_key=(child_depth, left_child_position)

                right_child_key=(child_depth, right_child_position)

                if left_child_key not in hashmap.keys() and right_child_key not in hashmap.keys():
                    result+=node_value

                    continue

                if left_child_key in hashmap.keys():
                    queue.append((child_depth, left_child_position, node_value + hashmap[left_child_key]))

                if right_child_key in hashmap.keys():
                    queue.append((child_depth, right_child_position, node_value + hashmap[right_child_key]))

        return result

    def get_triplet(self, number: int) -> Tuple[int, ..., int]:
        count=0

        depth=-1

        position=-1

        value=-1

        while number > 0 and count < 3:
            digit=number % 10
            
            if count==0:
                value=digit
            elif count==1:
                position=digit
            elif count==2:
                depth=digit

            number//=10

            count+=1

        return (depth, position, value)