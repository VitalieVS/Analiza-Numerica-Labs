#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x, char caz = 'a') {
    switch(caz) {
        case 'a': return 2*x + 6; break;
        case 'b': return x*x + 4*x + 55; break;
        case 'c': return x*x*x + 2*x*x + 69*x + 25; break;
        case 'd': return cos(x)/(1 + x*x); break;
    }
}

double df(double x, char caz = 'a') {
    switch(caz) {
        case 'a': return 0; break;
        case 'b': return 2; break;
        case 'c': return 6*x + 4; break;
        case 'd': return -(x*x+1*sin(x)+2*x*cos(x))/(x*x+1)*(x*x+1); break;
    }
}

double Dreptunghi(double a, double b, char caz = 'a') {
    return (b - a) * f((b + a)/2, caz);
}
double eps = 1e-9;
int k; // nr de pasi
double Runge(double a, double b, char caz = 'a') {

    double x, S0, S, h;
    int i;
    k = 1;
    h = b - a;
    S = Dreptunghi(a, b, caz);
    do {
       S0 = S;
       S = 0; x = a;
       k *= 2;
       h /= 2;
       for (i = 1; i <= k; i++) {
         S = S + Dreptunghi(x, x + h, caz);
         x += h;
       }
    } while (fabs(S - S0) > eps);
    return S;
}

int main()
{
    double a = 1, b = 5;
    double S, R, I, x, h;
    int n = 100, i;

    cout << "Proiect nr 4, calculul intergralei" << endl;
    cout << "Elaborat de Sandiuc Vitalie" << endl;
    cout << "Metoda Dreptunghiurilor Centrale" << endl;
    S = Dreptunghi(a, b);
    cout << "a) Valoarea aproximativa a integralei, identica cu cea exacta: " << S << endl;
    h = (b - a)/n;
    x = a; S = 0;
    for ( i = 1; i <= n; i++) {
       S = S + Dreptunghi(x, x + h);
       x += h;
    }
    cout << "Formula generalizata: Valoarea aproximativa a integralei: " << S << endl;

     S = Dreptunghi(a, b, 'b');
     R = pow((b - a), 3) * df(a, 'b')/24;
     I = S + R;
     cout << "b) Valoarea aproximativa a integralei: " << S << endl;
     cout << "Valoarea termenului de rest: " << R << endl;
     cout << "Valoarea exacta a integralei: " << I << endl;

    x = a; S = 0;
    for ( i = 1; i <= n; i++) {
       S = S + Dreptunghi(x, x + h, 'b');
       x += h;
    }
    R = pow((b - a), 3) * df(b, 'b')/(24*n*n);
    I = S + R;
    cout << "Formula generalizata: Valoarea aproximativa a integralei: " << S << endl;
    cout << "Valoarea termenului de rest: " << R << endl;
    cout << "Valoarea exacta a integralei: " << I << endl;
     S = Runge(a, b, 'b');
    cout << "Regula Runge: Valoarea aproximativa a integralei dupa " << k << " diviziuni: " << setprecision(16) << S << endl;

     S = Dreptunghi(a, b, 'c');
     R = pow((b - a), 3) * df(b, 'c')/24;
     I = S + R;
     cout << "c) Valoarea aproximativa a integralei: " << S << endl;
     cout << "Valoarea maximala a termenului de rest: " << R << endl;
     cout << "Valoarea exacta a integralei este intre " << S << " si " << I << endl;

    x = a; S = 0;
    for ( i = 1; i <= n; i++) {
       S = S + Dreptunghi(x, x + h, 'c');
       x += h;
    }
    R = pow((b - a), 3) * df(b, 'c')/(24*n*n);
    I = S + R;
    cout << "Formula generalizata: Valoarea aproximativa a integralei: " << S << endl;
    cout << "Valoarea termenului de rest: " << R << endl;
    cout << "Valoarea exacta a integralei este intre " << S << " si " << I << endl;
    S = Runge(a, b, 'c');
    cout << "Regula Runge: Valoarea aproximativa a integralei dupa " << k << " diviziuni: " << setprecision(16) << S << endl;


     x = a; S = 0;
    for ( i = 1; i <= n; i++) {
       S = S + Dreptunghi(x, x + h, 'd');
       x += h;
    }
    R = pow((b - a), 3) * df(b, 'd')/(24*n*n);
    I = S + R;
    cout << "d) Formula generalizata: Valoarea aproximativa a integralei: " << S << endl;
    cout << "Valoarea termenului de rest: " << R << endl;
    cout << "Valoarea exacta a integralei este intre " << S << " si " << I << endl;

    S = Runge(a, b, 'd');
    cout << "Regula Runge: Valoarea aproximativa a integralei dupa " << k << " diviziuni: " << setprecision(16) << S << endl;

    return 0;
}
