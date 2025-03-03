import numpy as np
import matplotlib
matplotlib.use("TkAgg")  # Backend for macOS
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
import pandas as pd
from sklearn.cluster import KMeans
from sklearn import tree
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.model_selection import cross_val_score
from sklearn.tree import DecisionTreeClassifier

# 0. Clustering
# Data load (first column, the IDs, is ignored)
data = np.loadtxt("csv/faithful.csv", delimiter=",", skiprows=1, usecols=(1, 2))

# print(f"Dimensiunea datelor: {data.shape}")
# print("Primele 5 rânduri:\n", data[:5])

errors = []
K_values = range(1, 10)

for k in K_values:
    kmeans = KMeans(n_clusters=k, random_state=42, n_init=10)
    kmeans.fit(data)
    errors.append(kmeans.inertia_)  # eroors = sum of the distances squared till entroid

# plt.figure(figsize=(8, 5))
# plt.plot(K_values, errors, marker='o', linestyle='-', color='b')
# plt.xlabel("Număr de Clustere (K)")
# plt.ylabel("Eroare (Inertia)")
# plt.title("K-Means: Alegerea optimă a lui K (Metoda Elbow)")
# plt.grid()
# plt.show()

# 1. Pandas
df = pd.read_csv("csv/iris.csv")
# print(df)
accx = df.loc[:,"SepalLength"]
# print(accx)
acc = df.iloc[:,1:4]
# print(acc)
df.iloc[0:5,:]
df.loc[0:5,["SepalLength", "SepalWidth"]]
df.loc[df.SepalLength < 5,:]
df.loc[df.SepalLength < 0,"SepalLength"] = 0
# print(df)

# 2. Entscheidungsbäume in Python
df = pd.read_csv("csv/iris.csv")
X = df.iloc[:,1:5]
y = df.iloc[:,5]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=1/3)

clf = tree.DecisionTreeClassifier()
clf = clf.fit(X_train, y_train)

pred = clf.predict(X_test)
# print(np.mean(pred==y_test))

# Aufgabe 1

dat = pd.read_csv("csv/pima_indians_diabetes.csv", header=None)

X = dat.iloc[:, :-1]
y = dat.iloc[:, -1]

def cv(clf, features, classes, n):
    scores = cross_val_score(clf, features, classes, cv=n)
    return np.mean(scores)

clf = DecisionTreeClassifier(random_state=42)
accuracy = cv(clf, X, y, 10)

print(accuracy)