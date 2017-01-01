i=int(input())

#store the i number of numbers
myList=list(map(int,input().strip().split()))[:i]

z=max(myList)

while max(myList)==z:
    myList.remove(max(myList))

print(max(myList))