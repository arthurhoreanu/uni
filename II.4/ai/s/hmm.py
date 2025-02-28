import numpy as np

def predict(tm, px):
    return np.dot(tm, px)

def update(om, px, obs):
    likelihood = om[:, obs]
    px_new = likelihood * px
    return px_new / np.sum(px_new)

def filter(tm, om, y1t, p0):
    px = p0
    for obs in y1t:
        px = predict(tm, px)
        px = update(om, px, 0 if obs == "w" else 1)
    return px

p0 = np.array([0.5, 0.5])

tm = np.array([
    [0.7, 0.3],
    [0.2, 0.8]
])

om = np.array([
    [0.95, 0.05],
    [0.40, 0.60]
])

y1t = ["w", "w", "v", "v"]

result = filter(tm, om, y1t, p0)
print(result)