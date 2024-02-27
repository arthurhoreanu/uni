def prim(n):
    if n <= 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def langste(liste):
    max_len = 0
    start = 0
    laufende_len = 0

    for i in range(len(liste)):
        for j in range(i + 1, len(liste)):
            if prim(liste[i] + liste[j]):
                laufende_len += 1
            else:
                break

        if laufende_len > max_len:
            max_len = laufende_len
            start = i
        laufende_len = 0

    if max_len == 0:
        return []

    return liste[start:start + max_len]

liste = [1, 2, 3, 5, 7, 8, 13]
print(langste(liste))
