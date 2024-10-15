// Mateusz Rochowski, 258669
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    int n = 0;

    cout << "Podaj liczbe: ";
    cin >> n;

    for (int i = 1; i <= n; i++){
        cout << i << ", ";
    }

    cout << endl << endl;

    for (int i = n; i >= 1; i--){
        cout << i << ", ";
    }

    cout << endl << endl;

    for (int i = 1; i <= n; i++){
        if (i % 2 != 0) cout << i << ", ";
    }

    cout << endl << endl;

    for (int i = 1; i <= n; i++){
        if (i % 2 == 0 && i % 3 == 2) cout << i << ", ";
    }

    cout << endl << endl;

    for (int i = 1; i <= n; i++){
        if (i % 5 == 0) cout << i << ", ";
    }

    for (char letter = 'a'; letter <= 'z'; letter++){
        cout << letter << " | ";
    }

    cout << endl << endl;
    system("PAUSE");
    return 0;
}
