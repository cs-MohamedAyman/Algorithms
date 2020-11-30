#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        int idx = i;
        for (int j = i ; j < n ; j++) {
            if (arr[idx] > arr[j])
                idx = j;
        }
        swap(arr[i], arr[idx]);
    }
}

int main() {

    int n = 8;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    cout << "selection_sort: \n";
    selection_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

}