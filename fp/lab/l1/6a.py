def main():
    liste = [2, 3, 10, 10, 0]
    produkt = 1
    cnt = 0

    for i in range(len(liste)):
        if liste[i] != 0:
            produkt *= liste[i]

    while produkt > 1:
        if produkt % 10 == 0:
            cnt += 1
        produkt //= 10

    print(cnt)

main()