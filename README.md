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
- Implement each node of the graph with the corresponding information for the model: coordinates and the number of Christmas gifts.
- Implement a search algorithm to find an efficient path for Santa's route in the graph
- Use constant speed to create a visualization of Santa's trajectory across the entire graph
- Determine the initial conditions of the model in order to make Christmas happen.

## Mathematical and computational tools
1. Graph Representation:
Implement classes in C++ for nodes and the graph. C++ is an ideal language for creating fast object-oriented structures and algorithms.
2. Pathfinding Algorithms:
Implement the A* algorithm for route optimization. The heuristic will be chosen based on the results from the testing phase. This part will also be implemented in C++.
3. Physics Modeling:
In the initial approach, we will assume a constant speed for Santa's sleigh and use Euclidean geometry to calculate the distances between nodes.
4. Visualization
The visualization should display Santa's route across the graph. This will be implemented in Python, as it provides excellent tools for creating visualizations easily.
