dictionary={}

#we map the student's name to the their average
#so, we just have to provide the students name and we are done
for i in range(int(input())):
	line=input().split()
	dictionary[line[0]]=sum(map(float,line[1:]))/3

print("{0:.2f}".format(dictionary[input()]))