#1
##a
    # Ausnahme = eine Situation, die während der Ausführung eines Programms auftritt und nicht erwartet wird
    # auslösen - raise

def zahl_teilen(zahl1, zahl2):
    if zahl2 == 0:
        raise ZeroDivisionError("Division durch 0 nicht möglich")
    return zahl1 / zahl2

try:
    zahl_teilen(10, 0)
except ZeroDivisionError:
    print("Division durch 0 nicht möglich")

    # behandeln - try/except
    # def zahl_lesen(eingabe):
    #     try:
    #         zahl = int(eingabe)
    #     except ValueError:
    #         print("Die Eingabe ist keine Zahl")
    #     return zahl
    #
    # zahl = zahl_lesen("10")
    # print(zahl)
    # zahl = zahl_lesen("Hallo")
    # print(zahl)

##b
    # Dynamische Typisierung = ein Schema der Typisierung von Programmiersprachen, bei der Typ-Prüfungen (etwa des Datentyps von Variablen) vorrangig zur Laufzeit eines Programms stattfinden
    # >>> a = 1                         # a enthält durch Zuweisung eine ganze Zahl
    # >>> a += 1.0                      # addiert die Gleitkommazahl 1.0 und legt neuen Wert (mit anderem Typ) in a ab
    # >>> a.upper()                     # Scheitert: a ist keine Zeichenkette

#2
##1, JA
x = -1
y = 10 + -x
print(y)

##2, NEIN
# def T:
#     def __init__(self):
#         self.x = 0

##3, JA
x=2
x = 6 if x == 3 else 2

##4, JA
def f(y):
    print("why?")
x = f
f(x)

##5, JA
x,*o,y =1,2,3,4,5
print(x, y)

#3
##a
def is_disarium(n):
    copy = n
    l = []
    while copy != 0:
        l.append(copy % 10)
        copy //= 10
    x = 0
    potenz = len(l)

    def d(x, potenz):
        if potenz >= 1:
            return l[x] ** potenz + d(x + 1, potenz - 1)
        return 0

    return d(x, potenz) == n

print(is_disarium(135))

##b
def selection(l):
    for i in range(len(l)-1):
        idx = i
        for j in range(i+1, len(l)):
            if l[j] < l[idx]:
                idx=j
        l[i], l[idx] = l[idx], l[i]
    print(l)

selection([5, 4, 8, 1, 9])

#4
##a
class Kurs:
    def __init__(self, titel, referent, studenten=None):
        self.titel = titel
        self.referent = referent
        if studenten is None:
            studenten = []
        self.studenten = studenten

    def __str__(self):
        return f"Kurs: {self.titel}\nReferent: {self.referent}\nStudenten: {self.studenten}"

##b
def anzahl_studenten(kurse):
    kurse = filter(lambda kurs: kurs.titel.startswith("a"), kurse)
    return sum(len(kurs.studenten) for kurs in kurse)