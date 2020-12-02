#include <bits/stdc++.h>
using namespace std;

float fast_power(float e, int b) {
    if (b == 0)
        return 1.0;
    if (b % 2 == 1)
        return e * fast_power(e * e, b / 2);
    else
        return fast_power(e * e, b / 2);
}

float fast_power_iterative(float e, int b) {
    float res = 1.0;
    while (b > 0) {
        if (b % 2 == 1)
            res = res * e;
        e = e * e;
        b = b / 2;
    }
    return res;
}

int main() {

    cout << "fast_power 2 ^ 5: " << fast_power(2, 5) << '\n';
    cout << "fast_power 2 ^ 8: " << fast_power(2, 8) << '\n';
    cout << "fast_power 3 ^ 5: " << fast_power(3, 5) << '\n';
    cout << "fast_power 3 ^ 8: " << fast_power(3, 8) << '\n';
    cout << "fast_power 4 ^ 5: " << fast_power(4, 5) << '\n';
    cout << "fast_power 4 ^ 8: " << fast_power(4, 8) << '\n';
    cout << "-------------------------\n";
    cout << "fast_power 2 ^ 5: " << fast_power_iterative(2, 5) << '\n';
    cout << "fast_power 2 ^ 8: " << fast_power_iterative(2, 8) << '\n';
    cout << "fast_power 3 ^ 5: " << fast_power_iterative(3, 5) << '\n';
    cout << "fast_power 3 ^ 8: " << fast_power_iterative(3, 8) << '\n';
    cout << "fast_power 4 ^ 5: " << fast_power_iterative(4, 5) << '\n';
    cout << "fast_power 4 ^ 8: " << fast_power_iterative(4, 8) << '\n';
    
}