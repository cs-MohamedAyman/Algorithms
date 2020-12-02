#include <bits/stdc++.h>
using namespace std;

struct point {
    float x;
    float y;
};

bool compareX(point p1, point p2) {
    return p1.x < p2.x;
}

bool compareY(point p1, point p2) {
    return p1.y < p2.y;
}

void heapify(point arr[], int n, int i, bool (*compare)(point, point)) {
    int j = -1;
    while (i != j) {
        j = i;
        int left_idx  = 2 * i + 1;
        int right_idx = 2 * i + 2;
        if (left_idx < n && (*compare)(arr[i], arr[left_idx]))
            i = left_idx  ;
        if (right_idx < n && (*compare)(arr[i], arr[right_idx]))
            i = right_idx;
        swap(arr[i], arr[j]);
    }
}

void heap_sort(point arr[], int n, bool (*compare)(point, point)) {
    for (int i = n / 2 ; i >= 0 ; i--)
        heapify(arr, n, i, compare);
    for (int i = n - 1 ; i >= 0 ; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, compare);
    }
}

float dist(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float brute_force(point p[], int n) {
    float res = FLT_MAX;  
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float curr_dist = dist(p[i], p[j]);
            if (curr_dist < res)
                res = curr_dist;
        }
    }
    return res;  
}

// A utility function to find the distance beween the closest points of strip of given size. 
// All points in p[] are sorted accordint to y coordinate. 
// They all have an upper bound on minimum distance as d. 
float strip_closest(point p[], int n, float d) {
    float res = d;
    heap_sort(p, n, &compareY);
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && (p[j].y - p[i].y) < res) {
            float curr_dist = dist(p[i], p[j]);
            if (curr_dist < res)
                res = curr_dist;
            j++;
        }
    }
    return res;
}

// A recursive function to find the smallest distance. 
// The array P contains all points sorted according to x coordinate  
float get_closest_pair(point p[], int n) {
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return brute_force(p, n);
    // Find the middle point
    int mid = n / 2;
    point mid_point = p[mid];
    // Consider the vertical line passing through the middle point calculate  
    // the smallest distance dl on left of middle point and dr on right side 
    float d_left  = get_closest_pair(p, mid);
    float d_right = get_closest_pair(p + mid, n - mid);
    // Find the smaller of two distances
    float d = min(d_left, d_right);
    // Build an array strip[] that contains points close (closer than d)  
    // to the line passing through the middle point  
    point *strip = new point[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(p[i].x - mid_point.x) < d) {
            strip[j] = p[i];
            j++;
        }
    }
    // Find the closest points in strip.  
    // Return the minimum of d and closest distance is strip[]  
    return min(d, strip_closest(strip, j, d));
}

float closest_pair(point p[], int n) {
    heap_sort(p, n, &compareX);
    return get_closest_pair(p, n);
}

int main() {

    int n = 6;
    point p[]  = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    cout << "The smallest distance is " << closest_pair(p, n);

}