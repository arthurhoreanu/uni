from itertools import permutations, combinations, combinations_with_replacement
#from more_itertools import distinct_permutations
from math import factorial, perm, comb, log, exp, dist, sqrt
from random import choice, choices, sample, randint,randrange, random

import matplotlib
from matplotlib.pyplot import hist, bar, plot, xticks, yticks, axis, legend, grid, show, title, xlabel, ylabel, figure
matplotlib.use("TkAgg")
#from numpy import mean, var, std, randint, linspace, log, exp, unique, random, random.default_rng()
import numpy as np
from scipy.stats import randint, bernoulli, binom, hypergeom, geom, uniform, norm, expon
# Fur die obigen Klassen aus scipy.stats, werden die Methoden: rvs, pdf, pmf, cdf benutzt.
# Man sei aufmerksam bei der Wahl der Parameter von jeder Verteilung, insbesondere fur loc und scale.

J = 2*[1] + [2] + 2*[3] + [6]
F = [1] + 2*[2] + 2*[3] + [5]

WS_selbeZahl = 0
WS_felixKleinerAlsJenny = 0

E = 0
S = []

for _ in range(1000):
    WJ = sample(J,1)
    WF = sample(F,1)

    if WJ == WF:
        WS_selbeZahl += 1

    if WF < WJ:
        WS_felixKleinerAlsJenny += 1

    S.append(WJ[0] + WF[0])
    E += WJ[0] + WF[0]

print("Die Wahrscheinlichkeit, dass Felix und Jenny die selbe Zahl beim Wurfeln erhalten, ist ",WS_selbeZahl/1000)
print("Die Wahrscheinlichkeit, dass Felix eine kleinere Zahl als Jenny erhalt, ist ", WS_felixKleinerAlsJenny/1000)
#
# #--------------Theoretische Wahrscheinlichkeiten-------------------
# # A: "Jenny und Felix wurfeln dieselbe Zahl"
# # P(A) = P(1) + P(2) + P(3)
# #      = 2/6*1/6 + 1/6*2/6 + 2/6*2/6
# print("Theoretische WS, dass Felix und Jenny die selbe Zahl beim Wurfeln erhalten, ist ",2/6*1/6 + 1/6*2/6 + 2/6*2/6)
#
# # B: "Die Zahl von Felix ist kleiner als die von Jenny
# # P(B) = P(X|1) + P(X|2) + P(X|3) + P(X|6)
# #      = 0*2/6 + 1/6*1/6 + 3/6*2/6 + 1*1/6
# print("Theoretische WS, dass Felix eine kleinere Zahl als Jenny erhalt, ist ",0*2/6 + 1/6*1/6 + 3/6*2/6 + 1*1/6)
#
# # c)
print("Erwartungswert E(S): ",E/1000)
#
# #---------Theoretische WS von S------------
# #mogliche Werte: 2 3 4 5 6 7 8 9 10 11
# # 1,1,2,3,3,6
# # 1,2,2,3,3,5
# #
# #WS 2: 1+1 oder 1+1 --> 2/34
# #WS 3: 1+2 oder 1+2 oder 1+2 oder 1+2 oder 2+1  --> 5/34
# #WS 4: 1+3 oder 1+3 oder 1+3 oder 1+3 oder 2+2 oder 2+2 oder 3+1 oder 3+1  --> 8/34
# #WS 5: 2+3 oder 2+3 oder 3+2 oder 3+2 oder 3+2 oder 3+2  --> 6/34
# #WS 6: 1+5 oder 1+5 oder 3+3 oder 3+3 oder 3+3 oder 3+3  --> 6/34
# #WS 7: 2+5 oder 6+1  --> 2/34
# #WS 8: 3+5 oder 3+5 oder 6+2 oder 6+2  --> 4/34
# #WS 9: 6+3 oder 6+3  --> 2/34
# #WS 10: 0/34
# #WS 11: 6+5  --> 1/34
# listeTheor = [2/34,5/34,8/34,6/34,6/34,2/34,4/34,2/34,1/34]
# #------------------------------------------
#
z, count = np.unique(S, return_counts=True)
#
# Plot relative and theoretical frequencies
bar(z, count / 1000, width=0.9, color="red", edgecolor="black", label="Relative Häufigkeiten")x
title("Relative und theoretische Häufigkeiten der Werte von S")
legend(loc="lower left")  # Add labels before calling legend
show()

# #--------------------------------------------------------
#
# from random import sample
# import numpy as np
# from matplotlib.pyplot import bar, title, xlabel, ylabel, legend, show
#
# # Setup bile în urnă
# urna = ["rosu", "rosu", "rosu", "albastru", "albastru", "verde"]
#
# # Variabile pentru simulare
# num_trials = 1000
# diff_colors = 0  # Număr de extrageri cu bile de culori diferite
# second_red = 0   # Număr de cazuri în care a doua bilă extrasă este roșie
# rosii_totale = []
#
# # Simulare
# for _ in range(num_trials):
#     extragere = sample(urna, 2)  # Extragem două bile fără repunere
#     if extragere[0] != extragere[1]:
#         diff_colors += 1
#     if extragere[1] == "rosu":
#         second_red += 1
#     rosu_count = extragere.count("rosu")  # Numărăm câte bile roșii au fost extrase
#     rosii_totale.append(rosu_count)
#
# # Calculăm frecvențele relative din simulare
# p_diff_colors_sim = diff_colors / num_trials
# p_second_red_sim = second_red / num_trials
# E_rosii_sim = np.mean(rosii_totale)
#
# print(f"Probabilitate din simulare pentru bile de culori diferite: {p_diff_colors_sim}")
# print(f"Probabilitate din simulare ca a doua bilă să fie roșie: {p_second_red_sim}")
# print(f"Valoarea așteptată (Erwartungswert) pentru numărul de bile roșii extrase: {E_rosii_sim}")
#
# # Calcul probabilitate teoretică
# p_diff_colors_teor = (3/6 * 3/5 + 2/6 * 4/5 + 1/6 * 5/5)  # Toate combinațiile posibile
# p_second_red_teor = (3/6 * 2/5 + 2/6 * 3/5 + 1/6 * 3/5)  # Probabilitatea a doua roșie
#
# print(f"Probabilitate teoretică pentru bile de culori diferite: {p_diff_colors_teor}")
# print(f"Probabilitate teoretică ca a doua bilă să fie roșie: {p_second_red_teor}")
#
# # Histogramă: Frecvențele relative vs teoretice pentru numărul de bile roșii
# z, count = np.unique(rosii_totale, return_counts=True)
# frecv_relative = count / num_trials
# teoretic_rosii = [3/15, 9/15, 3/15]  # Probabilitățile pentru 0, 1 sau 2 bile roșii
#
# bar(z, frecv_relative, width=0.9, color="red", label="Simulat")
# bar([0, 1, 2], teoretic_rosii, width=0.6, color="blue", label="Teoretic")
# title("Frecvențe relative și teoretice pentru numărul de bile roșii")
# xlabel("Numărul de bile roșii extrase")
# ylabel("Frecvență")
# legend(loc="upper right")
# show()
#
# #------------------------------------------------------------------
#
# from random import randint
# import numpy as np
# from matplotlib.pyplot import bar, title, xlabel, ylabel, legend, show
#
# # Variabile pentru simulare
# num_trials = 1000
# sum_greater_8 = 0  # Cazurile în care suma > 8
# first_greater = 0  # Cazurile în care primul zar > al doilea
# sume = []
#
# # Simulare
# for _ in range(num_trials):
#     zar1 = randint(1, 6)  # Aruncare zar 1
#     zar2 = randint(1, 6)  # Aruncare zar 2
#     suma = zar1 + zar2
#     if suma > 8:
#         sum_greater_8 += 1
#     if zar1 > zar2:
#         first_greater += 1
#     sume.append(suma)
#
# # Calcul frecvențe relative
# p_sum_greater_8_sim = sum_greater_8 / num_trials
# p_first_greater_sim = first_greater / num_trials
# E_sum_sim = np.mean(sume)
#
# print(f"Probabilitate din simulare că suma > 8: {p_sum_greater_8_sim}")
# print(f"Probabilitate din simulare că primul zar > al doilea: {p_first_greater_sim}")
# print(f"Valoarea așteptată (Erwartungswert) a sumei: {E_sum_sim}")
#
# # Calcul teoretic
# p_sum_greater_8_teor = (5+4+3+2+1)/36  # Numărul cazurilor favorabile / 36
# p_first_greater_teor = (3+3+3+3+3)/36  # Numărul cazurilor favorabile / 36
# print(f"Probabilitate teoretică că suma > 8: {p_sum_greater_8_teor}")
# print(f"Probabilitate teoretică că primul zar > al doilea: {p_first_greater_teor}")
#
# # Histogramă distribuție sumă
# z, count = np.unique(sume, return_counts=True)
# frecv_relative = count / num_trials
# teoretic_sum = [1/36, 2/36, 3/36, 4/36, 5/36, 6/36, 5/36, 4/36, 3/36, 2/36, 1/36]
#
# bar(z, frecv_relative, width=0.9, color="red", label="Simulat")
# bar(range(2, 13), teoretic_sum, width=0.6, color="blue", label="Teoretic")
# title("Distribuția frecvențelor relative și teoretice ale sumei")
# xlabel("Suma zarurilor")
# ylabel("Frecvență")
# legend(loc="upper right")
# show()
#
# # ---------------------------------------
#
# from random import randint
# import numpy as np
# from matplotlib.pyplot import bar, title, xlabel, ylabel, legend, show
#
# # Setup
# num_trials = 1000
# group_size = 23
# days_in_year = 365
#
# # Variabile pentru simulare
# at_least_two_same = 0
# exactly_two_same = 0
# pairs_with_same_birthday = []
#
# # Simulare
# for _ in range(num_trials):
#     birthdays = [randint(1, days_in_year) for _ in range(group_size)]  # Generăm zile de naștere aleatoare
#     unique_birthdays = set(birthdays)
#     duplicates = group_size - len(unique_birthdays)  # Numărăm câte zile de naștere se repetă
#
#     if duplicates > 0:
#         at_least_two_same += 1
#     if duplicates == 1:
#         exactly_two_same += 1
#
#     # Calculăm numărul de perechi care au aceeași zi de naștere
#     pairs = 0
#     for day in unique_birthdays:
#         count = birthdays.count(day)
#         if count > 1:
#             pairs += count * (count - 1) // 2  # Numărul de perechi pentru ziua respectivă
#     pairs_with_same_birthday.append(pairs)
#
# # Frecvențe relative
# p_at_least_two_sim = at_least_two_same / num_trials
# p_exactly_two_sim = exactly_two_same / num_trials
# E_pairs_sim = np.mean(pairs_with_same_birthday)
#
# print(f"Probabilitatea din simulare ca cel puțin două persoane să aibă aceeași zi de naștere: {p_at_least_two_sim}")
# print(f"Probabilitatea din simulare ca exact două persoane să aibă aceeași zi de naștere: {p_exactly_two_sim}")
# print(f"Valoarea așteptată (Erwartungswert) a perechilor cu aceeași zi de naștere: {E_pairs_sim}")
#
# # Calcul teoretic
# p_no_shared_birthday = 1
# for i in range(group_size):
#     p_no_shared_birthday *= (days_in_year - i) / days_in_year
# p_at_least_two_teor = 1 - p_no_shared_birthday
# print(f"Probabilitatea teoretică ca cel puțin două persoane să aibă aceeași zi de naștere: {p_at_least_two_teor}")
#
# # Grafic: Distribuția perechilor cu zile de naștere comune
# z, count = np.unique(pairs_with_same_birthday, return_counts=True)
# frecv_relative = count / num_trials
# bar(z, frecv_relative, width=0.9, color="red", label="Simulat")
# title("Distribuția perechilor cu zile de naștere comune")
# xlabel("Numărul de perechi cu zile de naștere comune")
# ylabel("Frecvență")
# legend(loc="upper right")
# show()
#
# # -------------------------------
#
# from random import randint
# import numpy as np
# from matplotlib.pyplot import bar, title, xlabel, ylabel, legend, show
#
# # Setup
# num_trials = 1000
# group_size = 5
# days_in_year = 365
#
# # Variabile pentru simulare
# all_different_group = 0
# common_birthdays = []
# at_least_one_common = 0
#
# # Simulare
# for _ in range(num_trials):
#     group1 = [randint(1, days_in_year) for _ in range(group_size)]
#     group2 = [randint(1, days_in_year) for _ in range(group_size)]
#
#     # Verificăm dacă toate zilele dintr-un grup sunt diferite
#     if len(set(group1)) == group_size:
#         all_different_group += 1
#
#     # Verificăm zilele comune între grupuri
#     common_days = len(set(group1) & set(group2))  # Intersecția între grupuri
#     if common_days > 0:
#         at_least_one_common += 1
#     common_birthdays.append(common_days)
#
# # Frecvențe relative
# p_all_different_sim = all_different_group / num_trials
# p_at_least_one_common_sim = at_least_one_common / num_trials
# E_common_birthdays_sim = np.mean(common_birthdays)
#
# print(f"Probabilitatea din simulare ca toate zilele dintr-un grup să fie diferite: {p_all_different_sim}")
# print(f"Probabilitatea din simulare ca grupurile să aibă cel puțin o zi comună: {p_at_least_one_common_sim}")
# print(f"Valoarea așteptată (Erwartungswert) a zilelor de naștere comune: {E_common_birthdays_sim}")
#
# # Calcul teoretic
# p_all_different_teor = 1
# for i in range(group_size):
#     p_all_different_teor *= (days_in_year - i) / days_in_year
#
# print(f"Probabilitatea teoretică ca toate zilele dintr-un grup să fie diferite: {p_all_different_teor}")
#
# # Grafic: Distribuția zilelor de naștere comune
# z, count = np.unique(common_birthdays, return_counts=True)
# frecv_relative = count / num_trials
# bar(z, frecv_relative, width=0.9, color="red", label="Simulat")
# title("Distribuția zilelor de naștere comune între grupuri")
# xlabel("Numărul de zile comune între grupuri")
# ylabel("Frecvență")
# legend(loc="upper right")
# show()
#
# # --------------------------------
#
# from random import randint
# import numpy as np
# from matplotlib.pyplot import bar, title, xlabel, ylabel, legend, show
#
# # Setup
# num_trials = 1000
# group_size = 50
# months_in_year = 12
#
# # Variabile pentru simulare
# empty_months_count = []
#
# # Simulare
# for _ in range(num_trials):
#     birthdays = [randint(1, months_in_year) for _ in range(group_size)]
#     empty_months = months_in_year - len(set(birthdays))  # Numărăm lunile fără zile de naștere
#     empty_months_count.append(empty_months)
#
# # Frecvențe relative
# E_empty_months_sim = np.mean(empty_months_count)
#
# print(f"Valoarea așteptată (Erwartungswert) a lunilor fără zile de naștere: {E_empty_months_sim}")
#
# # Grafic: Distribuția lunilor fără zile de naștere
# z, count = np.unique(empty_months_count, return_counts=True)
# frecv_relative = count / num_trials
# bar(z, frecv_relative, width=0.9, color="red", label="Simulat")
# title("Distribuția lunilor fără zile de naștere")
# xlabel("Numărul de luni fără zile de naștere")
# ylabel("Frecvență")
# legend(loc="upper right")
# show()
#
# # ----------------------------
#
# # Alegeri aleatoare:
# # Extrageri fără repunere: sample()
# # Extrageri cu repunere: choices()
#
# # Distribuții comune:
# # Uniformă: random.uniform(a, b)
# # Normală: np.random.normal(mu, sigma, size)
# # Binomială: binom.rvs(n, p, size)
# # Exponențială: np.random.exponential(scale, size)
#
# randint(a, b)  # Un număr întreg între a și b inclusiv
# choices(population, weights=None, k=1)  # Alegere cu repunere
# sample(population, k)  # Alegere fără repunere
#
# random()  # Număr uniform în [0, 1)
# uniform(a, b)  # Număr uniform în [a, b]
#
# from random import choices
#
# urn = ["rosu", "albastru", "verde"]
# bile_aleatoare = choices(urn, weights=[3, 2, 1], k=5)  # Extragem 5 bile cu probabilități diferite
#
# np.random.randint(1, 7, size=1000)  # 1000 numere între 1 și 6
# np.random.normal(mean, std, size=1000)  # 1000 numere dintr-o distribuție normală
# np.random.exponential(scale, size=1000)  # 1000 numere dintr-o distribuție exponențială
#
# np.mean(lista)  # Media
# np.var(lista)  # Varianța
# np.std(lista)  # Abaterea standard
#
# import numpy as np
#
# # Generăm 1000 de aruncări de monedă (0 = "față", 1 = "spate")
# aruncari = np.random.choice([0, 1], size=1000, p=[0.5, 0.5])
# print("Proporție spate:", np.mean(aruncari))
#
# # ---------------------------
#
# from random import choices
# import numpy as np
# from matplotlib.pyplot import hist, title, xlabel, ylabel, show
#
# # Setup
# urna = ["rosu", "albastru", "verde"]
# proportii = [3/6, 2/6, 1/6]  # Probabilități pentru fiecare culoare
# num_trials = 1000  # Numărul de simulări
# bile_extrase = 10  # Numărul de bile extrase
#
# # Simulare
# num_rosii = []  # Lista pentru a stoca numărul de bile roșii din fiecare simulare
# for _ in range(num_trials):
#     extrageri = choices(urna, weights=proportii, k=bile_extrase)  # Extragem bilele
#     num_rosii.append(extrageri.count("rosu"))  # Numărăm bilele roșii
#
# # Calcul Erwartungswert
# E_rosii_sim = np.mean(num_rosii)
# print(f"Valoarea așteptată (Erwartungswert) pentru numărul de bile roșii: {E_rosii_sim}")
#
# # Probabilitatea ca exact 4 bile să fie roșii
# prob_4_rosii_sim = num_rosii.count(4) / num_trials
# print(f"Probabilitatea din simulare ca exact 4 bile să fie roșii: {prob_4_rosii_sim}")
#
# # Histogramă
# hist(num_rosii, bins=range(0, bile_extrase+2), density=True, color="red", edgecolor="black", alpha=0.7)
# title("Distribuția numărului de bile roșii (Simulare)")
# xlabel("Numărul de bile roșii")
# ylabel("Frecvență relativă")
# show()
#
# # -------------------------
#
# from random import choices
# import numpy as np
# from matplotlib.pyplot import hist, title, xlabel, ylabel, show
#
# # Setup
# moneda = ["cap", "pajura"]
# proportii = [0.7, 0.3]  # Probabilitățile pentru fiecare față
# num_trials = 1000  # Numărul de simulări
# aruncari = 20  # Numărul de aruncări per simulare
#
# # Simulare
# num_cap = []  # Lista pentru a stoca numărul de "cap" din fiecare simulare
# for _ in range(num_trials):
#     rezultate = choices(moneda, weights=proportii, k=aruncari)  # Aruncăm moneda
#     num_cap.append(rezultate.count("cap"))  # Numărăm câte "cap" au apărut
#
# # Calcul Erwartungswert
# E_cap_sim = np.mean(num_cap)
# print(f"Valoarea așteptată (Erwartungswert) pentru numărul de 'cap': {E_cap_sim}")
#
# # Probabilitatea ca exact 15 să fie "cap"
# prob_15_cap_sim = num_cap.count(15) / num_trials
# print(f"Probabilitatea din simulare ca exact 15 să fie 'cap': {prob_15_cap_sim}")
#
# # Histogramă
# hist(num_cap, bins=range(0, aruncari+2), density=True, color="blue", edgecolor="black", alpha=0.7)
# title("Distribuția numărului de 'cap' (Simulare)")
# xlabel("Numărul de 'cap'")
# ylabel("Frecvență relativă")
# show()
#
# # --------------------------
#
# from random import choices
# import numpy as np
# from matplotlib.pyplot import hist, title, xlabel, ylabel, show
#
# # Setup
# echipa = ["Alice", "Bob", "Carol", "Dan", "Emma"]
# proportii = [1/5] * 5  # Fiecare are aceeași probabilitate
# num_trials = 1000  # Numărul de simulări
# selectii = 8  # Numărul de selecții per simulare
#
# # Simulare
# num_alice = []  # Lista pentru a stoca numărul de selecții ale lui Alice
# for _ in range(num_trials):
#     rezultate = choices(echipa, weights=proportii, k=selectii)  # Selectăm angajații
#     num_alice.append(rezultate.count("Alice"))  # Numărăm câte selecții are Alice
#
# # Calcul Erwartungswert
# E_alice_sim = np.mean(num_alice)
# print(f"Valoarea așteptată (Erwartungswert) pentru selecțiile lui Alice: {E_alice_sim}")
#
# # Probabilitatea ca Alice să fie selectată exact de 3 ori
# prob_3_alice_sim = num_alice.count(3) / num_trials
# print(f"Probabilitatea din simulare ca Alice să fie selectată exact de 3 ori: {prob_3_alice_sim}")
#
# # Histogramă
# hist(num_alice, bins=range(0, selectii+2), density=True, color="green", edgecolor="black", alpha=0.7)
# title("Distribuția selecțiilor lui Alice (Simulare)")
# xlabel("Numărul de selecții ale lui Alice")
# ylabel("Frecvență relativă")
# show()
#
# # --------------------------
#
# from random import sample
# import numpy as np
# from matplotlib.pyplot import bar, grid, show, title, xlabel, ylabel, legend
#
# # Configurare
# total_red = 6
# total_blue = 4
# num_draws = 3
# num_simulations = 10000
#
# # Simulare extrageri
# results = []
# for _ in range(num_simulations):
#     urn = ["red"] * total_red + ["blue"] * total_blue
#     draws = sample(urn, num_draws)
#     results.append(draws.count("red"))
#
# # Probabilități experimentale
# P_X_1_2 = sum(1 for x in results if x in {1, 2}) / num_simulations
# P_X_3 = results.count(3) / num_simulations
# P_X_0 = results.count(0) / num_simulations
# E_X = sum(results) / num_simulations
#
# print("P(X ∈ {1, 2}):", P_X_1_2)
# print("P(X = 3):", P_X_3)
# print("P(X = 0):", P_X_0)
# print("E(X):", E_X) #erwartungswert
#
# # Probabilități teoretice
# def comb(n, k):
#     from math import factorial
#     return factorial(n) // (factorial(k) * factorial(n - k))
#
# def hypergeom(success, total_red, total_blue, draws):
#     total = total_red + total_blue
#     return comb(total_red, success) * comb(total_blue, draws - success) / comb(total, draws)
#
# P_X_0_theoretical = hypergeom(0, total_red, total_blue, num_draws)
# P_X_3_theoretical = hypergeom(3, total_red, total_blue, num_draws)
#
# print("Teoretic P(X = 0):", P_X_0_theoretical)
# print("Teoretic P(X = 3):", P_X_3_theoretical)
#
# # Histogramă
# z, count = np.unique(results, return_counts=True)
# bar(z, count / num_simulations, width=0.9, edgecolor="black")
# title("Histogramă frecvențe relative ale lui X")
# xlabel("Număr bile roșii extrase")
# ylabel("Frecvență relativă")
# grid(axis="y", linestyle="--", alpha=0.7)
# show()
#
#
#
# #2
#
# from random import sample
# import numpy as np
# from matplotlib.pyplot import bar, grid, show, title, xlabel, ylabel
#
# # Configurare
# urne = [1, 2, 3, 4, 5]
# num_draws = 3
# num_simulations = 10000
#
# # Simulare extrageri
# results = []
# for _ in range(num_simulations):
#     draws = sample(urne, num_draws)
#     results.append(sum(draws))
#
# # Probabilități experimentale
# P_X_6_7 = sum(1 for x in results if x in {6, 7}) / num_simulations
# P_X_10 = results.count(10) / num_simulations
# P_X_15 = results.count(15) / num_simulations
# E_X = sum(results) / num_simulations
#
# print("P(X ∈ {6, 7}):", P_X_6_7)
# print("P(X = 10):", P_X_10)
# print("P(X = 15):", P_X_15)
# print("E(X):", E_X)
#
# # Probabilități teoretice
# def comb(n, k):
#     from math import factorial
#     return factorial(n) // (factorial(k) * factorial(n - k))
#
# def hypergeom_sum(success, urne, draws):
#     from itertools import combinations
#     total = list(combinations(urne, draws))
#     count_success = sum(1 for comb in total if sum(comb) == success)
#     return count_success / len(total)
#
# P_X_6_theoretical = hypergeom_sum(6, urne, num_draws)
# P_X_10_theoretical = hypergeom_sum(10, urne, num_draws)
#
# print("Teoretic P(X = 6):", P_X_6_theoretical)
# print("Teoretic P(X = 10):", P_X_10_theoretical)
#
# # Histogramă
# z, count = np.unique(results, return_counts=True)
# bar(z, count / num_simulations, width=0.9, edgecolor="black")
# title("Histogramă frecvențe relative ale lui X")
# xlabel("Suma numerelor extrase")
# ylabel("Frecvență relativă")
# grid(axis="y", linestyle="--", alpha=0.7)
# show()
# [09:57, 16/01/2025] Mălina DUMITRESCU: #3
#
# from random import sample
# import numpy as np
# from matplotlib.pyplot import bar, grid, show, title, xlabel, ylabel
#
# # Configurare
# urne = ["red"] * 4 + ["blue"] * 3 + ["green"] * 3
# num_draws = 2
# num_simulations = 10000
#
# # Simulare extrageri
# results = []
# for _ in range(num_simulations):
#     draws = sample(urne, num_draws)
#     results.append(len(set(draws)))
#
# # Probabilități experimentale
# P_X_1 = results.count(1) / num_simulations
# P_X_2 = results.count(2) / num_simulations
# P_X_1_2 = sum(1 for x in results if x in {1, 2}) / num_simulations
# E_X = sum(results) / num_simulations
#
# print("P(X = 1):", P_X_1)
# print("P(X = 2):", P_X_2)
# print("P(X ∈ {1, 2}):", P_X_1_2)
# print("E(X):", E_X)
#
# # Probabilități teoretice
# def comb(n, k):
#     from math import factorial
#     return factorial(n) // (factorial(k) * factorial(n - k))
#
# def hypergeom_colors(distinct_colors, urne, draws):
#     if distinct_colors == 1:
#         total = comb(10, 2)
#         same_color = comb(4, 2) + comb(3, 2) + comb(3, 2)
#         return same_color / total
#     elif distinct_colors == 2:
#         total = comb(10, 2)
#         diff_colors = comb(4, 1) * comb(3, 1) + comb(4, 1) * comb(3, 1) + comb(3, 1) * comb(3, 1)
#         return diff_colors / total
#     else:
#         return 0
#
# P_X_1_theoretical = hypergeom_colors(1, urne, num_draws)
# P_X_2_theoretical = hypergeom_colors(2, urne, num_draws)
#
# print("Teoretic P(X = 1):", P_X_1_theoretical)
# print("Teoretic P(X = 2):", P_X_2_theoretical)
#
# # Histogramă
# z, count = np.unique(results, return_counts=True)
# bar(z, count / num_simulations, width=0.9, edgecolor="black")
# title("Histogramă frecvențe relative ale lui X")
# xlabel("Număr culori distincte extrase")
# ylabel("Frecvență relativă")
# grid(axis="y", linestyle="--", alpha=0.7)
# show()
#
#
# #4
#
# from random import sample
# import numpy as np
# from matplotlib.pyplot import bar, grid, show, title, xlabel, ylabel
#
# # Configurare
# urne = list(range(1, 11))
# num_draws = 3
# num_simulations = 10000
#
# # Simulare extrageri
# results = []
# for _ in range(num_simulations):
#     draws = sample(urne, num_draws)
#     results.append(np.prod(draws))
#
# # Probabilități experimentale
# P_X_greater_100 = sum(1 for x in results if x > 100) / num_simulations
# P_X_less_50 = sum(1 for x in results if x < 50) / num_simulations
# P_X_equal_60 = results.count(60) / num_simulations
# E_X = sum(results) / num_simulations
#
# print("P(X > 100):", P_X_greater_100)
# print("P(X < 50):", P_X_less_50)
# print("P(X = 60):", P_X_equal_60)
# print("E(X):", E_X)
#
# # Probabilități teoretice
# def comb(n, k):
#     from math import factorial
#     return factorial(n) // (factorial(k) * factorial(n - k))
#
# def hypergeom_product(condition, urne, draws):
#     from itertools import combinations
#     total = list(combinations(urne, draws))
#     if condition == ">100":
#         count = sum(1 for comb in total if np.prod(comb) > 100)
#     elif condition == "=60":
#         count = sum(1 for comb in total if np.prod(comb) == 60)
#     else:
#         count = 0
#     return count / len(total)
#
# P_X_greater_100_theoretical = hypergeom_product(">100", urne, num_draws)
# P_X_equal_60_theoretical = hypergeom_product("=60", urne, num_draws)
#
# print("Teoretic P(X > 100):", P_X_greater_100_theoretical)
# print("Teoretic P(X = 60):", P_X_equal_60_theoretical)
#
# # Histogramă
# z, count = np.unique(results, return_counts=True)
# bar(z, count / num_simulations, width=0.9, edgecolor="black")
# title("Histogramă frecvențe relative ale lui X")
# xlabel("Produsul numerelor extrase")
# ylabel("Frecvență relativă")
# grid(axis="y", linestyle="--", alpha=0.7)
# show()
#
# #5
#
# from random import choice
# import numpy as np
# from matplotlib.pyplot import bar, grid, show, title, xlabel, ylabel
#
# # Configurare
# urna1 = ["red"] * 5 + ["blue"] * 5
# urna2 = ["green"] * 6 + ["yellow"] * 4
# num_simulations = 10000
#
# # Simulare extrageri
# results = []
# for _ in range(num_simulations):
#     draw1 = choice(urna1)
#     draw2 = choice(urna2)
#     results.append(1 if draw1 == draw2 else 0)
#
# # Probabilități experimentale
# P_X_0 = results.count(0) / num_simulations
# P_X_1 = results.count(1) / num_simulations
# P_X_greater_0 = sum(1 for x in results if x > 0) / num_simulations
# E_X = sum(results) / num_simulations
#
# print("P(X = 0):", P_X_0)
# print("P(X = 1):", P_X_1)
# print("P(X > 0):", P_X_greater_0)
# print("E(X):", E_X)
#
# # Probabilități teoretice
# def comb(n, k):
#     from math import factorial
#     return factorial(n) // (factorial(k) * factorial(n - k))
#
# def theoretical_probabilities():
#     P_X_1 = 0  # Nu există culori comune între urne
#     P_X_0 = 1  # Toate extragerile vor avea culori diferite
#     return P_X_0, P_X_1
#
# P_X_0_theoretical, P_X_1_theoretical = theoretical_probabilities()
#
# print("Teoretic P(X = 0):", P_X_0_theoretical)
# print("Teoretic P(X = 1):", P_X_1_theoretical)
#
# # Histogramă
# z, count = np.unique(results, return_counts=True)
# bar(z, count / num_simulations, width=0.9, edgecolor="black")
# title("Histogramă frecvențe relative ale lui X")
# xlabel("Număr bile colorate la fel")
# ylabel("Frecvență relativă")
# grid(axis="y", linestyle="--", alpha=0.7)
# show()
#
#
# #6
#
# from random import sample
# import numpy as np
# from matplotlib.pyplot import bar, grid, show, title, xlabel, ylabel
#
# # Configurare
# urne = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# num_draws = 2
# num_simulations = 10000
#
# # Simulare extrageri
# results = []
# for _ in range(num_simulations):
#     draws = sample(urne, num_draws)
#     results.append(abs(draws[0] - draws[1]))
#
# # Probabilități experimentale
# P_X_0 = results.count(0) / num_simulations
# P_X_3_5 = sum(1 for x in results if x in {3, 5}) / num_simulations
# P_X_greater_5 = sum(1 for x in results if x > 5) / num_simulations
# E_X = sum(results) / num_simulations
#
# print("P(X = 0):", P_X_0)
# print("P(X ∈ {3, 5}):", P_X_3_5)
# print("P(X > 5):", P_X_greater_5)
# print("E(X):", E_X)
#
# # Probabilități teoretice
# def comb(n, k):
#     from math import factorial
#     return factorial(n) // (factorial(k) * factorial(n - k))
#
# def theoretical_probabilities():
#     total_pairs = comb(9, 2)
#     P_X_0 = comb(3, 2) / total_pairs  # Perechi din aceeași categorie
#     P_X_3 = (2 * comb(3, 1) * comb(3, 1)) / total_pairs  # Diferența 3 între culori diferite
#     return P_X_0, P_X_3
#
# P_X_0_theoretical, P_X_3_theoretical = theoretical_probabilities()
#
# print("Teoretic P(X = 0):", P_X_0_theoretical)
# print("Teoretic P(X = 3):", P_X_3_theoretical)
#
# # Histogramă
# z, count = np.unique(results, return_counts=True)
# bar(z, count / num_simulations, width=0.9, edgecolor="black")
# title("Histogramă frecvențe relative ale lui X")
# xlabel("Diferența absolută între numerele bilelor extrase")
# ylabel("Frecvență relativă")
# grid(axis="y", linestyle="--", alpha=0.7)
# show()