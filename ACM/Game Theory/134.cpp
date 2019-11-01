#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 7;

// finds the winning and losing
// states for the 200 stones.
void findStates(int position[], int n)
{
    // 0 means losing state
    // 1 means winning state
    position[0] = 0;
    position[1] = 1;
    position[2] = 0;
    position[3] = 1;
    position[4] = 1;
    position[5] = 1;
    position[6] = 1;
    position[7] = 0;

    // find states for other positions
    for (int i = 8; i <= n; i++) {
        if (!position[i - 1] || !position[i - 3]
            || !position[i - 4])
            position[i] = 1;
        else
            position[i] = 0;
    }
}

// driver function
int main()
{
    freopen("test.inp", "r", stdin);
    int N = 9;
    int position[MAX] = { 0 };

    findStates(position, N);

    if (position[N] == 1)
        cout << "Player 1";
    else
        cout << "Player 2";

    return 0;
}
