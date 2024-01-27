//
// Created by Itay Mor on 22/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

template<typename T>
class mean_set {
 private:
  std::multiset<T> s1;
  std::multiset<T> s2;
  size_t size = 0;
  void balance() {
    while (s1.size() < s2.size()) {
      T to_add = *s2.begin();
      s2.erase(s2.begin());
      s1.insert(to_add);
    }
    while (s2.size() + 1 < s1.size()) {
      T to_add = *(last_s1_it());
      s1.erase(last_s1_it());
      s2.insert(to_add);
    }
  }
  typename std::set<T>::iterator last_s1_it() {
    auto it = s1.end();
    it--;
    return it;
  }
 public:
  void push(T element) {
    if (s1.empty()) {
      s1.insert(element);
      return;
    }
    if (element > *(last_s1_it()))
      s2.insert(element);
    else
      s1.insert(element);
    balance();
    size++;
  }

  void pop(T element) {
    if (element > *(last_s1_it()))
      s2.erase(s2.find(element));
    else
      s1.erase(s1.find(element));
    balance();
    size--;
  }

  T get_mean() {
    return *(last_s1_it());
  }
};

void sliding_median(vector<int64_t> numbers, int k) {
  mean_set<int64_t> window;
  for (int i = 0; i < k; ++i) window.push(numbers[i]);
  cout << window.get_mean() << " ";

  for (int i = k; i < numbers.size(); ++i) {
    window.push(numbers[i]);
    window.pop(numbers[i-k]);
    cout << window.get_mean() << " ";
  }
}

int main() {
  int n, k; cin >> n >> k;
  vector<int64_t> numbers(n);
  for (auto& number : numbers)
    cin >> number;

  sliding_median(numbers, k);
}