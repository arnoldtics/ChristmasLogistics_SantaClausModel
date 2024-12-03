# ChristmasLogistics_SantaClausModel

## Description
A graph-based model to simulate Santa Claus's gift delivery on Christmas Eve.

## Author and Contact
- Arnoldo Fernando Chue Sánchez: arnoldwork20@gmail.com
- Diego Maldonado Castro: diegomaldonadocastro1805@gmail.com
- Ana Paola Carreón Hernández: anapcahe@gmail.com

## License
GNU General Public License v3.0

## Affiliation
Final project for the Modeling and Simulation 2025-1 class, designed and developed at the National Autonomous University of Mexico (UNAM), specifically at its National School of Higher Studies, Morelia Campus (ENES Morelia). This project is an integral component of the Bachelor's in Information Technologies for Science curriculum.

## Introduction
Every year on Christmas Eve, Santa Claus embarks on a magical journey, flying across the night sky in his sleigh pulled by eight reindeer, tasked with delivering gifts to children all around the world. It's a feat that seems impossible—visiting every single house in just one night, spreading joy and wonder across the globe. Yet, through the magic of Christmas and a little help from clever logistics, Santa always finds a way.

This project simulates Santa Claus's gift delivery logistics on Christmas Eve using graph theory. The primary goal is to model and optimize Santa’s route to ensure that all gifts are delivered on time to every single house. By leveraging graph-based algorithms, the simulation addresses complex logistical challenges, such as minimizing travel time, or finding the most efficient paths across various regions. Through this model, we explore how Santa can accomplish this seemingly impossible task in a single night, combining elements of pathfinding, optimization, and real-world constraints.

## Objectives

- Represent the delivery points for Santa's route with a fully connected graph.
- Start with 32 nodes: each one represents a state of Mexico.
- Implement each node of the graph with the corresponding information for the model: coordinates of tha captial and the number of Christmas gifts.
- Implement a search algorithm to find an efficient path for Santa's route in the graph
- Use constant speed and a constant of gifts deliverd to create a visualization of Santa's journey across the country.
- Determine the initial conditions of the model in order to prove if Christmas could happen.

## Mathematical and computational tools
1. Graph Representation:
Implement classes in C++ for nodes and the graph. C++ is an ideal language for creating fast object-oriented structures and algorithms.
2. Pathfinding Algorithms:
Implement the graph explorations algorithms for route optimization. The heuristics will be chosen based on the results from the testing phase. This part will also be implemented in C++.
3. Physics Modeling:
In the initial approach, we will assume a constant speed for Santa's sleigh, determine a constant of gifts delivered per second, and use the Haversine formula to calculate the distances between nodes.
4. Visualization
The visualization should display Santa's route across the graph. This will be implemented in Python, as it provides excellent tools for creating visualizations easily.

## Development of the model

### Implementation of Nodes

### Graph definition
Through Graph.hpp we manage a collection of states (nodes) with attributes like gifts, latitude, and longitude. It provides methods to add nodes, retrieve the number of gifts for a state, calculate distances between states using the Haversine formula, and list states ordered by proximity to a given state. The construct_graph function initializes the graph using external data, ensuring each state is added with its corresponding information.

1. **Harvesine Formula**:
### BFS Exploration

Through the use of the properties graph, a BFS-like algorithm was implemented to perform graph exploration. A BFS follows these steps:

1. **Exploration**: While the queue is not empty:
   1.1. Dequeue a node from the queue and visit it (e.g., print its value).  
   1.2. For each unvisited neighbor of the dequeued node:  
       1.2.1. Enqueue the neighbor into the queue.  
       1.2.2. Mark the neighbor as visited.

2. **Termination**: Repeat step 1.2 until the queue is empty.
   
## Results

## Conclusions

## References
