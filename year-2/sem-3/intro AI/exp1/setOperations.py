print("This is Karan Taneja's code. SAP - 500084399.")

A = []
B = []

n = int(input("Number of set elements: "))

print("Enter set A:")
for i in range(n):
    A.append(int(input()))

print("Enter set B:")
for i in range(n):
    B.append(int(input()))

A = set(A)
B = set(B)

print("Union of the 2 sets:", (A | B))

print("Intersection of the 2 sets:", (A & B))

print("Difference of the 2 sets:", (A - B))

print("Symmetric difference of the 2 sets:", (A ^ B))
