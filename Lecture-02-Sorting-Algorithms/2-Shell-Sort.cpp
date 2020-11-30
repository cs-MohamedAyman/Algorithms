#include <bits/stdc++.h>
using namespace std;

void shell_sort(int arr[], int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap ; i < n ; i++) {
            int j = i, temp = arr[i];
            while (j - gap >= 0 && temp < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

int main() {

    int n = 8;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    cout << "shell_sort: \n";
    shell_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

}