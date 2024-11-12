#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Node.hpp"
#include "Data.hpp"
using namespace std;

class Graph{
    private:
        unordered_map<string, Node> nodes;

        // Euclidean distance between two states
        float distance(string state1, string state2){
            Node node1 = nodes[state1];
            Node node2 = nodes[state2];
            return sqrt(((node1.get_latitude() - node2.get_latitude()), 2) + pow((node1.get_longitude() - node2.get_longitude()), 2));
        }

    public:
        // Creating a node
        void set_node(string name, int gifts, float latitude, float longitude){
            if (nodes.find(name) == nodes.end()){
                Node n;
                n.set_gifts(gifts);
                n.set_latitude(latitude);
                n.set_longitude(longitude);
                nodes[name] = n;
            }
        }

        // Function that given a state returns a list of the other 31 states
        // ordered by the shortest distance
        vector<string> closests_states(string state){
            vector<pair<string, float>> distances;
            for (auto const& node : nodes){
                if (node.first != state){
                    distances.push_back({node.first, distance(state, node.first)});
                }
            }
            sort(distances.begin(), distances.end(), [](const pair<string, float>& a, const pair<string, float>& b){
                return a.second < b.second;
            });

            vector<string> closest_states;
            for (int i = 0; i < distances.size(); i++){
                closest_states.push_back(distances[i].first);
            }
            return closest_states;
        }
};

// Function for starting the graph
Graph construct_graph(Graph &G){
    for (const auto state : information){
        G.set_node(state.first, state.second.first, state.second.second.first, state.second.second.second);
    }
}