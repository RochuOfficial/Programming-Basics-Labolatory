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
void generateArray(int[], int);
void displayArray(int[], int);
double calculateMean(int[], int);
void copyArray(int[], int[], int);
void sortArray(int[], int);
double calculateMedian(int[], int);
void calculateGradesCount(int[], int[], int);
void clearArray(int[], int);
vector<int> gradesFrequency(int[], int);
void displayHistogram(int[], int);

// ---------- MAIN ----------
int main(int argc, char *argv[]){

    int choice;
    int gradesArray[GRADES_ARRAY_SIZE];
    int sortedArray[GRADES_ARRAY_SIZE];
    int gradesCount[GRADES_COUNT_ARRAY_SIZE] = {0};
    int indeces[GRADES_COUNT_ARRAY_SIZE] = {0};
    vector<int> maxIndicies;

    generateArray(gradesArray, GRADES_ARRAY_SIZE);

    while(true){
        menu();
        cin >> choice;

        switch(choice){
            case 1:
                generateArray(gradesArray, GRADES_ARRAY_SIZE);
                cout << "Tablica wylosowana" << endl;
            break;
            case 2:
                displayArray(gradesArray, GRADES_ARRAY_SIZE);
            break;
            case 3:
                cout << "Srednia z ocen to: " << calculateMean(gradesArray, GRADES_ARRAY_SIZE) << endl;
            break;
            case 4:
                copyArray(gradesArray, sortedArray, GRADES_ARRAY_SIZE);
                sortArray(sortedArray, GRADES_ARRAY_SIZE);
                displayArray(sortedArray, GRADES_ARRAY_SIZE);
            break;
            case 5:
                cout << "Mediana ocen to: " << calculateMedian(sortedArray, GRADES_ARRAY_SIZE) << endl;
            break;
            case 6:
                calculateGradesCount(gradesArray, gradesCount, GRADES_ARRAY_SIZE);
                cout << "Liczba poszczegolnych ocen:" << endl;
                for (int i = 0; i < 11; i++){
                    cout << setw(4) << "Ocena " << i << ": " << gradesCount[i] << " razy" << endl;
                }
            break;
            case 7:
                maxIndicies = gradesFrequency(gradesCount, GRADES_COUNT_ARRAY_SIZE);
                cout << "Najczestsze oceny to:" << endl;
                for (int index : maxIndicies){
                    cout << index << endl;
                }
            break;
            case 8:
                calculateGradesCount(gradesArray, gradesCount, GRADES_ARRAY_SIZE);
                displayHistogram(gradesCount, GRADES_COUNT_ARRAY_SIZE);
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

void generateArray(int grades[], int arraySize){
    srand(time(NULL));

    for (int i = 0; i < arraySize; i++){
        grades[i] = rand() % 11;
    }
}

void displayArray(int grades[], int arraySize){
    for (int i = 0; i < arraySize; i++){
        if (i % 20 == 0) cout << endl;
        cout << setw(4) << grades[i];
    }
}

double calculateMean(int grades[], int arraySize){
    double mean(0.0);

    for(int i = 0; i < arraySize; i++){
        mean += grades[i];
    }
    return mean / arraySize;
}

void copyArray(int source[], int destination[], int arraySize){
    for (int i = 0; i < arraySize; i++){
        destination[i] = source[i];
    }
}

void sortArray(int copiedArray[], int arraySize){
    for (int i = 0; i < arraySize; i++){
        for (int j = 0; j < arraySize - i - 1; j++){
            if (copiedArray[j] > copiedArray[j + 1]){
                int temp = copiedArray[j];
                copiedArray[j] = copiedArray[j + 1];
                copiedArray[j + 1] = temp;
            }
        }
    }
}

double calculateMedian(int grades[], int arraySize){
    double median;

    if (arraySize % 2 == 1) median = grades[arraySize / 2 + 1];
    else median = (grades[arraySize / 2] + grades[arraySize / 2 + 1]) / 2;

    return median;
}

void calculateGradesCount(int grades[], int gradesCount[], int arraySize){
    clearArray(gradesCount, arraySize);

    for (int i = 0; i < arraySize; i++){
        gradesCount[grades[i]]++;
    }
}

void clearArray(int givenArray[], int arraySize){
    for (int i = 0; i < arraySize; i++){
        givenArray[i] = 0;
    }
}

vector<int> gradesFrequency(int gradesFrequency[], int arraySize){
    int highest = gradesFrequency[0];
    vector<int> indicies;

    for (int i = 1; i < arraySize; i++){
        if(gradesFrequency[i] > highest) highest = gradesFrequency[i];
    }

    for (int i = 0; i < arraySize; i++){
        if (gradesFrequency[i] == highest) indicies.push_back(i);
    }

    return indicies;
}

void displayHistogram(int gradesCount[], int arraySize){
    int maxCount = 0;

    for (int i = 0; i < arraySize; i++){
        if(gradesCount[i] > maxCount) maxCount = gradesCount[i];
    }

    for(int level = maxCount; level > 0; level--){
        for(int i = 0; i < arraySize; i++){
            if(gradesCount[i] > level)
                cout << setw(4) << "*";
            else
                cout << setw(4) << " ";
        }
        cout << endl;
    }

    cout << setw(4 * arraySize) << setfill('-') << "" << setfill(' ') << endl;

    for (int i = 0; i < arraySize; i++){
        cout << setw(4) << i;
    }

    cout << endl << endl;
}

