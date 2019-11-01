#include <bits/stdc++.h>
#include <math.h>

using namespace std;

const int nmax = 1000000 + 7;
int n;

const int MN = 1e6 + 11;
int sieve[MN], se[MN];
pair<int,int> pk[MN];
int ndiv[MN];
int cnt[nmax];
int dp[nmax + 1];
int t;
bool snt[nmax];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void sang() {
    for (int i = 2; i <= 1000; i++)
        if (!sieve[i]) {
            for (int j = i*i; j <= 1000000; j += i) {
                sieve[j] = i;
            }
        }

    ndiv[1] = 1;

    for (int i = 2; i <= 1000000; i++) {
        if (!sieve[i]) {
            pk[i] = make_pair(i, 1);
            ndiv[i] = 2;
        }
        else {
            int p = sieve[i];

            if (pk[i/p].first == p) {
                pk[i] = make_pair(p, pk[i/p].second + 1);
                ndiv[i] = pk[i].second + 1;
            }
            else {
                pk[i] = make_pair(-1, 0);

                int u = i, v = 1;
                while (u % p == 0) {
                    u /= p;
                    v = v * p;
                }
                ndiv[i] = ndiv[u] * ndiv[v];
            }
        }
    }
}

void input() {
    cin >> t;
}

int eulerPhi(int n) { // = n (1-1/p1) ... (1-1/pn)
    if (n == 0) return 0;
    int ans = n;
    for (int x = 2; x*x <= n; ++x) {
        if (n % x == 0) {
            ans -= ans / x;
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

void process(int n) {
    dp[0] = false;
    dp[1] = true;
    for (int i = 2;i <= n;++ i) {
        if (i - 1 >= 0 && !dp[i - 1])
            {dp[i] = true;}
        else if (i - eulerPhi(i) >= 0 && !dp[i - eulerPhi(i)])
            {dp[i] = true;}
        else if (i - (int)log10(i) - 1 >= 0 && !dp[i - (int)log10(i) - 1])
            {dp[i] = true;}
        else
            {dp[i] = false;}
    }
}

int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n != 1) {
        res -= res / n;
    }
    return res;
}

void solve() {
//    phiEuler(100);
    process(1000000);
//    cout << phi(1000000) << "\n" << eulerPhi(1000000) << "\n";
//    for (int i = 1;i <= 999999;++ i) {
//        cout << dp[i] << ", ";
//    }
//    cout << dp[1000000];

    while (t -- ) {
        int n;
        cin >> n;
        if (dp[n]) cout << "BACH\n";
        else cout << "KHOA\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    sang();
    input();
    solve();
    return 0;
}
