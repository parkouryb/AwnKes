
// CPP to find nim-game winner
#include <bits/stdc++.h>
using namespace std;
const int nmax = 100000 + 7;
const int N = 3000000 + 10;
int n;
int a[nmax];
int sg[N];
int m = 1;
long long fibo[N];
int mark[40];

// function to find winner of NIM-game
string findWinner(int A[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= A[i];

    // case when Alice is winner
    if (res == 0 || n % 2 == 0)
        return "Ada";

    // when Bob is winner
    else
        return "Vinit";
}

int solve(int p[], int n)
{
    int G = 0;
    for (int i = 0; i < n; i++) {

        // if pile size is odd
        if (p[i] & 1)

            // We XOR pile size+1
            G ^= (p[i] + 1);

        else // if pile size is even

            // We XOR pile size-1
            G ^= (p[i] - 1);
    }
    return G;
}

// driver program
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    freopen("test.inp",  "r", stdin);

    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2;;++ i) {
//        cout << i << "\n";
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        ++ m;
        if (fibo[i] > N) break;
    }

    sg[0] = 0;

    for (int i = 1;i < N;++ i) {
        for (int j = 0;j < m;++ j) {
            if (fibo[j] <= i) mark[sg[i - fibo[j]]] = 1;
        }

        for (sg[i] = 0; mark[sg[i]]; ++sg[i]);
        for (int j = 0;j < m;++ j) {
            if (fibo[j] <= i) mark[sg[i - fibo[j]]] = 0;
        }
    }
    int res = 0;

    cin >> n;
    for(int i = 0;i < n;++ i) {
        cin >> a[i];
        res ^= sg[a[i]];
    }
    if (res) cout << "Ada\n";
    else cout << "Vinit\n";


//    cout << findWinner(a, n);
    return 0;
}
