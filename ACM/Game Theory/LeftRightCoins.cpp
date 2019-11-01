#include <bits/stdc++.h>

using namespace std;

const int nmax = 100 + 7;
int t, n;
int a[nmax];
int memo[nmax][nmax];

void input() {
    cin >> t;
}

int findWinner(int *a, int n) {
    int dp[n][n];

    for (int key = 0;key < n;++ key) {
        for (int i = 0, j = key;j < n;++ i, ++ j) {
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and
            // z is F(i, j-2) in above recursive formula
            int x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? dp[i][j - 2] : 0;

            dp[i][j] = max(a[i + 1] + min(x, y), a[j + 1] + min(y, z));
        }
    }

    return dp[0][n - 1];
}

int oSRec(int arr[], int i, int j, int sum)
{
    if (j == i + 1)
        return max(arr[i], arr[j]);

    if (memo[i][j] != -1)
        return memo[i][j];

    // For both of your choices, the opponent
    // gives you total sum minus maximum of
    // his value
    memo[i][j] = max((sum - oSRec(arr, i + 1, j, sum - arr[i])),
                     (sum - oSRec(arr, i, j - 1, sum - arr[j])));

    return memo[i][j];
}

// Returns optimal value possible that a player can
// collect from an array of coins of size n. Note
// than n must be even
int optimalStrategyOfGame(int* arr, int n)
{
    // Compute sum of elements
    int sum = 0;
    sum = accumulate(arr + 1, arr + n + 1, sum);

    // Initialize memoization table
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            memo[i][j] = -1;

    return oSRec(arr, 1, n, sum);
}

void solve() {
    while(t --) {
        cin >> n;
        memset(a, 0,  sizeof(a));
        for (int i = 1;i <= n;++ i) {
            cin >> a[i];
        }
        int res = findWinner(a, n);
        cout << optimalStrategyOfGame(a, n)  << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //freopen("test.inp", "r", stdin);
    input();
    solve();
    return 0;
}
