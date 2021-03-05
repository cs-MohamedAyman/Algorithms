#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

int coin_change(int* arr, int n, int m) {
    // If n is 0 then there is 1 solution (do not include any coin) 
    if (m == 0)
        return 1;
    // If n is less than 0 then no  solution exists 
    if (m < 0)
        return 0;
    if (memo[n][m] != -1)
        return memo[n][m];
    // If there are no coins and n is greater than 0, then no solution exist
    if (n <=0 && m >= 1)
        return 0;
    // count is sum of solutions
    // (i) including S[m-1]
    // (ii) excluding S[m-1]
    int choice1 = coin_change(arr, n-1, m);
    int choice2 = coin_change(arr, n, m-arr[n-1]);
    memo[n][m] = choice1 + choice2;
    return memo[n][m];
}

int dp[N][N];

int coin_change_iterative(int* arr, int n, int m) {
    // Fill the enteries for 0 value case (n = 0)
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;
    // Fill rest of the table entries in bottom up manner  
    for (int i = 1; i <= m; i++) { 
        for (int j = 0; j < n; j++) {
            int x = 0, y = 0;
            // Count of solutions including arr[j]
            if (i-arr[j] >= 0) 
                x = dp[i-arr[j]][j];
            // Count of solutions excluding arr[j]
            if (j >= 1) 
                y = dp[i][j-1];
            // total count
            dp[i][j] = x + y;
        }
    }
    return dp[m][n-1];
}

int main() {
    int n = 3;
    int arr[] = {1, 2, 3};
    int total_sum = 6;
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) # Coin Change " << coin_change(arr, n, total_sum) << '\n';
    cout << "(Iterative) # Coin Change " << coin_change_iterative(arr, n, total_sum) << '\n';
}
