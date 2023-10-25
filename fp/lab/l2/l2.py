liste = [70, 23, 32, 24, 47, 70, 12, 42]

def wiederholung(liste):
    wiederholung = []
    for item in liste:
        if item not in wiederholung:
            wiederholung.append(item)
    print(wiederholung)

def symmetrie(liste):
    cnt = 0
    for i in range(len(liste)):
        for j in range(i + 1, len(liste)):
            str_i = str(liste[i])
            str_j = str(liste[j])
            if str_i == str_j[::-1]:
                cnt += 1
    print(cnt)

def konkatenation(liste):
    str_liste = [str(element) for element in liste]
    str_liste.sort(reverse=True)
    kon = ''.join(str_liste)
    print(kon)

def schlussel(liste):
    element1 = liste[0]
    schlussel = [element1]
    for element in liste[1:]:
        schlussel.append(element+element1)
    print(schlussel)


def beziehung(liste, beziehung):
    output = []
    beziehung = beziehung.replace("=", "==")
    beziehung = beziehung.replace("/", "//")
    for zahl in liste:
        x = zahl // 10
        y = zahl % 10
        if eval(beziehung) == True:
            output.append(zahl)
    print(output)

def domino(liste):
    max_domino = []
    current_domino = [liste[0]]
    for i in range(1, len(liste)):
        if liste[i] // 10 == current_domino[-1] % 10:
            current_domino.append(liste[i])
        else:
            if len(current_domino) > len(max_domino):
                max_domino = current_domino
            current_domino = [liste[i]]
    if len(current_domino) > len(max_domino):
        max_domino = current_domino

    print(max_domino)

def kgv(from_zahl, to_zahl, liste):
    def ggt(a, b):
        while b:
            a, b = b, a%b
        return a
    def kgv_formel(a, b):
        return a * b // ggt(a,b)
    output = liste[from_zahl]
    for i in range(from_zahl+1, to_zahl+1):
        output=kgv_formel(output, i)
    print(output)

wiederholung(liste)
symmetrie(liste)
konkatenation(liste)
schlussel(liste)
beziehung(liste, "x=2*y")
domino(liste)
kgv(1, 5, liste)