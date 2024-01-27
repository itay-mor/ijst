//
// Created by Itay Mor on 12/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll INF = numeric_limits<ll>::max();

struct Edge {
  Edge() = default;
  ll targetNode{},  weight{};

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
vector<pair<ll, ll>> dist; // {dist, arrived_from}

void dijkstra(ll start_node = 1) {
  priority_queue<PQNode> pq; // {node, suggested distance}
  dist.assign(graph.size(), {INF, 0});

  dist[start_node].first = 0;
  pq.emplace(start_node, 0);

  while (!pq.empty()) {
    ll closest_node_dist = pq.top().dist;
    ll closest_node = pq.top().nodeId;
    pq.pop();

    // Nodes can be inserted to the PQ multiple times.
    // If we already handled the node before, it means now it
    // might have a worse distance, so we can skip it.
    if (closest_node_dist > dist[closest_node].first) continue;

    for (const auto& e : graph[closest_node]) {
      auto weight = e.weight;
      auto adjNode = e.targetNode;
      ll alt_dist = dist[closest_node].first + weight;
      if (alt_dist < dist[adjNode].first) {
        dist[adjNode] = {alt_dist, closest_node};
        pq.emplace(adjNode, alt_dist);
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
  ll flight_source, flight_target, duration;
  for (ll i = 0; i < m; ++i) {
    cin >> flight_source >> flight_target >> duration;
    graph[flight_source].emplace_back(flight_target, duration);
  }

  dijkstra();

  ll max_flight = 0, curr_flight;
 for (ll i = n; i != 1; i = dist[i].second) {
   curr_flight = dist[i].first - dist[dist[i].second].first;
   if (curr_flight > max_flight) max_flight = curr_flight;
 }

 ll coupon = (max_flight + 1)/2;
 cout << dist[n].first - coupon;
}