// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <limits>
#include <fstream>

// ---------- DEFINE CONSTANTS ----------
#define NAME_LENGHT 10
#define ARRAY_SIZE 3

using namespace std;

// ---------- DEFINE STRUCTURES ----------
struct Dog{
    char name[NAME_LENGHT];
    int age;
    double mass;
};

// ---------- DEFINE FUNCTIONS ----------
void menu();
Dog set1();
Dog set2(const char name[], int age, double mass);
void fillArray(Dog dogs[], int dogsSize);
void displayArray(const Dog dogs[], int dogsSize);
void get1(const Dog& dog);
void saveToFile(const Dog dogs[], int dogsSize);

// ---------- MAIN ----------
int main(int argc, char *argv[]){

    Dog dog1;
    Dog doggies[ARRAY_SIZE];
    int age, choice;
    double mass;
    bool singleFilled = false, arrayFilled = false;

    while (true){
        menu();
        while (true){
            cin >> choice;
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Twoj wybor powinien byc liczba calkowita!" << endl;
                cout << "Wybierz: ";
            }
            else break;
        }

        switch (choice){
            case 1:
                clog << endl << "Wypelnianie przy pomocy set1():" << endl;
                dog1 = set1();
                clog << endl << "Informacje zostaly zapisane." << endl;
                singleFilled = true;
                break;
            case 2:
                if (!singleFilled){
                    cerr << endl  << "Najpierw wypelnij informacje!" << endl;
                    break;
                }
                get1(dog1);
                break;
            case 3:
                clog << endl << "Wypelnianie przy pomocy set1():" << endl;
                doggies[0] = set1();
                fillArray(doggies, ARRAY_SIZE);
                clog << endl << "Informacje zostaly zapisane." << endl;
                arrayFilled = true;
                break;
            case 4:
                if (!arrayFilled){
                    cerr << "Najpierw wypelnij tabele!" << endl;
                    break;
                }
                displayArray(doggies, ARRAY_SIZE);
                break;
            case 5:
                if (!arrayFilled){
                    cerr << endl << "Najpierw wypelnij tabele!" << endl;
                    break;
                }
                saveToFile(doggies, ARRAY_SIZE);
                break;
            case 0:
                clog << "Zamykanie programu..." << endl;
                return 0;
            default:
                cerr << endl << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
        cout << endl;
    }

    return 0;
}

// ---------- FUNCTIONS ----------
void menu(){
    cout << "----------------------------------------------" << endl;
    cout << "-             Co chcesz zrobic ?             -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1. Wypelnij pojednynczy obiekt" << endl;
    cout << "2. Wyswietl pojednynczy obiekt" << endl;
    cout << "3. Wypelnij tablice" << endl;
    cout << "4. Wyswietl tablice" << endl;
    cout << "5. Zapisz imiona psow do pliku" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "Wybierz: ";
}

Dog set1(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Dog dog;

    cout << "Podaj imie psa: ";
    while (true){
        cin.getline(dog.name, NAME_LENGHT);

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Imie psa powinno miec " << NAME_LENGHT - 1 << " znakow!" << endl;
            cout << "Podaj imie psa: ";
        }
        else break;
    }

    cout << "Podaj wiek psa: ";
    while (true){
        cin >> dog.age;

        if (cin.fail() || dog.age <= 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wiek musi byc liczba calkowita nieujemna!" << endl;
            cout << "Podaj wiek psa: ";
        }
        else break;
    }

    cout << "Podaj mase psa: ";
    while (true){
        cin >> dog.mass;

        if (cin.fail() || dog.mass <= 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masa psa musi byc liczba nieujemna!" << endl;
            cout << "Podaj mase psa: ";
        }
        else break;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return dog;
}

Dog set2(const char name[], int age, double mass){
    Dog dog;

    clog << endl << "Wypelnianie przy pomocy set2()." << endl;
    for (int i = 0; i < NAME_LENGHT; i++){
        dog.name[i] = name[i];
    }
    dog.age = age;
    dog.mass = mass;

    return dog;
}

void fillArray(Dog dogs[], int dogsSize){
    char name[NAME_LENGHT];
    int age;
    double mass;

    for (int i = 1; i < dogsSize; i++){
        cout << endl << "Podaj imie psa: ";
        while (true){
            cin.getline(name, NAME_LENGHT);
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << endl << "Imie psa nie moze miec wiecej niz " << NAME_LENGHT - 1 << " liter!" << endl;
                cout << "Podaj imie psa: ";
            }
            else break;
        }

        cout << "Podaj wiek psa: ";
        while (true){
            cin >> age;
            if (cin.fail() || age <= 0){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << endl <<  "Wiek musi byc liczba calkowita nieujemna!" << endl;
                cout << "Podaj wiek psa: ";
            }
            else break;
        }

        cout << "Podaj mase psa: ";
        while (true){
            cin >> mass;
            if (cin.fail() || mass <= 0){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << endl <<  "Masa musi byc liczba nieujemna!" << endl;
                cout << "Podaj mase psa: ";
            }
            else break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        dogs[i] = set2(name, age, mass);
    }
}

void displayArray(const Dog dogs[], int dogsSize) {
    for (int i = 0; i < dogsSize; i++) {
        get1(dogs[i]);
    }
}

void get1(const Dog& dog) {
    cout << endl << "Pies " << dog.name << " ma " << dog.age << " lat(a) i wazy " << dog.mass << " kg." << endl;
}

void saveToFile(const Dog dogs[], int dogsSize){
    ofstream outputFile("names.txt");
    if (outputFile.is_open()){
        for (int i = 0; i < dogsSize; i++){
            outputFile << "Imie psa: " << dogs[i].name << endl;
        }
        clog << endl << "Imiona zostaly wpisane." << endl;
        outputFile.close();
    }
    else {
        cerr << "Blad przy zapisie pliku!" << endl;
    }
}
