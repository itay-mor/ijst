//
// Created by Itay Mor on 26/11/2023.
//

#ifndef IJST_YEAR2_T3_DATA_STRUCTURES_NEW_STRUCTURE_H_
#define IJST_YEAR2_T3_DATA_STRUCTURES_NEW_STRUCTURE_H_

#endif //IJST_YEAR2_T3_DATA_STRUCTURES_NEW_STRUCTURE_H_

#include <set>

template<typename T>
class mean_set {
 private:
  std::set<T> s1;
  std::set<T> s2;
  size_t size = 0;
  void balance() {
    while (s1.size() < s2.size()) {
      T to_add = *s2.begin();
      s2.erase(s2.begin());
      s1.insert(to_add);
    }
    while (s2.size() + 1 < s1.size()) {
      T to_add = *(s1.end()-1);
      s1.erase(s1.end()-1);
      s2.insert(to_add);
    }
  }
  std::set<T>::iterator last_s1_it() {
    auto it = s1.end();
    it--;
    return it;
  }
 public:
  void push(T element) {
    if (element > *(s1.end()-1))
      s2.insert(element);
    else
      s1.insert(element);
    balance();
    size++;
  }

  void pop(T element) {
    if (element > *(s1.end()-1))
      s2.erase(element);
    else
      s1.erase(element);
    balance();
    size--;
  }

  T get_mean() {
    return *(s1.end()-1);
  }
};