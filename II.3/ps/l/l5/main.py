from scipy.stats import norm
import numpy
import matplotlib.pyplot as plt
from scipy.stats import uniform, expon

def a1():
    mu = 199
    sigma = 3
    N = 1000

    # a) Simuliere 1000 Daten and löse die Mittel
    Daten = norm.rvs(mu, sigma, N)
    im_Mittel = numpy.mean(Daten)
    print(f"Im Mittel: {im_Mittel:.3f} g")

    # b) Wahrscheinlichkeiten
    # P(X < 195)
    wenigerAls195 = norm.cdf(195, mu, sigma)
    print(f"{wenigerAls195:.4f}")

    # P(195 <= X <= 198)
    zwischen195Und198 = norm.cdf(198, mu, sigma) - norm.cdf(195, mu, sigma)
    print(f"{zwischen195Und198:.4f}")

    # P(X > 195)
    groeserAls195 = 1 - norm.cdf(195, mu, sigma)
    print(f"{groeserAls195:.4f}")

    # c) Histogramm und Dichtefunktion
    # Histogramm der relativen Häufigkeiten
    plt.hist(Daten, bins=16, density=True, edgecolor="black", label="rel. Häufigkeiten")

    # Dichtefunktion der Normalverteilung
    x = numpy.linspace(min(Daten), max(Daten), 500)  # Werte für die x-Achse
    dichte = norm.pdf(x, mu, sigma)  # Dichtefunktion der Normalverteilung
    plt.plot(x, dichte, color="red", label="Dichtefunktion N(μ,σ²)")

    # Diagramm beschriften
    plt.xlabel("Abgefüllte Menge (g)")
    plt.ylabel("Relative Häufigkeit")
    plt.title("Histogramm und Dichtefunktion")
    plt.legend()
    plt.grid()
    plt.show()

    # (d) Anzahl der Daten in jeder Klasse
    Häufigkeiten, Klassen = numpy.histogram(Daten, bins=16)
    print("Häufigkeiten in jeder Klasse:")
    print(Häufigkeiten)

#a1()

def a2():
    L = 1 / 12
    N = 1000
    Daten = expon.rvs(loc=0, scale=1 / L, size=N)
    lambda_val = 1 / 12

    # (a) Simuliere N = 1000 Daten
    Daten = expon.rvs(loc=0, scale=1 / lambda_val, size=N)

    # Durchschnittliche Druckzeit
    durchschnittliche_druckzeit = numpy.mean(Daten)
    print(f"Durchschnittliche Druckzeit: {durchschnittliche_druckzeit:.2f} Sekunden")

    # (b) Histogramm und Dichtefunktion
    plt.hist(Daten, bins=15, density=True, edgecolor="black", label="rel. Häufigkeiten")

    # Diagramm beschriften
    plt.xlabel("Druckzeit T (Sekunden)")
    plt.ylabel("Relative Häufigkeit")
    plt.title("Histogramm und Dichtefunktion")
    plt.legend()
    plt.grid()
    plt.show()

    # (c) Wahrscheinlichkeiten berechnen und vergleichen
    P_T_kleiner_20 = expon.cdf(20, loc=0, scale=1 / lambda_val)
    P_T_groesser_10 = 1 - expon.cdf(10, loc=0, scale=1 / lambda_val)
    P_T_zwischen_10_und_30 = expon.cdf(30, loc=0, scale=1 / lambda_val) - expon.cdf(10, loc=0, scale=1 / lambda_val)

    print(f"P(T < 20): {P_T_kleiner_20:.4f}")
    print(f"P(T > 10): {P_T_groesser_10:.4f}")
    print(f"P(10 < T < 30): {P_T_zwischen_10_und_30:.4f}")

    # (d) Datenanzahl in Klassen zählen
    Häufigkeiten, Klassen = numpy.histogram(Daten, bins=15)
    print("Häufigkeiten in jeder Klasse:")
    print(Häufigkeiten)

    # (e) Verteilungsfunktion auf [0, 10]
    x_cdf = numpy.linspace(0, 10, 500)
    cdf = expon.cdf(x_cdf, loc=0, scale=1 / lambda_val)

    plt.plot(x_cdf, cdf, color="blue", label="Verteilungsfunktion Exp(λ)")
    plt.xlabel("Druckzeit T (Sekunden)")
    plt.ylabel("F(T)")
    plt.title("Verteilungsfunktion der Exp(1/12)")
    plt.grid()
    plt.legend()
    plt.show()

#a2()

def a3():
    # Parameter
    N = 10000  # Anzahl der Simulationen
    gruppen_groesse = 6  # Anzahl der Personen in einer Gruppe
    monate = 12  # Anzahl der Monate im Jahr

    # Simulation des Wettprozesses
    def simuliere_geburtstagswette(gruppen_groesse, monate, N):
        gewinne = 0
        for _ in range(N):
            geburtstage = numpy.random.randint(1, monate + 1, gruppen_groesse)  # Zufällige Monate für Geburtstage
            if len(geburtstage) > len(set(geburtstage)):  # Prüfen, ob mindestens zwei Personen denselben Monat haben
                gewinne += 1
        return gewinne / N  # Schätzung von p (Wahrscheinlichkeit des Gewinns)

    # Geschätzte Gewinnwahrscheinlichkeit
    p_gewinn = simuliere_geburtstagswette(gruppen_groesse, monate, N)

    # Durchschnittlicher Gewinn/Verlust pro Wette
    durchschnittlicher_gewinn_verlust = p_gewinn * 6 - (1 - p_gewinn) * 6
    print(f"Geschätzte Wahrscheinlichkeit für Gewinn (p): {p_gewinn:.4f}")
    print(f"Durchschnittlicher Gewinn/Verlust pro Wette: {durchschnittlicher_gewinn_verlust:.2f} €")

#a3()

def a4():

    # Parameter
    N = 10000  # Anzahl der Zufallswerte für die Simulation

    # (1a) Gleichverteilung X ∼ Unif[-2,2]
    a, b = -2, 2  # Intervallgrenzen der Gleichverteilung
    x_unif = numpy.linspace(-3, 3, 500)  # Werte für die x-Achse
    dichte_unif = uniform.pdf(x_unif, loc=a, scale=b - a)  # Dichtefunktion
    verteilung_unif = uniform.cdf(x_unif, loc=a, scale=b - a)  # Verteilungsfunktion

    # Grafische Darstellung der Gleichverteilung
    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    plt.plot(x_unif, dichte_unif, label="Dichtefunktion (PDF)")
    plt.title("Dichtefunktion für X ∼ Unif[-2,2]")
    plt.grid()
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(x_unif, verteilung_unif, label="Verteilungsfunktion (CDF)", color="orange")
    plt.title("Verteilungsfunktion für X ∼ Unif[-2,2]")
    plt.grid()
    plt.legend()
    plt.show()

    # (1b) Exponentialverteilung X ∼ Exp(2)
    lambda_wert = 2  # λ-Wert der Exponentialverteilung
    x_exp = numpy.linspace(0, 4, 500)  # Werte für die x-Achse
    dichte_exp = expon.pdf(x_exp, scale=1 / lambda_wert)  # Dichtefunktion
    verteilung_exp = expon.cdf(x_exp, scale=1 / lambda_wert)  # Verteilungsfunktion

    # Grafische Darstellung der Exponentialverteilung
    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    plt.plot(x_exp, dichte_exp, label="Dichtefunktion (PDF)")
    plt.title("Dichtefunktion für X ∼ Exp(2)")
    plt.grid()
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(x_exp, verteilung_exp, label="Verteilungsfunktion (CDF)", color="orange")
    plt.title("Verteilungsfunktion für X ∼ Exp(2)")
    plt.grid()
    plt.legend()
    plt.show()

    # (2) Schätzung von P(1 < X < 1.5)
    # Gleichverteilung
    sim_unif = uniform.rvs(loc=a, scale=b - a, size=N)  # Simulation von Zufallswerten
    P_unif_sim = numpy.mean((sim_unif > 1) & (sim_unif < 1.5))  # Schätzung durch Simulation
    P_unif_theo = uniform.cdf(1.5, loc=a, scale=b - a) - uniform.cdf(1, loc=a, scale=b - a)  # Theoretischer Wert

    # Exponentialverteilung
    sim_exp = expon.rvs(scale=1 / lambda_wert, size=N)  # Simulation von Zufallswerten
    P_exp_sim = numpy.mean((sim_exp > 1) & (sim_exp < 1.5))  # Schätzung durch Simulation
    P_exp_theo = expon.cdf(1.5, scale=1 / lambda_wert) - expon.cdf(1, scale=1 / lambda_wert)  # Theoretischer Wert

    print(f"Gleichverteilung: P(1 < X < 1.5) (Simuliert): {P_unif_sim:.4f}, Theoretisch: {P_unif_theo:.4f}")
    print(f"Exponentialverteilung: P(1 < X < 1.5) (Simuliert): {P_exp_sim:.4f}, Theoretisch: {P_exp_theo:.4f}")

    # (3) Schätzung von E(X) und V(X)
    # Erwartungswert und Varianz für Gleichverteilung
    E_unif_sim = numpy.mean(sim_unif)
    V_unif_sim = numpy.var(sim_unif)

    # Erwartungswert und Varianz für Exponentialverteilung
    E_exp_sim = numpy.mean(sim_exp)
    V_exp_sim = numpy.var(sim_exp)

    print(f"Gleichverteilung: E(X) (Simuliert): {E_unif_sim:.4f}, V(X) (Simuliert): {V_unif_sim:.4f}")
    print(f"Exponentialverteilung: E(X) (Simuliert): {E_exp_sim:.4f}, V(X) (Simuliert): {V_exp_sim:.4f}")

#a4()

def a5():
    