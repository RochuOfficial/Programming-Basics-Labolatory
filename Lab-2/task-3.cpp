// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <cmath>

// ---------- FUNCTIONS DECLARATION ----------
double calculateExp(double x, double eps);

using namespace std;

// ---------- MAIN ----------
int main(int argc, char *argv[]){

    double eps(0.0), x(0.0);

    cout << "Podaj wartosc x: ";
    cin >> x;

    cout << "Podaj wartosc eps (dokladnosc): ";
    cin >> eps;

    double result = calculateExp(x, eps);

    cout << "Wynik e^" << x << " to: " << result << endl;

    cout << endl << endl;
    system("PAUSE");
    return 0;
}

// ---------- FUNCTIONS ----------
double calculateExp(double x, double eps){
    double sum(1.0), term(1.0);
    int i(1);

    while (fabs(term) > eps){
        term *= x/i;
        sum += term;
        i++;
    }

    return sum;
}
