liste = [2, 6, 3, 9, 2, 3, 5, 7]

def ggt(x, y):
    while y!=0:
        x, y = y, x%y
    return x

def relativ_prim(x, y):
    return ggt(x, y) == 1

def langste_relativ_prim(liste):
    laufende = []
    langste = []
    for i in range(len(liste) - 1):
        if (relativ_prim(liste[i], liste[i + 1])):
            laufende.append(liste[i])
        else:
            if len(laufende) > len(langste):
                langste = laufende
                laufende = []
    if relativ_prim(liste[-1], liste[-2]):
        laufende.append(liste[-1])
    if len(laufende) > len(langste):
        langste = laufende

    return langste

print(langste_relativ_prim(liste))