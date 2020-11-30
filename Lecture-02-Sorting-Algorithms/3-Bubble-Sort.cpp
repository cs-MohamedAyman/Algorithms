#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
		}
    }
}

int main() {

    int n = 8;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    cout << "bubble_sort: \n";
    bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

}