//
// Created by Itay Mor on 03/11/2023.
//
#include <bits/stdc++.h>
#define x first
#define y second



using namespace std;
using coord = pair<double, double>;

vector<coord> read_points(size_t size) {
  vector<coord> points(size);
  for (int i = 0; i < size; ++i)
    cin >> points[i].x >> points[i].y;

  return points;
}

inline double point_abs(coord point) {
  return sqrt(point.x*point.x +point.y*point.y);
}

double best_circle_radius(const vector<coord>& points) {
  map<double, int> dist2count;
  {
    double dist;
    for (auto point : points) {
      dist = point_abs(point);
      if (dist2count.find(dist) == dist2count.end())
        dist2count.insert({dist, 1});
      else
        dist2count[dist]++;
    }
  }

  pair<double, int> max_element = {0, 0};
  for (auto const& [dist, count] : dist2count)
    if (count > max_element.second)
      max_element = {dist, count};

  return max_element.first;
}

int main() {
  int n; cin >> n;
  auto points = read_points(n);
  cout << "x^2 + y^2 = " << best_circle_radius(points) << "^2";
}
