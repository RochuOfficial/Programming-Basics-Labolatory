// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <cmath>

// ---------- DEFINE FUNCTIONS ----------
double calculateSeries(double x, int n);
double factorial (int n);

using namespace std;

// ---------- MAIN ----------
int main(int argc, char *argv[]){

    int n(0);
    double x(0.0);

    cout << "Podaj wartosc x: ";
    cin >> x;

    do {
        cout << "Podaj wartosc N: ";
        cin >> n;

        if (n < 1) cout << "Wartosc N musi byc wieksza od 0!" << endl;
    } while (n < 1);

    double result = calculateSeries(x, n);

    cout << "Wynik szeregu to: " << result << endl;

    cout << endl << endl;
    system("PAUSE");
    return 0;
}

// ---------- FUNCTIONS ----------
double calculateSeries(double x, int n){
    double series(0.0);

    for (int i = 1; i <= n; i++){
        series += (pow(x, i) / factorial(i));
    }

    return series;
}

double factorial (int n){
    double result(1.0);

    for (int i = 1; i <= n; i++){
        result *= i;
    }

    return result;
}







