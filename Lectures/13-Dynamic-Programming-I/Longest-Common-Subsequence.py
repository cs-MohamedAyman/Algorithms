N = int(1e3+3)

memo = [[-1 for i in range(N)] for j in range(N)]

def lcs(X, Y, m, n):
    if m == -1 or n == -1:
        return 0
    if memo[m][n] != -1:
        return memo[m][n]
    if X[m] == Y[n]:
        memo[m][n] = 1 + lcs(X, Y, m-1, n-1)
        return memo[m][n]
    else:
        choice1 = lcs(X, Y, m, n-1)
        choice2 = lcs(X, Y, m-1, n)
        memo[m][n] = max(choice1, choice2)
        return memo[m][n]

dp = [[-1 for i in range(N)] for j in range(N)]

def lcs_iterative(X, Y, m, n):
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif X[i-1] == Y[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[m][n]

def print_solution(X, Y, m, n):
    # Following code is used to print LCS
    res = dp[m][n]
    # Create a character array to store the lcs string
    lcs_res = [''] * res
    # Start from the right-most-bottom-most corner and 
    # one by one store characters in lcs[] 
    i, j = m, n
    while i > 0 and j > 0:
        # If current character in X and Y are same, then current character is part of LCS 
        if X[i-1] == Y[j-1]:
            # Put current character in result
            lcs_res[res-1] = X[i-1]
            # reduce values of i, j and index
            i -= 1
            j -= 1
            res -= 1
        # If not same, then find the larger of two and go in the direction of larger value 
        elif dp[i-1][j] > dp[i][j-1]:
            i -= 1
        else:
            j -= 1
    print("LCS of", X, "and", Y, "is", ''.join(lcs_res))

X = "AGGTAB"
Y = "GXTXAYB"
m = len(X)
n = len(Y)
print("(Recursive) Length of LCS is", lcs(X, Y, m-1, n-1))
print("(Iterative) Length of LCS is", lcs_iterative(X, Y, m, n))
print_solution(X, Y, m, n)
