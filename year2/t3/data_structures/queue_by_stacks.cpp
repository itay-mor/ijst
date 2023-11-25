//
// Created by Itay Mor on 25/11/2023.
//
#include <iostream>
#include "stacks_queue.h"

int main() {
  stacks_queue<int> q;
  q.push(10); // {10}
  q.push(1);  // {10 1}
  q.push(2);  // {10 1 2}
  std::cout << "Back: " << q.back() << ", Front: "<< q.front() << std::endl;
  std::cout << q.pop() << " ";  // {1 2}
  std::cout << q.pop() << " ";  // {2}
  std::cout << q.pop();         // {}
}