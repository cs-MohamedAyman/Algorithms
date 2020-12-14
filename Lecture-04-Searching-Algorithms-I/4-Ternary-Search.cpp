#include <bits/stdc++.h>
using namespace std;

bool ternary_search(int arr[], int n, int item) { 
    int b = 0, e = n - 1;
    while (b <= e) {
        int m1 = b + (e - b) / 3;
        int m2 = e - (e - b) / 3;
        if (arr[m1] == item || arr[m2] == item)
            return true;
        else if (item < arr[m1])
            e = m1 - 1;
        else if (item > arr[m2])
            b = m2 + 1;
        else {
            b = m1 + 1;
            e = m2 - 1;
        }
    }
    return false;
}

int main() {

    int n = 8;
    int arr[] = {10, 14, 19, 27, 33, 35, 42, 44};

    cout << "ternary_search for 42: " << ternary_search(arr, n, 42) << '\n';
    cout << "ternary_search for 43: " << ternary_search(arr, n, 43) << '\n';
    cout << "ternary_search for 44: " << ternary_search(arr, n, 44) << '\n';
    cout << "ternary_search for 12: " << ternary_search(arr, n, 12) << '\n';
    cout << "ternary_search for 10: " << ternary_search(arr, n, 10) << '\n';
    
}