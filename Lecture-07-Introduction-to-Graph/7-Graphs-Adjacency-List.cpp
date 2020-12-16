#include <bits/stdc++.h>
using namespace std;

// Initialize an adjacency List with static length
const int N = 1e5+3;
int n;
vector<int> adj[N];

// This function adds edges between given vertices (undirected edge)
void add_undirected_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// This function adds edges between given vertices (directed edge)
void add_directed_edge(int u, int v) {
    adj[u].push_back(v);
}

// Initialize an array to mark visited vertices
bool vis_bfs[N];

// This function traverses the graph in breadth first search
void bfs(int src) {
    queue<int> q;
    // push and mark the source node as visited
    q.push(src);
    vis_bfs[src] = true;
	// loop to print all vertices in the graph
    while (!q.empty()) {
        int u = q.front();
        // pop and print the front node
        q.pop();
        cout << u << ' ';
		// loop for all neighbors of the vertex u
        for (int v : adj[u]) {
            if (vis_bfs[v] == false) {
                // push and mark the current node as visited
                q.push(v);
                vis_bfs[v] = true;
            }
        }
    }
}

// Initialize an array to mark visited vertices
bool vis_dfs[N];

// This function traverses the graph in depth first search
void dfs(int src) {
    stack<int> stk;
    // push and mark the source node as visited
    stk.push(src);
    vis_dfs[src] = true;
	// loop to print all vertices in the graph
    while (!stk.empty()) {
        int u = stk.top();
        // pop and print the top node
        stk.pop();
        cout << u << ' ';
		// loop for all neighbors of the vertex u
        for (int v : adj[u]) {
            if (vis_dfs[v] == false) {
				// push and mark the source node as visited
                stk.push(v);
                vis_dfs[v] = true;
            }
        }
    }
}

// Initialize an array to mark visited vertices
bool vis[N];

// This function traverses the graph in depth first search
void dfs_util(int u) {
    // mark the current node as visited and print it
    vis[u] = true;
    cout << u << ' ';
    // recursive for all the vertices adjacent to this vertex
    for (int v : adj[u]) {
        // check if this vertex not visited yet
        if(vis[v] == false)
			dfs_util(v);
    }
}

// This function traverses the graph in depth first search
void dfs() {
    // Call the recursive helper function to print dfs traversal
    // starting from all vertices one by one
    for (int i = 1 ; i <= n ; i++)
        // check if this vertex not visited yet
        if (vis[i] == false)
			dfs_util(i);
}

int vis_cycle[N];
int parent[N];
int cycle_start, cycle_end;

bool dfs_cycle(int u, int p) {
    vis_cycle[u] = 1;
    for (int v : adj[u]) {
        if (v == p) 
            continue;
        if (vis_cycle[v] == 0) {
            parent[v] = u;
            if (dfs_cycle(v, parent[v]))
                return true;
        } 
        else if (vis_cycle[v] == 1) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    vis_cycle[u] = 2;
    return false;
}

void find_cycle() {
	memset(parent, -1, sizeof parent);
    cycle_start = -1;
    for (int v = 0; v < n; v++) {
        if (vis_cycle[v] == 0 && dfs_cycle(v, parent[v]))
            break;
    }
    if (cycle_start == -1) {
        cout << "Acyclic Graph";
        return;
    } 
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    cout << "Cycle found: ";
    for (int v : cycle)
        cout << v << " ";
}

bool vis_connected[N];

void dfs_connected(int u) {
    vis_connected[u] = true;
    for (int v : adj[u]) {
        if (vis_connected[v] == false)
            dfs_connected(v);
    }
}

bool is_connected() {
    dfs_connected(1);
    for (int i = 1 ; i <= n ; i++) {
        if (vis_connected[i] == false)
			return false;
	}
	return true;
}

int main() {

	// Testing operators functionality

    n = 5;
    add_undirected_edge(1, 2);
    add_undirected_edge(1, 3);
    add_undirected_edge(2, 4);
    add_undirected_edge(5, 3);
    add_undirected_edge(2, 3);
    add_undirected_edge(1, 5);
    
    cout << "Graph representation in bfs : \n";
    bfs(1);
    cout << "\n----------------------------------------------------\n";
    cout << "Graph representation in dfs iterative : \n";
    dfs(1);
    cout << "\n----------------------------------------------------\n";
    cout << "Graph representation in dfs recursion : \n";
    dfs();
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	Graph representation in bfs : 
	1 2 3 5 4 
	----------------------------------------------------
	Graph representation in dfs iterative : 
	1 5 3 2 4 
	----------------------------------------------------
	Graph representation in dfs recursion : 
	1 2 4 3 5 
	----------------------------------------------------
	*/

	cout << (is_connected()? "Connected Graph" : "Disconnected Graph");
    cout << "\n----------------------------------------------------\n";
    find_cycle();
    cout << "\n----------------------------------------------------\n";
	
	/* Expected Output:
    Connected Graph
	----------------------------------------------------
    Cycle found: 1 2 3 1
	----------------------------------------------------
	*/

}
