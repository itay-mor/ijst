//
// Created by Itay Mor on 29/08/2023.
//

#include <iostream>
#include <cstdint>

using namespace std;


int64_t run_increasing_array(int64_t n) {
    int64_t curr_num=0, prev_num=0, moves=0, add = 0;
    for (int64_t i = 0; i < n; i++)
    {
        prev_num = curr_num+add;
        cin >> curr_num;
        add = 0;

        if (curr_num<prev_num)
        {
            add = prev_num-curr_num;
            moves += add;
        }
    }
    return moves;
}

int main() {
    int64_t n; cin >> n;

    int64_t moves = run_increasing_array(n);
    cout << moves << endl;

}