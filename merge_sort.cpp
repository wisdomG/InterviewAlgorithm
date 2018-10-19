/***********************************************
 * 归并排序
 * ********************************************/

#include <iostream>
#include <vector>
using namespace std;

void merge_sort(vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    vector<int> tmp(r - l + 1, 0);
    for (int i = l; i <= r; ++i)
        tmp[i-l] = arr[i];
    int i = 0, j = mid + 1 - l;
    int k = l;
    while (i <= mid - l && j <= r - l) {
        if (tmp[i] < tmp[j]) {
            arr[k++] = tmp[i];
            ++i;
        } else {
            arr[k++] = tmp[j];
            ++j;
        }
    }
    if (i > mid - l) {
        while (j <= r - l) {
            arr[k++] = tmp[j];
            ++j;
        }
    }
    else if (j > r - l) {
        while (i <= mid - l) {
            arr[k++] = tmp[i];
            ++i;
        }
    }
}

int main() {
    srand(time(NULL));
    const int len = 10;
    const int mod = 5;
    vector<int> arr;
    for (int i = 0; i < len; ++i) {
        arr.push_back(rand() % mod);
    }
    merge_sort(arr, 0, len - 1);
    for (auto ele : arr) {
        cout << ele << ' ';
    }
    cout << endl;
    return 0;
    
}
