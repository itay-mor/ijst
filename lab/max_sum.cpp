#include <iostream>
#include <vector>

using namespace std;

long long max_sum(const vector<long long>& numbers, long long sum) {

  if (numbers.size()==1) {
    return numbers[0];
  }

  vector<long long> sliced_vector(numbers.size()-1);
  for (long long i = 1; i < numbers.size(); i++) {
    sliced_vector[i-1] = numbers[i];
  }


  long long max_after = max_sum(sliced_vector, sum+numbers[0]);
  return (sum+numbers[0] > max_after) ? sum+numbers[0] : sum+numbers[0]+max_after;
}

int main() {
  long long n; cin >> n;
  vector<long long> numbers;

  long long temp;
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    numbers.push_back(temp);
  }

  cout << max_sum(numbers, 0);
}