// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <cmath>

// ---------- DEFINE CONSTANTS ----------
#define SUCCES 0
#define FAILURE 0

// ---------- DEFINE FUNCTIONS ----------
void menu();

using namespace std;

// ---------- MAIN ----------
int main(int argc, char *argv[]){

    double angle(0.0), sinus(0.0);
    char choice;

    while(true){
        menu();
        cin >> choice;

        if (choice == 'q' || choice == 'Q'){
            cout << "Zamykanie programu" << endl;
            return SUCCES;
        }

        cout << "Podaj kat: ";
        cin >> angle;

        switch (choice){
            case 's':
            case 'S':
                angle = angle * M_PI / 180.0;

            case 'r':
            case 'R':
                // Angle is already in radians.
            break;

            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
            break;
        }

        sinus = sin(angle);
        cout << "Sin kata " << angle << " to: " << sinus << endl << endl;
    }
    return FAILURE;
}

// ---------- FUNCTIONS ----------
void menu(){
    cout << "Wybierz jednostke kata" << endl;
    cout << "----------------------" << endl;
    cout << "\"R\" - Radiany" << endl;
    cout << "\"S\" - Stopnie" << endl;
    cout << "\"Q\" - Koniec programu" << endl;
    cout << "Wybierz: ";
}
