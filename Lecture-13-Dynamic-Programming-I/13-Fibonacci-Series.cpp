  
#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n == 0 || n == 1)
        return n;
    return fib(n-1) + fib(n-2);
}

const int N = 2e5+3;
int dp[N];

int fib_dp(int n) {
    if (dp[n] != -1)
        return dp[n];
    if (n == 0 || n == 1) {
        dp[n] = n;
        return dp[n];
    }
    dp[n] = fib_dp(n-1) + fib_dp(n-2);
    return dp[n];
}

int main() {
    cout << "fib 7: " << fib(7) << '\n';
    cout << "fib 6: " << fib(6) << '\n';
    cout << "fib 5: " << fib(5) << '\n';
    cout << "fib 4: " << fib(4) << '\n';
    cout << "fib 3: " << fib(3) << '\n';
    cout << "fib 2: " << fib(2) << '\n';
    
    memset(dp, -1, sizeof dp);
    cout << "fib 7: " << fib_dp(7) << '\n';
    cout << "fib 6: " << fib_dp(6) << '\n';
    cout << "fib 5: " << fib_dp(5) << '\n';
    cout << "fib 4: " << fib_dp(4) << '\n';
    cout << "fib 3: " << fib_dp(3) << '\n';
    cout << "fib 2: " << fib_dp(2) << '\n';
}
