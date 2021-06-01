#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define Nmax 10
int main()
{

    int k = 0, i, j, n; //n =5
    double a[Nmax][Nmax],
    b[Nmax] ;
    double d, eps, max, R, X0[Nmax], X[Nmax], M[Nmax][Nmax], C[Nmax]; //eps = 1e-9
    printf("Dati rangul sistemului: ");
    scanf("%d",&n);
    printf("\nDati elementele matricei: \n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    scanf("%lf",&a[i][j]);
    printf("\nDati coloana termenilor liberi: \n");
    for(i=0;i<n;i++)
    scanf("%lf",&b[i]);
    printf("\nIntroduceti precizia de calcul: \n");
    scanf("%lf", &eps);

    printf("\n Sistemul initial\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%8.2lf", a[i][j]);
        printf(" | %8.2lf\n", b[i]);
    }

    for (i = 0; i < n; i++) {
        M[i][i] = 0;
        for (j = 0; j < n; j++)
            if (j != i)
                M[i][j] = -a[i][j] / a[i][i];
        C[i] = b[i] / a[i][i];
    }
    printf("\n Matricea M si Vetorul C \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%8.2lf", M[i][j]);
        printf(" | %8.2lf\n", C[i]);
    }
    max = 0;
    for (i = 0; i < n; i++) {
        d = 0;
        for (j = 0; j < n; j++)
            d += fabs(M[i][j]);
        if (d > max)
            max = d;
    }
    if (max > 1) {
        printf("Nu sunt satisfacute conditiile de convergenta");
    }
    //Procesul iterativ

    do {
        k++;
        max = 0;
        for (i = 0; i < n; i++) {
            X[i] = C[i];
            for (j = 0; j < n; j++)
                X[i] += M[i][j] * X0[j];
            d = fabs(X[i] - X0[i]);
            if (d > max)
                max = d;
        }
        for (i = 0; i < n; i++)
            X0[i] = X[i];
             printf("\nAproximatia a %d a solutiei este\n", k);
    for (i = 0; i < n; i++)
        printf("%8.3lf", X[i]);
    printf("\n");
    } while (max >= eps);


    //R = ax-b
    printf("\n Verificare\n");
    for (i = 0; i < n; i++) {
        R = -b[i];
        for (j = 0; j < n; j++)
            R += a[i][j] * X[j];
        printf(" %8.16e", R);
    }
    printf("\n");
    getch();
}

