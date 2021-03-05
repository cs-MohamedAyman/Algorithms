#include <bits/stdc++.h>
using namespace std;

bool linear_search(int arr[], int n, int item) {
	int i = 0;
	while (i < n) {
        if (arr[i] == item)
			return true;
        i = i + 1;
    }
	return false;
}

int main() {

    int n = 8;
    int arr[] = {10, 14, 19, 27, 33, 35, 42, 44};

    cout << "linear_search for 42: " << linear_search(arr, n, 42) << '\n';
    cout << "linear_search for 40: " << linear_search(arr, n, 40) << '\n';
    
}