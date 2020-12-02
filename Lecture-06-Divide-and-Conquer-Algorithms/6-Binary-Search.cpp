#include <bits/stdc++.h>
using namespace std;

bool binary_search(int arr[], int b, int e, int item) {
	if (b > e)
	    return false;
	int m  = b + (e - b) / 2;
	if (arr[m] < item)
		binary_search(arr, m + 1, e, item);
	else if (arr[m] > item)
		binary_search(arr, b, m - 1, item);
	else
		return true;
}

int lower_bound(int arr[], int b, int e, int item) {
	if (b >= e)
	    return b;
	int m  = b + (e - b) / 2;
	if (arr[m] < item)
		return lower_bound(arr, m + 1, e, item);
	else
		return lower_bound(arr, b, m, item);
}

int upper_bound(int arr[], int b, int e, int item) {
	if (b >= e)
	    return b;
	int m  = b + (e - b) / 2;
	if (arr[m] <= item)
		return upper_bound(arr, m + 1, e, item);
	else
		return upper_bound(arr, b, m, item);
}

int main() {

    int n = 8;
    int arr[] = {10, 14, 19, 27, 33, 35, 42, 44};

    cout << "binary_search for 42: " << binary_search(arr, 0, n-1, 42) << '\n';
    cout << "binary_search for 43: " << binary_search(arr, 0, n-1, 43) << '\n';
    cout << "binary_search for 44: " << binary_search(arr, 0, n-1, 44) << '\n';
    cout << "binary_search for 12: " << binary_search(arr, 0, n-1, 12) << '\n';
    cout << "binary_search for 10: " << binary_search(arr, 0, n-1, 10) << '\n';
    cout << "--------------------------\n";
    
    cout << "lower_bound for  9: " << lower_bound(arr, 0, n, 9) << '\n';
    cout << "lower_bound for 10: " << lower_bound(arr, 0, n, 10) << '\n';
    cout << "lower_bound for 11: " << lower_bound(arr, 0, n, 11) << '\n';
    cout << "lower_bound for 14: " << lower_bound(arr, 0, n, 14) << '\n';
    cout << "lower_bound for 43: " << lower_bound(arr, 0, n, 43) << '\n';
    cout << "lower_bound for 44: " << lower_bound(arr, 0, n, 44) << '\n';
    cout << "lower_bound for 45: " << lower_bound(arr, 0, n, 45) << '\n';
    cout << "--------------------------\n";
    
    cout << "upper_bound for  9: " << upper_bound(arr, 0, n, 9) << '\n';
    cout << "upper_bound for 10: " << upper_bound(arr, 0, n, 10) << '\n';
    cout << "upper_bound for 11: " << upper_bound(arr, 0, n, 11) << '\n';
    cout << "upper_bound for 14: " << upper_bound(arr, 0, n, 14) << '\n';
    cout << "upper_bound for 43: " << upper_bound(arr, 0, n, 43) << '\n';
    cout << "upper_bound for 44: " << upper_bound(arr, 0, n, 44) << '\n';
    cout << "upper_bound for 45: " << upper_bound(arr, 0, n, 45) << '\n';

}