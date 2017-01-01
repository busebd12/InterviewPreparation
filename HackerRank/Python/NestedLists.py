gradebook=[]

for _ in range(0,int(input())):
    gradebook.append([input(), float(input())])

#sort the list and get the second highest
second_highest=sorted(list(set([grades for name, grades in gradebook])))[1]

print('\n'.join([a for a,b in sorted(gradebook) if b==second_highest]))