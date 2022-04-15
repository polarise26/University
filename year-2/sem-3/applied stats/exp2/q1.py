import pandas as pd

data = pd.read_excel(
    r"C:\Users\kannu\PycharmProjects\applstatslab\venv\exp2\Demo.xlsx")

print("          Marks          ")
mcol = data['Marks'].sort_values(ascending=False)
mrange = mcol.max() - mcol.min()
mstdev = mcol.std()
mvar = mcol.var()

print(mcol)

print("The range of the marks column = {}".format(mrange))
print("The standard deviation of the marks column = {:.2f}".format(mstdev))
print("The variance of the marks column = {:.2f}".format(mvar))

print("\n          CGPA           ")

cgpacol = data['CGPI'].sort_values(ascending=False, ignore_index=True)
cgparange = cgpacol.max() - cgpacol.min()
cgpastdev = cgpacol.std()
cgpavar = cgpacol.var()

print(cgpacol)
print("The range of the CGPA column = {}".format(cgparange))
print("The standard deviation of the CGPA column = {:.2f}".format(cgpastdev))
print("The variance of the CGPA column = {:.2f}".format(cgpavar))