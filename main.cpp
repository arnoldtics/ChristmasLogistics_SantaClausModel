#include <iostream>
#include <queue>
#include <unordered_set>
#include "Graph.hpp"

using namespace std;

// BFS function
vector<string> bfs(Graph& G, const string& start_state) {
    vector<string> visited_states;           // Order of visited states
    unordered_set<string> visited;           // To mark states as visited
    queue<string> to_visit;                  // Queue for BFS
    
    // Initialize
    to_visit.push(start_state);
    visited.insert(start_state);

    // Start BFS
    while (!to_visit.empty()) {
        string current_state = to_visit.front();
        to_visit.pop();
        visited_states.push_back(current_state);

        // Retrieve closest states and use them as neighbors
        vector<string> neighbors = G.closests_states(current_state);
        for (const auto& neighbor : neighbors) {
            if (visited.find(neighbor) == visited.end()) {  // If not visited
                to_visit.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    return visited_states;
}

int main() {
    Graph G;
    
    // Construct the graph nodes from Data
    construct_graph(G);

    // Perform BFS starting from Aguascalientes
    string start_state = "Aguascalientes";
    vector<string> result = bfs(G, start_state);

    // Print BFS
    cout << "BFS traversal starting from " << start_state << ":\n";
    for (const auto& state : result) {
        cout << state << endl;
    }

    return 0;
}
