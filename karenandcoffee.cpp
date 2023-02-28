#include <bits/stdc++.h>
#define N 200005
using namespace std;
vector<int> recipe(N, 0);
int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    for (int i = 0; i < a; i++)
    {
        int l, r;
        cin >> l >> r;
        recipe[l]++;
        recipe[r + 1]--;
    }
    for (int i = 1; i < N; i++)
    {
        recipe[i] += recipe[i - 1];
    }
    recipe[0] = 0;
    for (int i = 1; i < N; i++)
    {
        recipe[i] = recipe[i - 1] + (recipe[i] >= b ? 1 : 0);
    }
    for (int i = 0; i < c; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << recipe[r] - recipe[l - 1] << endl;
    }
}