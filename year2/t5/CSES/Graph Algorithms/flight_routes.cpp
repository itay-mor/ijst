//
// Created by Itay Mor on 28/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll INF = numeric_limits<ll>::max();

struct Edge {
  ll targetNode, weight;

  Edge(ll target_node, ll weight) : targetNode(target_node), weight(weight) {}
  inline bool operator==(const Edge& other) const {
    return weight == other.weight && targetNode == other.targetNode;
  }
};

struct EdgeHash {
  std::size_t operator()(const Edge& e) const {
    return std::hash<ll>()(e.targetNode ^ e.weight);
  }
};

struct PQNode {
  ll nodeId, dist;

  PQNode(ll id, ll d) : nodeId(id), dist(d) {}
  inline bool operator<(const PQNode& other) const {
    return dist > other.dist;
  }
};

vector<unordered_set<Edge, EdgeHash>> graph, flipped_graph;
vector<ll> dist;
int n, m;

void remove_best_route() {
  ll node = n;
  while (node != 1) {
    for (auto e : flipped_graph[node]) {
      if (dist[e.targetNode] + e.weight == dist[node]) {
        graph[e.targetNode].erase({node, e.weight});
        flipped_graph[node].erase(e);
        node = e.targetNode;
        break;
      }
    }
  }
}

void dijkstra(ll start_node = 1) {
  priority_queue<PQNode> pq; // {Suggested dist, node}
  dist.assign(graph.size(), INF);

  dist[start_node] = 0;
  pq.emplace(start_node, 0);

  while (!pq.empty()) {
    ll closest_node_dist = pq.top().dist;
    ll closest_node = pq.top().nodeId;
    pq.pop();

    // Nodes can be inserted to the PQ multiple times.
    // If we already handled the node before, it means now it
    // might have a worse distance, so we can skip it.
    if (closest_node_dist > dist[closest_node]) continue;

    for (const auto& e : graph[closest_node]) {
      auto weight = e.weight;
      auto adjNode = e.targetNode;
      ll alt_dist = dist[closest_node] + weight;
      if (alt_dist < dist[adjNode]) {
        dist[adjNode] = alt_dist;
        pq.emplace(adjNode, alt_dist);
      }
    }
  }
}

int main() {
  int k;
  cin >> n >> m >> k;
  graph.resize(n + 1);
  flipped_graph.resize(n + 1);
  int a, b, c;
  while (m--) {
    cin >> a >> b >> c;
    graph[a].emplace(b, c);
    flipped_graph[b].emplace(a, c);
  }
  while (k--) {
    dijkstra();
    cout << dist[n] << " ";
    remove_best_route();
  }
}