from math import ceil, log2


number = int(input("enter a decimal: "))
noOfBits = ceil(log2(number))
print(noOfBits, bin(number))
