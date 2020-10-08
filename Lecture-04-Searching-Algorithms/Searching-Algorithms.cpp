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

bool jump_search(int arr[], int n, int item) {
	int step = sqrt(n);
	int i = 0;
	while (i < n && arr[i] < item)
		i = i + step;
    if (i >= n)
        i -= step;
	int j = i;
	while (j < min(i + step, n)) {
        if (arr[j] == item)
			return true;
		j = j + 1;
    }
	return false;
}

bool binary_search(int arr[], int n, int item) {
	int b = 0, e = n - 1;
	while (b <= e) {
		int m  = b + (e - b) / 2;
		if (arr[m] < item)
			b = m + 1;
		else if (arr[m] > item)
			e = m - 1;
		else
			return true;
	}
	return false;
}

int lower_bound(int arr[], int n, int item) {
	int b = 0, e = n;
	while (b < e) {
		int m  = b + (e - b) / 2;
		if (arr[m] < item)
			b = m + 1;
		else
			e = m;
	}
	return b;
}

int upper_bound(int arr[], int n, int item) {
	int b = 0, e = n;
	while (b < e) {
		int m  = b + (e - b) / 2;
		if (arr[m] <= item)
			b = m + 1;
		else
			e = m;
	}
	return b;
}

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

    cout << "linear_search\n";
    cout << linear_search(arr, n, 42) << '\n';
    cout << linear_search(arr, n, 40) << '\n';

    cout << "jump_search\n";
    cout << jump_search(arr, n, 42) << '\n';
    cout << jump_search(arr, n, 43) << '\n';
    cout << jump_search(arr, n, 44) << '\n';
    cout << jump_search(arr, n, 12) << '\n';
    cout << jump_search(arr, n, 10) << '\n';

    cout << "binary_search\n";
    cout << binary_search(arr, n, 42) << '\n';
    cout << binary_search(arr, n, 43) << '\n';
    cout << binary_search(arr, n, 44) << '\n';
    cout << binary_search(arr, n, 12) << '\n';
    cout << binary_search(arr, n, 10) << '\n';

    cout << "lower_bound\n";
    cout << lower_bound(arr, n, 9) << '\n';
    cout << lower_bound(arr, n, 10) << '\n';
    cout << lower_bound(arr, n, 11) << '\n';
    cout << lower_bound(arr, n, 14) << '\n';
    cout << lower_bound(arr, n, 43) << '\n';
    cout << lower_bound(arr, n, 44) << '\n';
    cout << lower_bound(arr, n, 45) << '\n';

    cout << "upper_bound\n";
    cout << upper_bound(arr, n, 9) << '\n';
    cout << upper_bound(arr, n, 10) << '\n';
    cout << upper_bound(arr, n, 11) << '\n';
    cout << upper_bound(arr, n, 14) << '\n';
    cout << lower_bound(arr, n, 43) << '\n';
    cout << upper_bound(arr, n, 44) << '\n';
    cout << upper_bound(arr, n, 45) << '\n';

    cout << "ternary_search\n";
    cout << ternary_search(arr, n, 42) << '\n';
    cout << ternary_search(arr, n, 43) << '\n';
    cout << ternary_search(arr, n, 44) << '\n';
    cout << ternary_search(arr, n, 12) << '\n';
    cout << ternary_search(arr, n, 10) << '\n';
    
}