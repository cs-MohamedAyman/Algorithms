#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e5+3;
int n;
vector<int> dis;
vector<int> prt;
vector<pair<int, int>> adj[N];

// This function adds edges between given vertices (undirected edge)
void add_undirected_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
// This function adds edges between given vertices (directed edge)
void add_directed_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
}

void dijkstra(int src) {
    dis.assign(n, INF);
    prt.assign(n, -1);
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>> > pq;     
    pq.push({0, src}); 
    dis[src] = 0;
    while (!pq.empty()) { 
        int v = pq.top().second; 
        pq.pop();
        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (dis[u] > dis[v] + w) {
                dis[u] = dis[v] + w;
                pq.push({dis[u], u}); 
                prt[u] = v;
            }
        }
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
    dijkstra(0);
    
    cout << "Distance :\n";
    for (int i = 0; i < n; i++) 
        cout << i << ' ' << dis[i] << '\n'; 
    cout << '\n';
    cout << "Parent :\n";
    for (int i = 0; i < prt.size(); i++) 
        cout << i << ' ' << prt[i] << '\n'; 
    cout << '\n';
}
