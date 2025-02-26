import matplotlib
import numpy as np
import heapq
import math
import matplotlib.pyplot as plt
matplotlib.use('TkAgg')

def distance(x, y):
    return (((x[0] - y[0])) ** 2 + ((x[1] - y[1]) ** 2))

class Map:
    def __init__(self, m: np.ndarray) -> None:
        self.m = m

    def neighbors(self, cell):
        nrow, ncol = m.shape
        x, y = cell
        nb = []
        if x > 0:
            if m[x - 1, y] == 0:
                nb = nb + [(x - 1, y)]
        if x < (nrow - 1):
            if m[x + 1, y] == 0:
                nb = nb + [(x + 1, y)]
        if y > 0:
            if m[x, y - 1] == 0:
                nb = nb + [(x, y - 1)]
        if y < (ncol - 1):
            if m[x, y + 1] == 0:
                nb = nb + [(x, y + 1)]
        return nb

class PriorityQueue:
    def __init__(self):
        self.elements = []

    def empty(self):
        return len(self.elements) == 0

    def put(self, item, priority):
        heapq.heappush(self.elements, (priority, item))

    def get(self):
        return heapq.heappop(self.elements)[1]

class Stack:
    def __init__(self):
        self.elements = []

    def empty(self):
        return len(self.elements) == 0

    def put(self, x):
        self.elements.append(x)

    def get(self):
        return self.elements.pop()


def dfs(map: Map, start, goal):
    stack = Stack()
    stack.put(start)
    came_from = {start: None}
    while not stack.empty():
        current = stack.get()
        if current == goal:
            return make_path(came_from, start, goal)
        for neighbor in map.neighbors(current):
            if neighbor not in came_from:
                stack.put(neighbor)
                came_from[neighbor] = current
    return None

def make_path(came_from, start, goal):
    path = []
    current = goal
    while current is not None:
        path.append(current)
        current = came_from[current]
    path.reverse()
    return path

def astar(map: Map, start, goal):
    pq = PriorityQueue()
    pq.put(start, 0)
    came_from = {start: None}
    cost_so_far = {start: 0}
    while not pq.empty():
        current = pq.get()
        if current == goal:
            return make_path(came_from, start, goal)
        for neighbor in map.neighbors(current):
            new_cost = cost_so_far[current] + 1
            if neighbor not in cost_so_far or new_cost < cost_so_far[neighbor]:
                cost_so_far[neighbor] = new_cost
                priority = new_cost + distance(neighbor, goal)
                pq.put(neighbor, priority)
                came_from[neighbor] = current
    return None

def plot_map(m, path=None):
    plt.imshow(m, cmap="inferno", origin="upper")
    if path:
        x, y = zip(*path)
        plt.plot(y, x, color="deepskyblue", linewidth=2)
    plt.show()

m = np.array(
    [[0, 1, 0, 0, 0, 0, 0],
     [0, 1, 0, 1, 0, 0, 1],
     [0, 1, 0, 1, 0, 1, 0],
     [0, 1, 0, 1, 0, 0, 0],
     [0, 0, 0, 1, 1, 0, 0],
     [0, 0, 0, 1, 1, 0, 0]])
mm = Map(m)
print(mm.neighbors((4, 1)))
start = (0, 0)
goal = (5, 6)
print("DFS Path:", dfs(mm, start, goal))
print("A* Path:", astar(mm, start, goal))
path = astar(mm, start, goal)
plot_map(m, path)