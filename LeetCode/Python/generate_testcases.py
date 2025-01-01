import random

limit=(10**5)

matrix=[[random.choice([0,1]) for _ in range(0, limit)] for _ in range(0, limit)]

print(matrix)