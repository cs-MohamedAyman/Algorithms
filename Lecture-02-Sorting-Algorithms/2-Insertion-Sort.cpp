#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        int j = i;
        int temp = arr[i];
        while (j > 0 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

int main() {

    int n = 8;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    cout << "insertion_sort: \n";
    insertion_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

}