// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>

// ---------- DEFINE CONSTANTS ----------
#define SUCCES 0
#define FAILURE 1

// ---------- DEFINE FUNCTIONS ----------
int hcf(int a, int b);
void menu();

using namespace std;

// ---------- MAIN ----------
int main(int argc, char *argv[]){

    int number1(0), number2(0), choice(0), result(0);

    while (true){
        menu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Podaj 1 liczbe: ";
                cin >> number1;
                cout << "Podaj 2 liczbe: ";
                cin >> number2;

                result = hcf(number1, number2);
                cout << "NWD liczb " << number1 << " i " << number2 << " to: " << result << endl;
            break;

            case 0:
                cout << "Zamykanie programu" << endl;
                return SUCCES;

            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
            break;

        }
    }
    return FAILURE;
}

// ---------- FUNCTIONS ----------
int hcf(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void menu(){
    cout << endl << "Co chcesz zrobic?" << endl;
    cout << "-------------------------" << endl;
    cout << "1. Oblicz NWD" << endl;
    cout << "0. Zakoncz program" << endl;
    cout << "Wybierz: ";
}

