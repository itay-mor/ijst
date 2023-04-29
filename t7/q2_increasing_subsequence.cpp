#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int64_t find_first_bigger(vector<int64_t>& vec, int64_t number) {
  int64_t begin = -1;
  int64_t end = vec.size();

  while ((end-begin)!=1) {
    if (vec[(begin+end)/2] < number) {
      begin = (begin+end)/2;
    }
    else {
      end = (begin+end)/2;
    }
    
  }
  
  return end;
}

// int64_t find_longest_increasing_subsequence(vector<int64_t>& sequence) {
//   vector<int64_t> vec;
//   for (int64_t number : sequence) {
//     if (vec.size() == 0) {
//       vec.push_back(number);
//     } else if (vec[vec.size()-1] < number) {
//       vec.push_back(number);
//     } else {
//       vec[find_first_bigger(vec, number)] = number;
//     }
//   }

//   return vec.size();
// }
int64_t find_longest_increasing_subsequence() {
  vector<int64_t> vec;
  int64_t number;
  int64_t n; cin >> n;
  for (int64_t i = 0; i < n; i++) {
    cin >> number;
    if (vec.size() == 0) {
      vec.push_back(number);
    } else if (vec[vec.size()-1] < number) {
      vec.push_back(number);
    } else {
      vec[find_first_bigger(vec, number)] = number;
    }
  }

  return vec.size();
}
int main() {
  vector<int64_t> sequence = {13, 7, 10};
  cout << find_longest_increasing_subsequence() << endl;
  return 0;
}