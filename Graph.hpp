#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Node.hpp"
#include "Data.hpp"  // Include Data.hpp to access information

using namespace std;

class Graph {
private:
    unordered_map<string, Node> nodes;

    // Convert degrees to radians
    float deg_to_rad(float deg) const {
        return deg * (M_PI / 180.0);
    }

    // Calculate distance between two states using Haversine formula
    float distance(const string& state1, const string& state2) {
        if (nodes.find(state1) == nodes.end() || nodes.find(state2) == nodes.end()) {
            throw invalid_argument("One or both states do not exist in the graph.");
        }

        Node node1 = nodes[state1];
        Node node2 = nodes[state2];

        const float R = 6371.0; // Earth's radius in kilometers

        float lat1 = deg_to_rad(node1.get_latitude());
        float lon1 = deg_to_rad(node1.get_longitude());
        float lat2 = deg_to_rad(node2.get_latitude());
        float lon2 = deg_to_rad(node2.get_longitude());

        float dlat = lat2 - lat1;
        float dlon = lon2 - lon1;
        float a = sin(dlat / 2) * sin(dlat / 2) +
                  cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
        float c = 2 * atan2(sqrt(a), sqrt(1 - a));

        return R * c;
    }

public:
    // Add a node to the graph
    void set_node(const string& name, int gifts, float latitude, float longitude) {
        if (nodes.find(name) == nodes.end()) {
            Node n;
            n.set_gifts(gifts);
            n.set_latitude(latitude);
            n.set_longitude(longitude);
            nodes[name] = n;
        }
    }

    // Get the number of gifts for a state
    int get_gifts(const string& state) const {
        if (nodes.find(state) != nodes.end()) {
            return nodes.at(state).get_gifts();
        }
        return 0;
    }

    // Get the distance between two states
    float get_distance(const string& state1, const string& state2) {
        return distance(state1, state2);
    }

    // Return a list of states ordered by distance to a given state
    vector<string> closests_states(const string& state) {
        vector<pair<string, float>> distances;
        for (const auto& node : nodes) {
            if (node.first != state) {
                distances.push_back({node.first, distance(state, node.first)});
            }
        }

        sort(distances.begin(), distances.end(), [](const pair<string, float>& a, const pair<string, float>& b){return a.second < b.second;});

        vector<string> closest_states;
        for (const auto& d : distances) {
            closest_states.push_back(d.first);
        }
        return closest_states;
    }

};

// Flexible function for constructing a graph
Graph construct_graph(Graph &G) {
    for (const auto& state : information) {
        G.set_node(state.first, state.second.first, state.second.second.first, state.second.second.second);
    }
    return G;
}
