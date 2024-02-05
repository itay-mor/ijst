//
// Created by Itay Mor on 02/02/2024.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll INF = numeric_limits<ll>::max();
constexpr ll MOD = 1000000007;

struct Edge {
  ll targetNode, weight;

  Edge(ll target_node, ll weight) : targetNode(target_node), weight(weight) {}
};

struct PQNode {
  ll nodeId, dist;

  PQNode(ll id, ll d) : nodeId(id), dist(d) {}
  inline bool operator<(const PQNode& other) const {
    return dist > other.dist;
  }
};

vector<vector<Edge>> graph;
vector<ll> dist;
vector<ll> possibilities;
vector<ll> max_length;
vector<ll> min_length;

void dijkstra(ll start_node = 1) {
  priority_queue<PQNode> pq; // {Suggested dist, node}
  dist.assign(graph.size(), INF);
  possibilities.resize(graph.size());
  min_length.resize(graph.size());
  max_length.resize(graph.size());

  dist[start_node] = 0;
  possibilities[start_node] = 1;
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
        possibilities[adjNode] = possibilities[closest_node];
        max_length[adjNode] = max_length[closest_node] + 1;
        min_length[adjNode] = min_length[closest_node] + 1;
        dist[adjNode] = alt_dist;
        pq.emplace(adjNode, alt_dist);
      } else if (alt_dist == dist[adjNode]) {
        possibilities[adjNode] += possibilities[closest_node];
        possibilities[adjNode] %= MOD;
        max_length[adjNode] = max(max_length[adjNode], max_length[closest_node] + 1);
        min_length[adjNode] = min(min_length[adjNode], min_length[closest_node] + 1);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  graph = vector<vector<Edge>>(n + 1);
  ll flight_source, flight_target, price;
  for (ll i = 0; i < m; ++i) {
    cin >> flight_source >> flight_target >> price;
    graph[flight_source].emplace_back(flight_target, price);
  }

  dijkstra();

  cout << dist[n] << " " << possibilities[n] << " " << min_length[n] << " " << max_length[n];
}