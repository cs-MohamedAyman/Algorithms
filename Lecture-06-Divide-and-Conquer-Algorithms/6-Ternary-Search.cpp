#include <bits/stdc++.h>
using namespace std;

bool ternary_search(int arr[], int b, int e, int item) { 
    if (b > e)
        return false;
    int m1 = b + (e - b) / 3;
    int m2 = e - (e - b) / 3;
    if (arr[m1] == item || arr[m2] == item)
        return true;
    else if (item < arr[m1])
        return ternary_search(arr, b, m1 - 1, item);
    else if (item > arr[m2])
        return ternary_search(arr, m2 + 1, e, item);
    else
        return ternary_search(arr, m1 + 1, m2 - 1, item);
}

int main() {

    int n = 8;
    int arr[] = {10, 14, 19, 27, 33, 35, 42, 44};

    cout << "ternary_search for 42: " << ternary_search(arr, 0, n-1, 42) << '\n';
    cout << "ternary_search for 43: " << ternary_search(arr, 0, n-1, 43) << '\n';
    cout << "ternary_search for 44: " << ternary_search(arr, 0, n-1, 44) << '\n';
    cout << "ternary_search for 12: " << ternary_search(arr, 0, n-1, 12) << '\n';
    cout << "ternary_search for 10: " << ternary_search(arr, 0, n-1, 10) << '\n';
    
}