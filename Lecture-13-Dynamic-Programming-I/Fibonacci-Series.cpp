  
#include <bits/stdc++.h>
using namespace std;

int fib_recursion(int n) {
    if (n == 0 || n == 1)
        return n;
    return fib_recursion(n-1) + fib_recursion(n-2);
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

    cout << "fib 7: " << fib_recursion(7) << '\n';
    cout << "fib 6: " << fib_recursion(6) << '\n';
    cout << "fib 5: " << fib_recursion(5) << '\n';
    cout << "fib 4: " << fib_recursion(4) << '\n';
    cout << "fib 3: " << fib_recursion(3) << '\n';
    cout << "fib 2: " << fib_recursion(2) << '\n';
    
    memset(dp, -1, sizeof dp);
    cout << "fib 7: " << fib_dp(7) << '\n';
    cout << "fib 6: " << fib_dp(6) << '\n';
    cout << "fib 5: " << fib_dp(5) << '\n';
    cout << "fib 4: " << fib_dp(4) << '\n';
    cout << "fib 3: " << fib_dp(3) << '\n';
    cout << "fib 2: " << fib_dp(2) << '\n';
    
}
