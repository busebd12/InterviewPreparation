#read from standard in four times (compacted for loop)
#use _ instead of a variable like i because we want to signify that we don't plan on returning it
x, y, z, n=(int(input()) for _ in range(4))

#compact way of writing three nested loops
print ([[a,b,c] for a in range(0,x+1) for b in range(0,y+1) for c in range(0,z+1) if a + b + c != n ])