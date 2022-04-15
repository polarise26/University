import pandas as pd
import matplotlib.pyplot as plt
import statistics
import numpy as np

data = pd.read_excel(
    r"C:\Users\kannu\PycharmProjects\applstatslab\venv\exp1\Demo.xlsx")

dtype = ["nominal", "n s interval", "s interval", "ordinal", "ordinal"]

print("Names are a nominal data type, its central tendency is mode. Mode:",
      statistics.mode(data["Name"])+".")

data[["Marks"]].plot(kind='hist', bins=[0, 20, 40, 60, 80,
                     100], rwidth=0.95, color='slateblue')
plt.xlabel('Marks')
plt.ylabel('Number of Students')
plt.show()
print("Marks are a non skewed interval data type, its central tendency is mean. Mean:",
      str(statistics.mean(data['Marks']))+".")

data[["CGPI"]].plot(kind='hist', bins=[0, 2, 4, 6, 8, 10], rwidth=0.95, color='aquamarine')
plt.xlabel('CGPI')
plt.ylabel('Number of Students')
plt.show()
ccgpi = statistics.median(data['CGPI'])
print("CGPI is a skewed interval data type, its central tendency is median. Median:", str(ccgpi)+".")

qual = {"Great": 1, "Good": 2, "Average": 3, "Poor": 4}
data["Qual"] = np.where(data["Quality of Assignment"] == "Great", 1, np.where(data["Quality of Assignment"] == "Good", 2, np.where(data["Quality of Assignment"] == "Average", 3, np.where(data["Quality of Assignment"] == "Poor", 4, 5))))
data["Qual"].median()
print("Quality of Assignment is an ordinal data type, its central tendency is median. Median:", str(data["Qual"].median())+".")

data["CGPI"].fillna(value=ccgpi, inplace=True)
data.loc[len(data.index)] = dtype
print(data)