#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n = 10;
    double x[n][n];
    double y[n][n];
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            //generate random number between [-pi, pi] and use the time as seed
            x[i][j] = (double)rand() / RAND_MAX * 2 * M_PI - M_PI;
            y[i][j] = (double)rand() / RAND_MAX * 2 * M_PI - M_PI;
        }
    }
    //transpose the y array
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            y[i][j] = y[j][i];
    //matrix multiplication
    double z[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            z[i][j] = 0;
            for (int k = 0; k < n; k++)
                z[i][j] += x[i][k] * y[k][j];
        }
    return 0;
}