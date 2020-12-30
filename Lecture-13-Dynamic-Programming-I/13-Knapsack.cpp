#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;

int memo[N][N];

int knapsack(int total_wt, int* wt, int* val, int n) {
    if (n == 0 || total_wt == 0)
        return 0;
    if (memo[total_wt][n] != -1)
        return memo[total_wt][n];
    // If weight of the nth item is more than Knapsack capacity W, 
    // then this item cannot be included in the optimal solution 
    if (wt[n-1] > total_wt) {
        memo[total_wt][n] = knapsack(total_wt, wt, val, n-1);
        return memo[total_wt][n];
    }
    // Return the maximum of two cases: 
    // (1) n-th item included 
    // (2) not included 
    int choice1 = knapsack(total_wt - wt[n-1], wt, val, n-1) + val[n-1];
    int choice2 = knapsack(total_wt, wt, val, n-1); 
    memo[total_wt][n] = max(choice1, choice2);
    return memo[total_wt][n];
}

int dp[N][N];

int knapsack_iterative(int total_wt, int* wt, int* val, int n) {
    // Build table dp[][] in bottom up manner 
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= total_wt; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w) {
                int choice1 = dp[i-1][w-wt[i-1]] + val[i-1];
                int choice2 = dp[i-1][w];
                dp[i][w] = max(choice1, choice2);
            }
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][total_wt];
}

int main() {
    int n = 3;
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int total_wt = 50;
    memset(memo, -1, sizeof memo);
    cout << "(Recursive) knapsack " << knapsack(total_wt, wt, val, n) << '\n';
    cout << "(Iterative) knapsack " << knapsack_iterative(total_wt, wt, val, n) << '\n';
}
