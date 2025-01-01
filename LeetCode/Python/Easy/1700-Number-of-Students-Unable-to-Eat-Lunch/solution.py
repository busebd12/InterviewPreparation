from collections import deque

class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        sandwiches.reverse()
        
        stack=sandwiches

        queue=deque(students)

        while stack:
            students_ate=False

            q_size=len(queue)

            for iteration in range(0, q_size):
                student=queue.popleft()

                if student==stack[-1]:
                    students_ate=True

                    stack.pop()
                else:
                    queue.append(student)

            if not students_ate:
                break

        return len(queue)