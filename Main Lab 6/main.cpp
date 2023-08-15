#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

const int PLATE_SIZE = 10;

void PrintArray(double currentHotPlateVals[PLATE_SIZE][PLATE_SIZE]);
void UpdateArray(double currentHotPlateVals[PLATE_SIZE][PLATE_SIZE], double oldHotPlateVals[PLATE_SIZE][PLATE_SIZE]);
bool CheckForStability(double currentHotPlateVals[PLATE_SIZE][PLATE_SIZE], double oldHotPlateVals[PLATE_SIZE][PLATE_SIZE]);

int main() {
    unsigned int row;
    unsigned int col;
    bool isPlateStable = false;
    double currentHotPlateVals[PLATE_SIZE][PLATE_SIZE];
    double oldHotPlateVals[PLATE_SIZE][PLATE_SIZE];


    for (row = 1; row <= PLATE_SIZE; row++){
        for (col = 1; col <= PLATE_SIZE; col++){
            if ((row != 1 && row != PLATE_SIZE) || (col == 1 || col == PLATE_SIZE)){
                currentHotPlateVals[row - 1][col - 1] = 0.0;
            }
            else{
                currentHotPlateVals[row - 1][col - 1] = 100.0;
            }
        }
    }

    cout << "Hotplate simulator" << endl << endl;
    cout << "Printing the initial plate values..." << endl;
    PrintArray(currentHotPlateVals);
    cout << endl << endl;
    cout << "Printing plate after one iteration..." << endl;
    UpdateArray(currentHotPlateVals, oldHotPlateVals);
    PrintArray(currentHotPlateVals);
    cout << endl << endl;
    cout << "Printing final plate..." << endl;
    while (isPlateStable != true) {
        UpdateArray(currentHotPlateVals, oldHotPlateVals);
        isPlateStable = CheckForStability(currentHotPlateVals, oldHotPlateVals);
    }
    PrintArray(currentHotPlateVals);
    cout << endl;

    cout << "Writing final plate to \"Hotplate.csv\"..." << endl << endl;
    //outputting the current array to Hotplate.csv
    ofstream outputPlateFile;
    outputPlateFile.open("Hotplate.csv");
    for (row = 1; row <= PLATE_SIZE; row++){
        for (col = 1; col <= PLATE_SIZE; col++){
            outputPlateFile << fixed << setprecision(3);
            outputPlateFile << setw(9) << right;
            if (col == PLATE_SIZE) {
                outputPlateFile << currentHotPlateVals[row - 1][col - 1];
            }
            else{
                outputPlateFile << currentHotPlateVals[row - 1][col - 1] << ",";
            }
        }
        outputPlateFile << endl;
    }
    outputPlateFile.close();

    cout << "Printing input plate after 3 updates..." << endl;

    ifstream inputPlateFile;
    inputPlateFile.open("Inputplate.txt");

    for (row = 1; row <= PLATE_SIZE; row++){
        for (col = 1; col <= PLATE_SIZE; col++){
            inputPlateFile >> currentHotPlateVals[row - 1][col - 1];
        }
    }
    inputPlateFile.close();
    UpdateArray(currentHotPlateVals, oldHotPlateVals);
    UpdateArray(currentHotPlateVals, oldHotPlateVals);
    UpdateArray(currentHotPlateVals, oldHotPlateVals);
    PrintArray(currentHotPlateVals);


    return 0;
}

void UpdateArray(double currentHotPlateVals[PLATE_SIZE][PLATE_SIZE], double oldHotPlateVals[PLATE_SIZE][PLATE_SIZE]){
    int row = 0;
    int col = 0;

    for (row = 1; row <= PLATE_SIZE; row++){
        for (col = 1; col <= PLATE_SIZE; col++){
            oldHotPlateVals[row - 1][col - 1] = currentHotPlateVals[row - 1][col - 1];
        }
    }

    for (row = 1; row <= PLATE_SIZE; row++){
        for (col = 1; col <= PLATE_SIZE; col++){
            if ((row != 1 && row != PLATE_SIZE) && (col != 1 && col != PLATE_SIZE)){
                double leftVal = oldHotPlateVals[row - 1][col - 2];
                double rightVal = oldHotPlateVals[row - 1][col];
                double upVal = oldHotPlateVals[row - 2][col - 1];
                double downVal = oldHotPlateVals[row][col - 1];
                currentHotPlateVals[row - 1][col - 1] = (leftVal + rightVal + upVal + downVal) / 4.0;
            }
        }
    }
}

void PrintArray(double currentHotPlateVals[PLATE_SIZE][PLATE_SIZE]) {
    unsigned int row;
    unsigned int col;
    cout << fixed << setprecision(3);

    for (row = 1; row <= PLATE_SIZE; ++row) {
        for (col = 1; col <= PLATE_SIZE; ++col) {
            cout << setw(9) << right;
            if (col == PLATE_SIZE) {
                cout << currentHotPlateVals[row - 1][col - 1];
            }
            else{
                cout << currentHotPlateVals[row - 1][col - 1] << ",";
            }
        }
        cout << endl;
    }
}

bool CheckForStability(double currentHotPlateVals[PLATE_SIZE][PLATE_SIZE], double oldHotPlateVals[PLATE_SIZE][PLATE_SIZE]){
    double changeInPlateVal;
    unsigned int row;
    unsigned int col;

    for (row = 1; row <= PLATE_SIZE; ++row) {
        for (col = 1; col <= PLATE_SIZE; ++col) {
            changeInPlateVal = fabs(oldHotPlateVals[row - 1][col - 1] - currentHotPlateVals[row - 1][col - 1]);
            if (changeInPlateVal > 0.1){
                return false;
            }
        }
    }

    return true;
}