from pomegranate import *

print("This is Karan Taneja's code. SAP - 500084399.")

guest = DiscreteDistribution({'A': 1. / 3, 'B': 1. / 3, 'C': 1. / 3})

prize = DiscreteDistribution({'A': 1. / 3, 'B': 1. / 3, 'C': 1. / 3})

monty = ConditionalProbabilityTable([['A', 'A', 'A', 0.0], ['A', 'A', 'B', 0.5], ['A', 'A', 'C', 0.5], ['A', 'B', 'A', 0.0], ['A', 'B', 'B', 0.0], ['A', 'B', 'C', 1.0], ['A', 'C', 'A', 0.0], ['A', 'C', 'B', 1.0], ['A', 'C', 'C', 0.0], ['B', 'A', 'A', 0.0], ['B', 'A', 'B', 0.0], ['B', 'A', 'C', 1.0], ['B', 'B', 'A', 0.5], [
                                    'B', 'B', 'B', 0.0], ['B', 'B', 'C', 0.5], ['B', 'C', 'A', 1.0], ['B', 'C', 'B', 0.0], ['B', 'C', 'C', 0.0], ['C', 'A', 'A', 0.0], ['C', 'A', 'B', 1.0], ['C', 'A', 'C', 0.0], ['C', 'B', 'A', 1.0], ['C', 'B', 'B', 0.0], ['C', 'B', 'C', 0.0], ['C', 'C', 'A', 0.5], ['C', 'C', 'B', 0.5], ['C', 'C', 'C', 0.0]], [guest, prize])

d1 = State(guest, name="guest")
d2 = State(prize, name="prize")
d3 = State(monty, name="monty")

network = BayesianNetwork(
    "Solving the Monty Hall Problem With Bayesian Networks")
network.add_states(d1, d2, d3)
network.add_edge(d1, d3)
network.add_edge(d2, d3)
network.bake()
gate = input("Enter the Gate to choose: [A, B, C]: ")
beliefs = network.predict_proba({'guest': gate})

beliefs = map(str, beliefs)

print(" n ".join("{} t {}".format(state.name, belief)
      for state, belief in zip(network.states, beliefs)))

guest
prize
{
    "class": "Distribution",
    "dtype": "str",
    "name": "DiscreteDistribution",
    "parameters": [{"A": 0.3333333333333333, "B": 0.3333333333333333, "C": 0.3333333333333333}],
}

monty
{
    "class": "Distribution",
    "dtype": "str", "name":
    "DiscreteDistribution",
    "parameters": [{"C": 0.49999999999999983, "A": 0.0, "B": 0.49999999999999983}],
}
