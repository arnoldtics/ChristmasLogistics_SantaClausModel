#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include "Graph.hpp"
#include <iomanip>
#include <fstream>
#include <vector>
#include <tuple>
#include <string>
#include <sys/stat.h> // For checking file existence


using namespace std;

bool file_exists(const string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

// Function to save BFS trajectories to a file (creates it if necessary)
void save_trajectories(const vector<tuple<string, float, int>>& trajectories, const string& filename) {
    // Check if the file exists
    if (file_exists(filename)) {
        cout << "File \"" << filename << "\" already exists. No action taken.\n";
        return;
    }

    ofstream outfile(filename); // Create the file if it doesn't exist
    if (!outfile) {
        cerr << "Error: Unable to create file.\n";
        return;
    }

    outfile << "=============================================\n";
    outfile << "| State Name      | Distance   | Gifts       |\n";
    outfile << "=============================================\n";
    for (const auto& [state, distance, gifts] : trajectories) {
        outfile << "| " << setw(15) << left << state
                << "| " << setw(11) << fixed << setprecision(2) << distance
                << "| " << setw(12) << right << gifts << " |\n";
    }
    outfile << "=============================================\n";

    outfile.close();
    cout << "File \"" << filename << "\" created and trajectories saved.\n";
}

// BFS function with distance and gifts tracking
vector<tuple<string, float, int>> bfs(Graph& G, const string& start_state) {
    string last_state = start_state;
    vector<tuple<string, float, int>> visited_states; // State, distance, gifts
    unordered_set<string> visited;                   // To mark states as visited
    queue<string> to_visit;       // Queue for BFS (states)

    // Initialize
    to_visit.push(start_state);

    // Start BFS
    while (!to_visit.empty()) {
        string current_state = to_visit.front();
        to_visit.pop();

        if (visited.find(current_state) != visited.end()){continue;}
        
        visited.insert(current_state);
        visited_states.push_back({current_state, G.get_distance(current_state, last_state), G.get_gifts(current_state)});
        
        last_state = current_state;

        // Retrieve closest states and use them as neighbors
        vector<string> neighbors = G.closests_states(current_state);
        for (const auto& neighbor : neighbors) {
            if (visited.find(neighbor) == visited.end()) {  // If not visited
                to_visit.push({neighbor});
            }
        }

    }
    return visited_states;
}

int main() {
    Graph G;
    // Construct the graph nodes
    float speed = 300.0; // Speed in km/h
    float time_passed = 0.0;

    construct_graph(G);

    // Perform BFS starting from "Quintana Roo"
    string start_state = "Quintana Roo";
    vector<tuple<string, float, int>> result = bfs(G, start_state);

    // Print BFS traversal distances, gifts, and time passed
    cout << "BFS traversal starting from " << start_state << ":\n";
    
    // Align the headers for the table
    cout << left << setw(15) << "State"
         << setw(15) << "Distance (km)"
         << setw(15) << "Gifts"
         << setw(25) << "Time Passed (hours)" << endl;

    // Iterate through the result and print the information
    for (const auto& [state, distance, gifts] : result) {
        time_passed = distance / speed;

        // Print each state, distance, gifts, and time
        cout << left << setw(15) << state
             << setw(15) << fixed << setprecision(2) << distance
             << setw(15) << gifts
             << setw(25) << fixed << setprecision(2) << time_passed << endl;
    }

    // Save trajectories to a file
    string filename = "trajectories.txt";
    save_trajectories(result, filename);

    return 0;
}