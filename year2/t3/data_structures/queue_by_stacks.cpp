//
// Created by Itay Mor on 25/11/2023.
//
#include <iostream>
#include "stacks_queue.h"

int main() {
  stacks_queue<int> q;
  q.push(10); // {10}     [back: 10, front: 10]
  q.push(1);  // {10 1}   [back: 1, front 10]
  q.push(2);  // {10 1 2} [back: 2, front 10]
  std::cout << "Back: " << q.back() << ", Front: "<< q.front() << ", Size: " << q.size() << std::endl;
  std::cout << q.pop() << " ";  // {1 2}  [back: 2, front 1]
  std::cout << q.pop() << " ";  // {2}    [back: 2, front 2]
  q.push(11);           // {2 11} [back: 11, front 2]
  std::cout << q.pop() << " ";  // {11}   [back: 11, front 11]
  std::cout << q.pop();         // {}     [back: None, front: None]
}