#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <vector>

using namespace std;

vector<set<pair<int, int>>> remove_degree_one_nodes(vector<set<pair<int, int>>> &graph) {
    vector<set<pair<int, int>>> new_graph(graph);

    // Initialize a queue to store nodes with degree 1
    queue<int> q;

    // Initialize a list to keep track of nodes with degree 1
    vector<int> degree_one_nodes;

    // Initialize a list to keep track of whether a node has been visited
    vector<bool> visited(graph.size(), false);

    // Find nodes with degree 1 and add them to the queue
    for (int node = 0; node < graph.size(); ++node) {
        if (graph[node].size() == 1) {
            q.push(node);
            degree_one_nodes.push_back(node);
            visited[node] = true;
        }
    }

    // Iterate through the queue until it's empty
    while (!q.empty()) {
        int node = q.front(); // Remove a node with degree 1 from the queue
        q.pop();
        for (auto [neighbor, _]: graph[node]) {                          // Iterate through its neighbors
            new_graph[neighbor].erase({node, _});                        // Remove edge from the neighbor
            if (!visited[neighbor] && new_graph[neighbor].size() == 1) { // If neighbor now has degree 1
                q.push(neighbor);                                        // Add neighbor to the queue
                degree_one_nodes.push_back(neighbor);
                visited[neighbor] = true; // Mark neighbor as visited
            }
        }
    }

    // Remove degree one nodes from the new graph
    for (int node: degree_one_nodes) {
        new_graph[node].clear();
    }

    return new_graph;
}

pair<int, pair<int, int>> find_edge_with_smallest_weight(vector<vector<pair<int, int>>> &graph) {


    int min_weight = numeric_limits<int>::max();
    pair<int, int> min_edge;

    // Iterate through each edge in the graph
    for (int node = 0; node < graph.size(); ++node) {
        for (auto [neighbor, weight]: graph[node]) {
            if (weight < min_weight) {
                min_weight = weight;
                min_edge = {node, neighbor};
            }
        }
    }

    return {min_weight, min_edge};
}

// Function to find a cycle containing the given edge using BFS
vector<int> find_cycle(vector<set<pair<int, int>>> &graph, pair<int, int> edge) {
    int start = edge.first;
    int end = edge.second;

    vector<int> parent(graph.size(), -1);
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == end) break;
        for (auto [neighbor, _]: graph[node]) {
            if (parent[neighbor] == -1 && !(node == start && neighbor == end)) {
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    vector<int> cycle;
    for (int current = end; current != -1; current = parent[current]) {
        cycle.push_back(current);
        if (current == start) break;
    }

    return cycle;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Initialize the graph
        vector<vector<pair<int, int>>> graph(n);

        // Read each edge and its weight
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u].push_back({v, w}); // Add edge uv
            graph[v].push_back({u, w}); // Add edge vu (undirected)
        }

        // Find the edge with the smallest weight
        pair<int, pair<int, int>> smallest_edge = find_edge_with_smallest_weight(graph);

        // Find a cycle containing the edge with the smallest weight
        vector<int> cycle = find_cycle(graph, smallest_edge.second);

        cout << smallest_edge.first << " " << cycle.size() << endl;
        for (int node: cycle) {
            cout << node + 1 << " ";
        }

        // Output the cycle
        cout << endl;
    }

    return 0;
}

