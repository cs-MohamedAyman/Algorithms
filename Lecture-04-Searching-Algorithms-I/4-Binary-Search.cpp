#include <bits/stdc++.h>
using namespace std;

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

int main() {

    int n = 8;
    int arr[] = {10, 14, 19, 27, 33, 35, 42, 44};

    cout << "binary_search for 42: " << binary_search(arr, n, 42) << '\n';
    cout << "binary_search for 43: " << binary_search(arr, n, 43) << '\n';
    cout << "binary_search for 44: " << binary_search(arr, n, 44) << '\n';
    cout << "binary_search for 12: " << binary_search(arr, n, 12) << '\n';
    cout << "binary_search for 10: " << binary_search(arr, n, 10) << '\n';
    cout << "--------------------------\n";
    
    cout << "lower_bound for  9: " << lower_bound(arr, n, 9) << '\n';
    cout << "lower_bound for 10: " << lower_bound(arr, n, 10) << '\n';
    cout << "lower_bound for 11: " << lower_bound(arr, n, 11) << '\n';
    cout << "lower_bound for 14: " << lower_bound(arr, n, 14) << '\n';
    cout << "lower_bound for 43: " << lower_bound(arr, n, 43) << '\n';
    cout << "lower_bound for 44: " << lower_bound(arr, n, 44) << '\n';
    cout << "lower_bound for 45: " << lower_bound(arr, n, 45) << '\n';
    cout << "--------------------------\n";
    
    cout << "upper_bound for  9: " << upper_bound(arr, n, 9) << '\n';
    cout << "upper_bound for 10: " << upper_bound(arr, n, 10) << '\n';
    cout << "upper_bound for 11: " << upper_bound(arr, n, 11) << '\n';
    cout << "upper_bound for 14: " << upper_bound(arr, n, 14) << '\n';
    cout << "upper_bound for 43: " << upper_bound(arr, n, 43) << '\n';
    cout << "upper_bound for 44: " << upper_bound(arr, n, 44) << '\n';
    cout << "upper_bound for 45: " << upper_bound(arr, n, 45) << '\n';

}