#the *allows you pass in an array of values for your arguments and they will be unpacked accordingly inside the print  function
#apparently, this "overload" of the print funciton is much faster than the original print function
print(*range(1, int(input())+1), sep='')