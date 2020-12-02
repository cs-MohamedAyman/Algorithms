#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int f, int m, int e) {
    int temp[e - f + 1], i=0;
    int st1 = f, st2 = m + 1;
    while (st1 <= m && st2 <= e) {
        if (arr[st1] < arr[st2]) {
            temp[i] = arr[st1];
			i = i + 1;
			st1 = st1 + 1;
		}
        else {
            temp[i] = arr[st2];
			i = i + 1;
			st2 = st2 + 1;
		}
    }
    while (st1 <= m) {
        temp[i] = arr[st1];
		i = i + 1;
		st1 = st1 + 1;
	}
    while (st2 <= e) {
        temp[i] = arr[st2];
		i = i + 1;
		st2 = st2 + 1;
	}
    for (int j = f; j <= e; j++)
        arr[j] = temp[j - f];
}

void merge_sort(int arr[], int f, int e) {
    if (f >= e)
		return;
    int m = (f + e) / 2;
    merge_sort(arr, f, m);
    merge_sort(arr, m + 1, e);
    merge(arr, f, m, e);
}

int main() {

    int n = 8;
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    cout << "merge_sort: \n";
    merge_sort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

}