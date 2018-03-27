#include <iostream>
#include <vector>
#include <random>
using namespace std;

void quick_sort(vector<int> &arr, int l, int r) {
    if (r <= l) return ;
    int tar = arr[l];
    int lp = l, rp = r + 1;
    int i = l + 1;
    while (i < rp) {
        if (arr[i] > tar) {
            --rp;
            swap(arr[i], arr[rp]);
        } else if (arr[i] < tar) {
            ++lp;
            swap(arr[i], arr[lp]);
            ++i;
        } else {
            ++i;
        }
    }
    swap(arr[l], arr[lp]);
    quick_sort(arr, l, lp-1);
    quick_sort(arr, rp, r);
}

const int LEN = 20;
const int MOD = 5;

int main() {
    srand(time(NULL));
    vector<int> arr(LEN, 0);
    for (auto &ele : arr) {
        ele = rand() % MOD;
        cout << ele << ' ';
    }
    cout << endl;
    quick_sort(arr, 0, LEN-1);
    for (auto &ele : arr)
        cout << ele << ' ';
    cout << endl;
    return 0;
}
