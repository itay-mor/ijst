//
// Created by Itay Mor on 28/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll INF = numeric_limits<ll>::max() - 2000000000;

struct Edge {
  ll targetNode, weight;

  Edge(ll target_node, ll weight) : targetNode(target_node), weight(weight) {}
  inline bool operator==(const Edge& other) const {
    return weight == other.weight && targetNode == other.targetNode;
  }
};

struct PQNode {
  ll nodeId, dist;

  PQNode(ll id, ll d) : nodeId(id), dist(d) {}
  inline bool operator>(const PQNode& other) const {
    return dist > other.dist;
  }
  inline bool operator<(const PQNode& other) const {
    return dist < other.dist;
  }
};

vector<vector<Edge>> graph;
vector<priority_queue<ll>> dist;
int n, m, k;


void dijkstra(ll start_node = 1) {
  priority_queue<PQNode, vector<PQNode>, greater<>> pq; // {Suggested dist, node}

  dist[start_node].push(0);
  pq.emplace(start_node, 0);

  while (!pq.empty()) {
    ll closest_node_dist = pq.top().dist;
    ll closest_node = pq.top().nodeId;
    pq.pop();

    // Nodes can be inserted to the PQ multiple times.
    // If we already handled the node before, it means now it
    // might have a worse distance, so we can skip it.
    if (closest_node_dist > dist[closest_node].top()) continue;

    for (const auto& e : graph[closest_node]) {
      auto weight = e.weight;
      auto adjNode = e.targetNode;
      ll alt_dist = closest_node_dist + weight;
      if (dist[adjNode].size() < k) {
        dist[adjNode].push(alt_dist);
        pq.emplace(adjNode, alt_dist);
      } else if (alt_dist < dist[adjNode].top()) {
        dist[adjNode].pop();
        dist[adjNode].push(alt_dist);
        pq.emplace(adjNode, alt_dist);
      }
    }
  }
}

int main() {
  cin >> n >> m >> k;
  graph.resize(n + 1);
  dist.resize(n + 1);
  int a, b, c;
  while (m--) {
    cin >> a >> b >> c;
    graph[a].emplace_back(b, c);
  }
  for (int i = 2; i <= n; ++i)
    dist[i].push(INF);

  dijkstra();
  vector<ll> k_best_routes;
  while (!dist[n].empty()) {
    k_best_routes.push_back(dist[n].top());
    dist[n].pop();
  }
  reverse(k_best_routes.begin(), k_best_routes.end());
  for (auto route : k_best_routes)
    cout << route << " ";


}