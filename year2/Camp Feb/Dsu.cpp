//
// Created by Itay Mor on 05/02/2024.
//

#include "Dsu.h"

int main() {
  int n, m; cin >> n >> m;
  Dsu dsu(n);

  int a, b;
  while (m--) {
    cin >> a >> b;
    a--; b--;
    dsu.make_union(a, b);
  }

  int q; cin >> q;
  while (q--) {
    cin >> a >> b;
    a--; b--;
    cout << (dsu.find_route(a, b) ? "YES\n" : "NO\n");
  }
}
