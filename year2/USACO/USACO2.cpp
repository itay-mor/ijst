//
// Created by Itay Mor on 18/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int64_t max_number_of_days(string cows) {

  set<int64_t> seqs_lengths;
  int64_t first_seq = 0, last_seq = 0;
  for (int64_t i = 0; i < cows.length(); ++i) {
    int64_t index = i;
    int64_t seq = 0;

    while (i < cows.length() && cows[i] == '1') {
      seq++;
      i++;
    }
    if (index == 0 && i >= cows.length() - 1)
      return -1;
    if (index == 0)
      first_seq = seq;
    if (i >= cows.length() - 1)
      last_seq = seq;
    if (seq > 0 && index > 0 && i < cows.length() - 1)
      seqs_lengths.insert(seq);

  }




  if (seqs_lengths.empty() && first_seq && last_seq)
//    return min(first_seq, last_seq);
    return -2;
  if (seqs_lengths.empty() && first_seq)
    return -1;
  if (seqs_lengths.empty() && last_seq)
    return -1;
  if (first_seq)
    seqs_lengths.insert(first_seq);
  if (last_seq)
    seqs_lengths.insert(last_seq);

  auto it = seqs_lengths.begin();
  int64_t odd = *it % 2;
  for (auto seq_length : seqs_lengths) {
    if (seq_length%2 != odd)
      return 0;
  }
  return (*it - 1) / 2;

}

int main() {
  int n; cin >> n;
  string cows;
  cin >> cows;

  int64_t days = max_number_of_days(cows);
  if (days < 0)
    cout << -days;
  int64_t sick_cows = 0;
  for (auto cow : cows)
    sick_cows += (cow == '1');
  if (days == 0)
    cout << sick_cows;
  if (days > 0) {
    int64_t ans = log2(days) + 1;
    cout << ans;
  }

}