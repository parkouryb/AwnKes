
// Program to find winner of the game
#include <bits/stdc++.h>
using namespace std;

// Function to return find winner of game
string Winner(int n, string pile[])
{

    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        int l = pile[i].length();

        // Piles begins and ends with White box 'W'
        if (pile[i][0] == pile[i][l - 1] && pile[i][0] == 'W')
            a++;

        // Piles begins and ends with Black box 'B'
        if (pile[i][0] == pile[i][l - 1] && pile[i][0] == 'B')
            b++;
    }
    if (a <= b)
        return "A";
    else
        return "B";
}

// Driver code
int main()
{

    int n = 3;
    string pile[n] = { "WWWW", "WBWB", "WBBW" };

    // function to print required answer
    cout << Winner(n, pile);

    return 0;
}
