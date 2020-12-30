#include <bits/stdc++.h> 
using namespace std; 

int const N = 1e3+3;
int memo[N][N];

int lcs(char *X, char *Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (memo[m-1][n-1] != -1)
        return memo[m-1][n-1];
    if (X[m-1] == Y[n-1]) {
        memo[m-1][n-1] = 1 + lcs(X, Y, m-1, n-1);
        return memo[m-1][n-1];
    }
    else {
        int choice1 = lcs(X, Y, m, n-1);
        int choice2 = lcs(X, Y, m-1, n);
        memo[m-1][n-1] = max(choice1, choice2);
        return memo[m-1][n-1];
    }
}  
  
int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    memset(memo, -1, sizeof memo);
    cout << "Length of LCS is " << lcs(X, Y, m, n);
}
