import random

loc_A, loc_B = (0, 0), (1, 0)
GRID_WIDTH = 5
GRID_HEIGHT = 5

class Thing:
    """This represents any physical object that can appear in an Environment.
    You subclass Thing to get the things you want. Each thing can have a
    .__name__  slot (used for output only)."""

    def __repr__(self):
        return '<{}>'.format(getattr(self, '__name__', self.__class__.__name__))

    def is_alive(self):
        """Things that are 'alive' should return true."""
        return hasattr(self, 'alive') and self.alive

    def show_state(self):
        """Display the agent's internal state. Subclasses should override."""
        print("I don't know how to show_state.")

    def display(self, canvas, x, y, width, height):
        """Display an image of this Thing on the canvas."""
        # Do we need this?
        pass

class Agent(Thing):
    """An Agent is a subclass of Thing with one required slot,
    .program, which should hold a function that takes one argument, the
    percept, and returns an action. (What counts as a percept or action
    will depend on the specific environment in which the agent exists.)
    Note that 'program' is a slot, not a method. If it were a method,
    then the program could 'cheat' and look at aspects of the agent.
    It's not supposed to do that: the program can only look at the
    percepts. An agent program that needs a model of the world (and of
    the agent itself) will have to build and maintain its own model.
    There is an optional slot, .performance, which is a number giving
    the performance measure of the agent in its environment."""
    def __init__(self, program):
        self.program = program

def TraceAgent(agent):
    """Wrap the agent's program to print its input and output. This will let
    you see what the agent is doing in the environment."""
    old_program = agent.program

    def new_program(percept):
        action = old_program(percept)
        print('{} perceives {} and does {}'.format(agent, percept, action))
        return action
    agent.program = new_program
    return agent

def ReflexVacuumAgent():
    """A reflex agent for the two-state vacuum environment. [Figure 2.8]"""
    def program(percept):
        location, status = percept
        if status == 'Dirty':
            return 'Suck'
        elif location == loc_A:
            return 'Right'
        elif location == loc_B:
            return 'Left'
    return Agent(program)

# def ReflexVacuumAgent():
#     """A reflex agent that operates in an NxM grid."""
#
#     def program(percept):
#         location, status = percept
#         if status == 'Dirty':
#             return 'Suck'
#         x, y = location
#         moves = []
#         if x > 0:
#             moves.append('Left')
#         if x < GRID_WIDTH - 1:
#             moves.append('Right')
#         if y > 0:
#             moves.append('Down')
#         if y < GRID_HEIGHT - 1:
#             moves.append('Up')
#         return random.choice(moves)
#     return Agent(program)

def ModelBasedVacuumAgent():
    """An agent that keeps track of what locations are clean or dirty."""
    model = {loc_A: None, loc_B: None}

    def program(percept):
        """Same as ReflexVacuumAgent, except if everything is clean, do NoOp."""
        location, status = percept
        model[location] = status
        if model[loc_A] == model[loc_B] == 'Clean':
            return 'NoOp'
        elif status == 'Dirty':
            return 'Suck'
        elif location == loc_A:
            return 'Right'
        elif location == loc_B:
            return 'Left'
    return Agent(program)

# def ModelBasedVacuumAgent():
#     """An agent that keeps track of a grid environment."""
#     model = {}
#     def program(percept):
#         location, status = percept
#         model[location] = status
#
#         if all(state == 'Clean' for state in model.values()):
#             return 'NoOp'
#
#         if status == 'Dirty':
#             return 'Suck'
#
#         x, y = location
#         moves = [('Right', (x + 1, y)), ('Left', (x - 1, y)), ('Up', (x, y + 1)), ('Down', (x, y - 1))]
#
#         valid_moves = []
#
#         for move, loc in moves:
#             if loc not in model:
#                 valid_moves.append(move)
#             elif model[loc] == 'Dirty':
#                 valid_moves.append(move)
#
#         return random.choice(valid_moves) if valid_moves else 'NoOp'
#
#     return Agent(program)

class Environment:
    """Abstract class representing an Environment. 'Real' Environment classes
    inherit from this. Your Environment will typically need to implement:
        percept:           Define the percept that an agent sees.
        execute_action:    Define the effects of executing an action.
                           Also update the agent.performance slot.
    The environment keeps a list of .things and .agents (which is a subset
    of .things). Each agent has a .performance slot, initialized to 0.
    Each thing has a .location slot, even though some environments may not
    need this."""

    def __init__(self):
        self.things = []
        self.agents = []

    def thing_classes(self):
        return []  # List of classes that can go into environment

    def percept(self, agent):
        """Return the percept that the agent sees at this point. (Implement this.)"""
        raise NotImplementedError

    def execute_action(self, agent, action):
        """Change the world to reflect this action. (Implement this.)"""
        raise NotImplementedError

    def default_location(self, thing):
        """Default location to place a new thing with unspecified location."""
        return None

    def exogenous_change(self):
        """If there is spontaneous change in the world, override this."""
        pass

    def step(self):
        """Run the environment for one time step. If the
        actions and exogenous changes are independent, this method will
        do. If there are interactions between them, you'll need to
        override this method."""
        actions = []
        for agent in self.agents:
            actions.append(agent.program(self.percept(agent)))
        for (agent, action) in zip(self.agents, actions):
            self.execute_action(agent, action)
        self.exogenous_change()

    def run(self, steps=1000):
        """Run the Environment for given number of time steps."""
        for step in range(steps):
            self.step()

    def list_things_at(self, location, tclass=Thing):
        """Return all things exactly at a given location."""
        return [thing for thing in self.things
                if thing.location == location and isinstance(thing, tclass)]

    def some_things_at(self, location, tclass=Thing):
        """Return true if at least one of the things at location
        is an instance of class tclass (or a subclass)."""
        return self.list_things_at(location, tclass) != []

    def add_thing(self, thing, location=None):
        """Add a thing to the environment, setting its location. For
        convenience, if thing is an agent program we make a new agent
        for it. (Shouldn't need to override this.)"""
        if not isinstance(thing, Thing):
            thing = Agent(thing)
        if thing in self.things:
            print("Can't add the same thing twice")
        else:
            thing.location = location if location is not None else self.default_location(thing)
            self.things.append(thing)
            if isinstance(thing, Agent):
                thing.performance = 0
                self.agents.append(thing)

    def delete_thing(self, thing):
        """Remove a thing from the environment."""
        try:
            self.things.remove(thing)
        except ValueError as e:
            print(e)
            print("  in Environment delete_thing")
            print("  Thing to be removed: {} at {}".format(thing, thing.location))
            print("  from list: {}".format([(thing, thing.location) for thing in self.things]))
        if thing in self.agents:
            self.agents.remove(thing)

class TrivialVacuumEnvironment(Environment):

    """This environment has two locations, A and B. Each can be Dirty
    or Clean. The agent perceives its location and the location's
    status. This serves as an example of how to implement a simple
    Environment."""

    def __init__(self):
        super().__init__()
        self.status = {loc_A: random.choice(['Clean', 'Dirty']),
                       loc_B: random.choice(['Clean', 'Dirty'])}

    def percept(self, agent):
        """Returns the agent's location, and the location status (Dirty/Clean)."""
        return (agent.location, self.status[agent.location])

    def execute_action(self, agent, action):
        """Change agent's location and/or location's status; track performance.
        Score 10 for each dirt cleaned; -1 for each move."""
        if action == 'Right':
            agent.location = loc_B
            agent.performance -= 1
        elif action == 'Left':
            agent.location = loc_A
            agent.performance -= 1
        elif action == 'Suck':
            if self.status[agent.location] == 'Dirty':
                agent.performance += 10
            self.status[agent.location] = 'Clean'

    def default_location(self, thing):
        """Agents start in either location at random."""
        return random.choice([loc_A, loc_B])


class GridVacuumEnvironment(Environment):
    """Vacuum environment expanded to an NxM grid."""

    def __init__(self, width=3, height=3):
        super().__init__()
        self.width = width
        self.height = height
        self.status = {(x, y): random.choice(['Clean', 'Dirty']) for x in range(width) for y in range(height)}

    def percept(self, agent):
        """Returns the agent's location and the location status (Dirty/Clean)."""
        return (agent.location, self.status[agent.location])

    def execute_action(self, agent, action):
        """Change agent's location and/or clean the dirt."""
        x, y = agent.location

        if action == 'Right' and x < self.width - 1:
            agent.location = (x + 1, y)
            agent.performance -= 1
        elif action == 'Left' and x > 0:
            agent.location = (x - 1, y)
            agent.performance -= 1
        elif action == 'Up' and y < self.height - 1:
            agent.location = (x, y + 1)
            agent.performance -= 1
        elif action == 'Down' and y > 0:
            agent.location = (x, y - 1)
            agent.performance -= 1
        elif action == 'Suck':
            if self.status[agent.location] == 'Dirty':
                agent.performance += 10
            self.status[agent.location] = 'Clean'

    def default_location(self, thing):
        """Agents start at a random location in the grid."""
        return (random.randint(0, self.width - 1), random.randint(0, self.height - 1))

a = ReflexVacuumAgent()
a.program((loc_A, 'Clean'))
a.program((loc_B, 'Clean'))
a.program((loc_A, 'Dirty'))
a.program((loc_A, 'Dirty'))

grid_env = GridVacuumEnvironment(width=GRID_WIDTH, height=GRID_HEIGHT)
grid_agent = TraceAgent(ModelBasedVacuumAgent())
grid_env.add_thing(grid_agent, grid_env.default_location(grid_agent))
grid_env.run(10)

e = TrivialVacuumEnvironment()
e.add_thing(TraceAgent(ModelBasedVacuumAgent()))
e.run(5)