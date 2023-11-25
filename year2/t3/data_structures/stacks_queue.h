//
// Created by Itay Mor on 25/11/2023.
//
#include "stack"
#ifndef IJST_YEAR2_T3_DATA_STRUCTURES_STACKS_QUEUE_H_
#define IJST_YEAR2_T3_DATA_STRUCTURES_STACKS_QUEUE_H_

#endif //IJST_YEAR2_T3_DATA_STRUCTURES_STACKS_QUEUE_H_

template<typename T>
class stacks_queue {
 private:
  std::stack<T> s1_, s2_;
  T front_, back_;

  void move_to_s2_() {
    while (!s1_.empty()) {
      s2_.push(s1_.top());
      s1_.pop();
    }
  }

 public:
  stacks_queue() =  default; // Default

  void push(T element) {
    static bool first_push = true;
    back_ = element;
    // Handle first push (push to s2_, define front_).
    if (first_push) {
      front_ = element;
      s2_.push(element);
      first_push = false;
      return;
    }
    s1_.push(element);
  }

  T pop() {
    T return_value = s2_.top();
    s2_.pop();                        // pop the top element of s2_.
    if (s2_.empty())  move_to_s2_();  // If s2_ is empty, fill it for the next pop.
    if (!empty()) front_ = s2_.top(); // Update front_ if exists.

    return return_value;
  }

  inline size_t size() {
    return s1_.size() + s2_.size();
  }
  inline bool empty() {
    return s1_.empty() && s2_.empty();
  }
  inline T front() {
    return front_;
  }
  inline T back() {
    return back_;
  }
};
