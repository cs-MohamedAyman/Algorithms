#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int lf = 2 * i + 1;
    int rt = 2 * i + 2;
    int j = -1;
    while (i != j) {
        j = i;
        if (rt < n && arr[rt] > arr[i])
            i = rt;
        if (lf < n && arr[lf] > arr[i])
            i = lf;
        swap(arr[i], arr[j]);
        lf = 2 * i + 1;
        rt = 2 * i + 2;
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 ; i >= 0 ; i--)
        heapify(arr, n, i);
    for (int i = n - 1 ; i >= 0 ; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {

    int n = 8;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    cout << "heap_sort: \n";
    heap_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

}