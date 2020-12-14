#include <bits/stdc++.h>
using namespace std;

void quick_sort(int arr[], int f, int e) {
    int st1 = f, st2 = e;
    int pivot = arr[(f + e) / 2];
    while (st1 <= st2) {
        while (arr[st1] < pivot)
            st1 = st1 + 1;
        while (arr[st2] > pivot)
            st2 = st2 - 1;
        if (st1 <= st2) {
            swap(arr[st1], arr[st2]);
            st1 = st1 + 1;
            st2 = st2 - 1;
        }
    }    
    if (st1 < e)
        quick_sort(arr, st1, e);
    if (f < st2)
        quick_sort(arr, f, st2);
}

int main() {

    int n = 8;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    cout << "quick_sort: \n";
    quick_sort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

}