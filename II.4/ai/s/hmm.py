import numpy as np

def predict(tm, px):
    return tm @ px

def update(om, px, obs):
    if obs == "w":
        i = 0
    else:
        i = 1
    px2 = np.multiply(px, om[:, i])
    return px2 / np.sum(px2)

def filter(tm, om, y1t, p0):
    pt = p0
    pl = [pt]
    for t in range(len(y1t)):
        pt_pred = predict(tm, pt)
        pt = update(om, pt_pred, y1t[t])
        pl = pl + [pt]
    return pl

p0 = np.array([0.5, 0.5])

tm = np.array([
    [0.7, 0.2],
    [0.3, 0.8]
])

om = np.array([
    [0.95, 0.05],
    [0.4, 0.6]
])

y1t = ["w", "w", "v", "v"]

result = filter(tm, om, y1t, p0)
print(result)