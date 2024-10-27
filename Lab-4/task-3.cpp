// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

// ---------- DEFINE CONSTANTS ----------
#define SUCCES 0
#define FAILURE 1

// ---------- DEFINE FUNCTIONS ----------
int rollDice();
void displayStats(int, int);
void win(int&);
void loss(int&);

using namespace std;

// ---------- MAIN ----------
int main(int argc, char *argv[]){

    int randomSum, money(100), points(0);
    char choice;
    bool firstRoll;

    while(true){
        cout << "Chcesz zagrac w gre? (t/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') return SUCCES;
        money = 100;
        points = 0;
        firstRoll = true;

        for (int i = 0; i < 10; i++){
            cout << endl << endl << "****** Runda #" << i+1 <<" ******" << endl;
            randomSum = rollDice();

            if (i == 1) firstRoll = false;

            if((randomSum == 7 || randomSum == 11) && firstRoll){
                cout << "Wygrales bo wyrzuciles " << randomSum << " w 1. rzucie!!!" << endl;
                win(money);
            }
            else if((randomSum == 2 || randomSum == 3 || randomSum == 12) && firstRoll){
                cout << "Przegrales bo wyrztuciles " << randomSum << " w 1. rzucie!!!" << endl;
                loss(money);
            }
            else if(randomSum >= 4 && randomSum <= 10 && randomSum != 7 && randomSum != points){
                points = randomSum;
                cout << "Liczba " << randomSum << " jest teraz twoimi punktami!" << endl;
            }
            else if(randomSum == points){
                cout << "Wygrales bo wyrzules " << randomSum << " 2. raz!!!" << endl;
                win(money);
            }
            else if(randomSum == 7 && !firstRoll){
                cout << "Przegrales bo wyrzuciles 7!!!" << endl;
                loss(money);
            }
            else {
                cout << "Jestes na 0!" << endl;
            }

            displayStats(randomSum, money);
            Sleep(2000);
        }

        Beep(750, 300); Beep(1000, 500);
        cout << endl << endl;
        cout << "------------------------------" << endl;
        cout << "Koniec Gry!" << endl;
        cout << "Po 10 rundach masz " << money << "PLN" << endl;
        if (money > 100) cout << "Gratulacje!" << endl <<"Jestes " << money-100 << "PLN na plusie!" << endl;
        else if(money == 100) cout << "Brawo!" << endl << "Wyszedles na 0!" << endl;
        else cout << "Slabo!" << endl << "Jestes " << 100-money <<"PLN na minusie!" << endl;
    }
}

// ---------- FUNCTIONS ----------

int rollDice(){
    srand(time(NULL));
    return rand() % 11 + 2;
}

void displayStats(int roll, int money){
    cout << "Suma wyrzuconych oczek: " << roll << endl;
    cout << "Masz na koncie " << money << "PLN" << endl;
    cout << endl;
}

void win(int &money){
    Beep(1500, 300);
    money += 30;
}

void loss(int &money){
    Beep(500, 300);
    money -= 20;
}
