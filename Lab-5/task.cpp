// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

// ---------- DEFINE CONSTANTS ----------
#define SUCCES 0
#define FAILURE 1
#define GRADES_ARRAY_SIZE 100
#define GRADES_COUNT_ARRAY_SIZE 11

using namespace std;

// ---------- DEFINE FUNCTIONS ----------
void menu();
void generateArray(int[]);
void displayArray(int[]);
double calculateMean(int[]);
void copyArray(int[], int[]);
void sortArray(int[]);
double calculateMedian(int[]);
void calculateGradesCount(int[], int[]);
void clearArray(int[], int);
vector<int> gradesFrequency(int[]);
void displayHistogram(int[]);

// ---------- MAIN ----------
int main(int argc, char *argv[]){

    int choice;
    int gradesArray[GRADES_ARRAY_SIZE];
    int sortedArray[GRADES_ARRAY_SIZE];
    int gradesCount[GRADES_COUNT_ARRAY_SIZE] = {0};
    int indeces[GRADES_COUNT_ARRAY_SIZE] = {0};
    vector<int> maxIndicies;

    generateArray(gradesArray);

    while(true){
        menu();
        cin >> choice;

        switch(choice){
            case 1:
                generateArray(gradesArray);
                cout << "Tablica wylosowana" << endl;
            break;
            case 2:
                displayArray(gradesArray);
            break;
            case 3:
                cout << "Srednia z ocen to: " << calculateMean(gradesArray) << endl;
            break;
            case 4:
                copyArray(gradesArray, sortedArray);
                sortArray(sortedArray);
                displayArray(sortedArray);
            break;
            case 5:
                cout << "Mediana ocen to: " << calculateMedian(sortedArray) << endl;
            break;
            case 6:
                calculateGradesCount(gradesArray, gradesCount);
                cout << "Liczba poszczegolnych ocen:" << endl;
                for (int i = 0; i < 11; i++){
                    cout << setw(4) << "Ocena " << i << ": " << gradesCount[i] << " razy" << endl;
                }
            break;
            case 7:
                maxIndicies = gradesFrequency(gradesCount);
                cout << "Najczestsze oceny to:" << endl;
                for (int index : maxIndicies){
                    cout << index << endl;
                }
            break;
            case 8:
                calculateGradesCount(gradesArray, gradesCount);
                displayHistogram(gradesCount);
            break;
            case 0:
                cout << "Zakmykanie programu!" << endl;
                return SUCCES;
            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
            break;
        }
        cout << endl;
    }
}

// ---------- FUNCTIONS ----------
void menu(){
    cout << "-----------------------------------------------" << endl;
    cout << "-              Co chcesz zrobic ?             -" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "1. Ponownie wylosuj tablice" << endl;
    cout << "2. Wyswietl tablice" << endl;
    cout << "3. Oblicz srednia z ocen" << endl;
    cout << "4. Wyswietl posortowana tablice" << endl;
    cout << "5. Oblicz mediane tablicy" << endl;
    cout << "6. Oblicz ile studentow przyznalo kazda z ocen" << endl;
    cout << "7. Oblicz ktore oceny byly najczestsze" << endl;
    cout << "8. Wyswietl histogram" << endl;
    cout << "0. Zakoncz program" << endl;
    cout << "Wybierz: ";
}

void generateArray(int grades[]){
    srand(time(NULL));

    for (int i = 0; i < GRADES_ARRAY_SIZE; i++){
        grades[i] = rand() % 11;
    }
}

void displayArray(int grades[]){
    for (int i = 0; i < GRADES_ARRAY_SIZE; i++){
        if (i % 20 == 0) cout << endl;
        cout << setw(4) << grades[i];
    }
}

double calculateMean(int grades[]){
    double mean(0.0);

    for(int i = 0; i < GRADES_ARRAY_SIZE; i++){
        mean += grades[i];
    }
    return mean / GRADES_ARRAY_SIZE;
}

void copyArray(int source[], int destination[]){
    for (int i = 0; i < GRADES_ARRAY_SIZE; i++){
        destination[i] = source[i];
    }
}

void sortArray(int copiedArray[]){
    for (int i = 0; i < GRADES_ARRAY_SIZE; i++){
        for (int j = 0; j < GRADES_ARRAY_SIZE - i - 1; j++){
            if (copiedArray[j] > copiedArray[j + 1]){
                int temp = copiedArray[j];
                copiedArray[j] = copiedArray[j + 1];
                copiedArray[j + 1] = temp;
            }
        }
    }
}

double calculateMedian(int grades[]){
    double median;

    if (GRADES_ARRAY_SIZE % 2 == 1) median = grades[GRADES_ARRAY_SIZE / 2 + 1];
    else median = (grades[GRADES_ARRAY_SIZE / 2] + grades[GRADES_ARRAY_SIZE / 2 + 1]) / 2;

    return median;
}

void calculateGradesCount(int grades[], int gradesCount[]){
    clearArray(gradesCount, GRADES_COUNT_ARRAY_SIZE);

    for (int i = 0; i < GRADES_ARRAY_SIZE; i++){
        gradesCount[grades[i]]++;
    }
}

void clearArray(int givenArray[], int arraySize){
    for (int i = 0; i < arraySize; i++){
        givenArray[i] = 0;
    }
}

vector<int> gradesFrequency(int gradesFrequency[]){
    int highest = gradesFrequency[0];
    vector<int> indicies;

    for (int i = 1; i < GRADES_COUNT_ARRAY_SIZE; i++){
        if(gradesFrequency[i] > highest) highest = gradesFrequency[i];
    }

    for (int i = 0; i < GRADES_COUNT_ARRAY_SIZE; i++){
        if (gradesFrequency[i] == highest) indicies.push_back(i);
    }

    return indicies;
}

void displayHistogram(int gradesCount[]){
    int maxCount = 0;

    for (int i = 0; i < GRADES_COUNT_ARRAY_SIZE; i++){
        if(gradesCount[i] > maxCount) maxCount = gradesCount[i];
    }

    for(int level = maxCount; level > 0; level--){
        for(int i = 0; i < GRADES_COUNT_ARRAY_SIZE; i++){
            if(gradesCount[i] > level)
                cout << setw(4) << "*";
            else
                cout << setw(4) << " ";
        }
        cout << endl;
    }

    cout << setw(4 * GRADES_COUNT_ARRAY_SIZE) << setfill('-') << "" << setfill(' ') << endl;

    for (int i = 0; i < GRADES_COUNT_ARRAY_SIZE; i++){
        cout << setw(4) << i;
    }

    cout << endl << endl;
}

