#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n = 10;
    double x[n][n];
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            //generate random number between [-pi, pi] and use the time as seed
            x[i][j] = (double)rand() / RAND_MAX * 2 * M_PI - M_PI;
        }
    }
    //replace the array with cosine values
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i][j] = cos(x[i][j]);
    //print the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << x[i][j] << " ";
        cout << endl;
    }
    return 0;

}