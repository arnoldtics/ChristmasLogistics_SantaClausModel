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
The `Node` class represents a state in the context of our project. Each `Node` encapsulates key attributes related to a state (name, gifts (given by the number of habitants between 0 and 19 years old), latitude, and longitude (both in degrees)) and provides getter and setter methods for managing these attributes. The main purpose of the `Node` class is to serve as a foundational element in our graph representation, where nodes correspond to states with specific geographical and logistical properties.


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
The model introduces three free parameters:

- Start_state: The state where Santa's journey begins.
- Traveling: The constant speed of Santa's sleigh in km/s.
- Delivering: The number of gifts delivered per second

Due to Mexico's geographical position, the starting point was chosen as Quintana Roo, as it is the first state to experience nighttime during Christmas Eve.

The values for Traveling and Delivering were determined through extensive testing of the model. Given that Christmas Eve lasts approximately 13 hours in Mexico, this was set as the time limit for completing all deliveries. The initial conditions that ensured a successful delivery were 0.833 km/s for traveling speed and 1400 gifts delivered per second.

This result is remarkable because it demonstrates that Santa's mission is feasible within this context. A speed of 0.833 km/s translates to 3000 km/h, or approximately Mach 2.83. The airplane MiG-25 Foxbat is able to reach this speed (a supersonic interceptor and reconnaissance aircraft that is among the fastest military aircraft to enter service. Designed by the Soviet Union).

The delivery rate of 1400 gifts per second can be justified as follows: Santa Claus is not alone; he is accompanied by his team of Christmas Elves. Assuming 56,000 elves, divided into 40 teams (each with 1400 elves), the delivery rate is achievable. If each elf in a team delivers one gift in 20 seconds and prepares the next gift in another 20 seconds, with perfect synchronization, they can collectively deliver 1400 gifts per second in each state.

After running this simulation (delivering and traveling among the path finded by our graph exploration), the following information was plotted.

![Plotting the amount of gifts delivered each second](img/Plotting%20the%20amount%20of%20gifts%20delivered%20each%20second.png)

![Plotting distance traveled each second](img/Plotting%20distance%20traveled%20each%20second.png)


## Testing and execution

To reproduce this simulation or modify it with different parameters, follow these steps:

1. Set the Mexican state where Santa's journey will start by editing line 92 of main.cpp.
2. Compile the program into an executable file named main.exe. You can either use a CMake file or compile it manually.
3. Run the main.exe file. This will generate a trajectories.txt file containing the simulation results.
4. Execute visualization.py to generate the plots. If you wish to modify the Traveling or Delivering parameters, edit lines 51 and 52 of visualization.py.

## Conclusions

# Project Overview  

This project deepened our understanding of **graph theory** and **problem-solving in simulated environments**. We tackled the challenge of grounding a fictional scenario by incorporating realistic variables such as graph density, real-world location mapping, sleigh speed, and the number of gifts.  

A major obstacle was calculating distances between coordinates, which we resolved using the **Haversine formula**. Overcoming this and other challenges allowed us to effectively integrate real-world variables into our solutions.  

Some of the skills developed during the realization of the project were:  
- **Efficient Simulations:** Implemented in **C++** for fast and reliable model testing.  
- **Data Management:** Organized data into structured files for easier analysis.  
- **Visualization:** Developed tools to interpret results clearly and communicate findings.  

Overall, this project honed our technical skills and enhanced our ability to think critically and creatively in applying theory to fictional problems.  


## References
