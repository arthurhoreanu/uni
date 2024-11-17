import random
from collections import Counter

import numpy
from random import randrange

from matplotlib import pyplot as plt
from matplotlib.pyplot import bar, show, grid, legend, xticks

def simulate_urn_draws(num_simulations=10000):
    favorable_A = favorable_B = favorable_AB = 0  # Counters for conditions A, B, and A ∩ B
    for _ in range(num_simulations):
        draw = random.sample(["r", "b", "g"], counts=[6, 4, 6], k=3)  # Simulate drawing 3 balls
        red_present = 'r' in draw  # Condition A: At least one red ball
        same_color = len(set(draw)) == 1  # Condition B: All balls are the same color

        # Update counters based on outcomes
        if red_present:
            favorable_A += 1
        if same_color:
            favorable_B += 1
        if red_present and same_color:
            favorable_AB += 1

    # Estimating probabilities
    p_A = favorable_A / num_simulations
    p_B = favorable_B / num_simulations
    p_AB = favorable_AB / num_simulations
    p_B_given_A = p_AB / p_A if p_A > 0 else 0  # Conditional probability P(B|A)

    return p_A, p_B, p_AB, p_B_given_A

def theoretical_simulate_urn_draws():
    return 1-(10*9*8)/(16*15*14)

print("A1.1:", simulate_urn_draws())
print("2:", theoretical_simulate_urn_draws())

def histogramm():
    N = 2000
    daten = [randrange(1, 7) for _ in range(N)]
    #print ( daten )
    z, count = numpy . unique(daten, return_counts=True)
    d = dict([(z[i], count[i]/N) for i in range(0, 6)])
    print(d)
    bar(z, count/N, width=0.9, color="red", edgecolor="black", label="relative Haufigkeiten")
    D = dict([(k, 1/6) for k in range(1, 7)])
    bar(D.keys(), D.values(), width=0.7, color="blue", edgecolor="black", label=".....")
    legend(loc="lower left")
    xticks(range(0, 7))
    grid()
    show()

# print("A2:", histogramm())

# import numpy as np
# import matplotlib.pyplot as plt
# import random
#
# def count_sum_prob(s):
#     total_outcomes = 6 * 6 * 6
#     count = 0
#     for die1 in range(1, 7):  # Values 1 through 6
#         for die2 in range(1, 7):
#             for die3 in range(1, 7):
#                 if die1 + die2 + die3 == s:
#                     count += 1
#     return count / total_outcomes
#
# def find_most_probable_sum():
#     possible_sums = range(3, 19)  # Possible sums for three six-sided dice
#     probabilities = {s: count_sum_prob(s) for s in possible_sums}
#     max_probability = max(probabilities.values())
#     most_probable_sums = [s for s, prob in probabilities.items() if prob == max_probability]
#     return most_probable_sums, max_probability
#
# def simulate_dice_sum_game(N=1000):
#     sums = [sum(random.choices(range(1, 7), k=3)) for _ in range(N)]  # Dice with values 1 through 6
#     unique_sums, counts = np.unique(sums, return_counts=True)
#     rel_frequencies = counts / N
#
#     # Theoretical probabilities
#     possible_sums = range(3, 19)
#     theoretical_probs = [count_sum_prob(s) for s in possible_sums]
#
#     # Plotting
#     plt.bar(unique_sums, rel_frequencies, width=0.9, color='red', edgecolor='black', label="Simulated Frequencies")
#     plt.bar(possible_sums, theoretical_probs, width=0.7, color='blue', edgecolor='black', label="Theoretical Frequencies")
#     plt.legend(loc="upper right")
#     plt.grid()
#     plt.show()
#
#     return unique_sums, rel_frequencies
#
# # Find the most probable sum(s) and their theoretical probability
# most_probable_sums, max_prob = find_most_probable_sum()
# print(f"Most probable sum(s): {most_probable_sums} with theoretical probability {max_prob:.4f}")
#
# # Run the simulation and get simulated results
# unique_sums, rel_frequencies = simulate_dice_sum_game()
#
# # Compare the most probable sum(s) to the simulation results
# for sum_value in most_probable_sums:
#     sim_freq = rel_frequencies[np.where(unique_sums == sum_value)][0]
#     print(f"Sum: {sum_value}, Simulated Probability: {sim_freq:.4f}, Theoretical Probability: {max_prob:.4f}")

def a4():
    import random; import numpy
    c1,c2,a1,a2=0,0,0,0
    N=10000
    A= list(range(1,21))
    for _ in range(N):
        i = numpy.random.randint(len(A))
        v=A[i]
        c1=c1+(v%2)
        c2=c2+((v%2)==0)
        a1=a1+(v%2)*((v%3)==0);
        a2=a2+((v%2)==0)*(6<=v and v<=10)
    p1=a1/c1
    p2=a2/c2
    p3=c1/N
    print("Aus den Simulationen")
    print(f"p1={p1:.6f}")
    print(f"p2={p2:.6f}")
    print(f"p3={p3:.6f}")

a4()

def birthday_simulation(N=10000):
    favorable = 0
    for _ in range(N):
        birthdays = [random.randint(1, 12) for _ in range(5)]  # Random months for 5 people
        counts = Counter(birthdays)
        if list(counts.values()).count(2) == 1 and list(counts.values()).count(1) == 3:
            favorable += 1
    probability = favorable / N
    return probability

print("A5:", birthday_simulation())