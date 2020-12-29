#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5+3;
int n;
vector<int> dis;
vector<int> prt;
vector<pair<int, int>> adj[N];
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, pair<int, int>>> res;

// This function adds edges between given vertices (undirected edge)
void add_undirected_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    edges.push_back({w, {u, v}});
}

void kruskal() {
    vector<int> edge_id(n);
    for (int i = 0; i < n; i++)
        edge_id[i] = i;
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
        if (edge_id[e.second.first] == edge_id[e.second.second])
            continue;
        res.push_back(e);
        int old_id = edge_id[e.second.first];
        int new_id = edge_id[e.second.second];
        for (int i = 0; i < n; i++)
            if (edge_id[i] == old_id)
                edge_id[i] = new_id;
    }
}

int main() {
    n = 9;
    add_undirected_edge(0, 1, 4); 
    add_undirected_edge(0, 7, 8); 
    add_undirected_edge(1, 2, 8); 
    add_undirected_edge(1, 7, 11); 
    add_undirected_edge(2, 3, 7); 
    add_undirected_edge(2, 8, 2); 
    add_undirected_edge(2, 5, 4); 
    add_undirected_edge(3, 4, 9); 
    add_undirected_edge(3, 5, 14); 
    add_undirected_edge(4, 5, 10); 
    add_undirected_edge(5, 6, 2); 
    add_undirected_edge(6, 7, 1); 
    add_undirected_edge(6, 8, 6); 
    add_undirected_edge(7, 8, 7); 
    kruskal();
    
    cout << "kruskal :\n";
    for (auto i : res) 
        cout << i.second.first << ' ' << i.second.second << ' ' << i.first << '\n'; 
    cout << '\n';
}
