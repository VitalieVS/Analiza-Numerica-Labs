#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdio.h>

using namespace std;
int i, j, k, n = 5, l;
double u[5][5], ut[5][5], y[3], x[3];
double a[5][5] = {
   {76,1,2,3,4},
   {
       1,75,3,4,4
   },
   {
       2,3,74,4,5
   },
   {
       3,4,3,73,5
   },
   {
       4,4,3,2,72
   }
};
double b[5] = {2,3,4,5,6 };
double sum;
int fun();
int main()
{

    cout << "Sistemul" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            u[i][j] = 0;
            cout << " " << a[i][j] << " ";
        }
        cout << " =" << b[i] << endl;
    }
    l = fun();
    if (l == 1)
        cout << "Nu e corect" << endl;
    system("pause");
}

int fun()
{

    for (j = 0; j < n; j++) {
        sum = 0;
        for (k = 0; k < j; k++) {
           // printf("u%d%d= %8.3lf\n", j, k, u[j][k]);
             sum += u[j][k] * u[j][k];
        }

        //printf("sum%d= %8.3lf\n", j, sum);
        if ((a[j][j] - sum) < 0) {
            return 1;
        }
        u[j][j] = sqrt(a[j][j] - sum);
        if (u[j][j] == 0) {
            return 1;
        }
        for (i = j + 1; i < n; i++) {
            sum = 0;
            for (k = 0; k < j; k++)
                sum += u[i][k] * u[j][k];
            u[i][j] = (a[i][j] - sum) / u[j][j];
             //printf("u%d%d= %8.3lf\n", i, j, u[i][j]);
        }
    }


    cout << "Matricea U" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
                printf(" %8.2lf", u[i][j]);
        }
        cout << endl;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            ut[j][i] = u[i][j];

    y[0] = b[0] / u[0][0];
    for (i = 1; i < n; i++) {
        sum = 0;
        for (j = 0; j < i; j++)
            sum += u[i][j] * y[j];
        y[i] = (b[i] - sum) / u[i][i];
    }

    cout << "Rezultat Y" << endl;

    for (i = 0; i < n; i++) {
        printf(" %8.16lf", y[i]);
    }

    cout << endl;


    x[n-1] = y[n-1] / u[n-1][n-1];

    for (i = n - 2; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++)
            sum += u[j][i] * x[j];
        x[i] = (y[i] - sum) / u[i][i];
    }

    cout << "Rezultat X" << endl;

    for (i = 0; i < n; i++) {
        printf(" %8.16lf", x[i]);
    }

    cout << endl;

    cout << "Verificare" << endl;
    for (i = 0; i < 4; i++) {
        sum = 0;
        for (j = 0; j < 4; j++)
            sum += a[i][j] * x[j];
        cout << sum << endl;
    }
    return 0;
}
