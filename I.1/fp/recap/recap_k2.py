#1
##a
    # Klasse = Blaupause für ein Objekt, definiert die Eigenschaften (Attribute) und Verhaltensweisen (Methoden) eines Objekts
    # Objekt = konkrete Instanz einer Klasse, Es hat alle Eigenschaften und Verhaltensweisen, die in der Klasse definiert sind

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def say_hello(self):
        print(f"Hallo, mein Name ist {self.name}.")

##b
    # Monkey Patching = Technik, mit der das Verhalten eines Codeabschnitts zur Laufzeit dynamisch aktualisiert wird

import math
def square(x):
    return x * x
print(square(2))
def square_patched(x):
    if x < 0:
        return -x * -x
    return x * x
math.sqrt = square_patched
print(square_patched(2))
print(square_patched(-2))

#2
##1, JA
def f():
    print("ok")
def f():
    print("ok but why?")

##2, JA
class T:
    x = 10
    def __init__(self):
        self.y = 0

##3, JA
x=1
y = x++1

##4, JA
d = {1: 2}
print(d.get(1))

##5, JA
x, _ = 1, 2
print(x)

#3
##a
def double_factorial(n):
    def factorial(n):
        while(n>1):
            return n*factorial(n-1)
        return 1
    if n>1:
        return factorial(n)*factorial(n-1)
    return 1

print(double_factorial(3))

##b
def insert(l):
    for i in range(1, len(l)):
        idx = i-1
        el = l[i]
        while idx >= 0 and el < l[idx]:
            l[idx+1] = l[idx]
            idx = idx-1
        l[idx+1]=el
    print(l)

insert([5, 9, 1, 2])

#4
##a
class OnlineShop:
    def __init__(self, name, customers):
        self.name = name
        if customers is None:
            customers = []
        self.customers = customers

    def __str__(self):
        return f"Nume: {self.name}\nClienti: {self.customers}"

##b
def max_anzahl(shops):
    customers_count = [len(shop.customers) for shop in shops]
    return max(shops, key=lambda shop: customers_count[shops.index(shop)])