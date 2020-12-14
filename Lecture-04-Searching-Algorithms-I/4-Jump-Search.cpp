#include <bits/stdc++.h>
using namespace std;

bool jump_search(int arr[], int n, int item) {
    int step = sqrt(n);
    int i = 0;
    while (i + step < n && arr[i + step] <= item)
        i = i + step;
    int j = i;
    while (j < min(i + step, n)) {
        if (arr[j] == item)
            return true;
        j = j + 1;
    }
    return false;
}

int main() {

    int n = 8;
    int arr[] = {10, 14, 19, 27, 33, 35, 42, 44};

    cout << "jump_search for 42: " << jump_search(arr, n, 42) << '\n';
    cout << "jump_search for 43: " << jump_search(arr, n, 43) << '\n';
    cout << "jump_search for 44: " << jump_search(arr, n, 44) << '\n';
    cout << "jump_search for 12: " << jump_search(arr, n, 12) << '\n';
    cout << "jump_search for 10: " << jump_search(arr, n, 10) << '\n';
    
}
