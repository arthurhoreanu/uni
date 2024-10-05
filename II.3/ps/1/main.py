from itertools import permutations, combinations, combinations_with_replacement
import math
import random

#print(perm(4,4))
#print(perm(4,2))

#1

#a
wordOne = "sicher"
# count = 0
# permutationsList = permutations(wordOne)
# for perm in permutationsList:
#     count+=1
#     print(''.join(perm))
# print(count)

#b
# randomPerm = random.sample(wordOne, len(word))
# print(''.join(randomPerm))
# randomPerm = random.sample(wordOne, len(word))
# print(''.join(randomPerm))

#c
# varTwo = permutations(wordOne, 2)
# count = 0
# for perm in varTwo:
#     count += 1
#     print(''.join(perm))
# print(count)

#d
wordTwo='MATHE'
# varCount=math.perm(len(wordTwo), len(wordTwo))
# print(varCount)

#e
# comobinationList=combinations(wordTwo, 3)
# count = 0
# for comb in comobinationList:
#     count += 1
#     print(''.join(comb))
#
# #f
# print(count)

#2
# from more_itertools import distinct_permutations
#
# M=list(distinct_permutations("AABB"))
# print(M)
# m = len(M)
# print("Anzahl Permutationen von AABB mit Wiederholung:", m)
#
# for p in distinct_permutations("1112"):
#     print("".join(p))
# n = len(p)
# print("Anzahl Permutationen von 1112 mit Wiederholung:", n)

#3
# M = list(combinations_with_replacement("ABC",2))
# print("Alle Kombinationen von ABC je 2, mit Wierderholung")
# print(M)
# k = len(M)
# print("Anzahl Kombinationen von ABC je 2 mit Wierderholung", k)

#4
