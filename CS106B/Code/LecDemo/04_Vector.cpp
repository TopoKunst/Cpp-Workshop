#include <iostream>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "grid.h"
#include "vector.h"
#include <string>
using namespace std;

void vectorGridExamples();
void printGrid(Grid<char> &grid);
void eliminateNegativity(Vector<int>& v);



int main() {
    for (int i = 10; i > 0; i--){
        cout << i << endl;
    }
    cout << "Liftoff!" << endl;

    cout << "This program greets users with a personalized message." << endl;
    string name = getLine("Please enter your name: ");
    string food = getLine("Please enter your favorite food: ");
    cout << "Hello " << name << ", it's so nice to meet you!" << endl;
    cout << "Would you like some " << food << " to eat?" << endl;

    cout << "This program prints squares of numbers." << endl;
    while (true) {
        string inputStr = getLine("Please enter the number you would like squared (ENTER/RETURN to quit): ");
        if (inputStr == "") break;
        int inputNum = stringToInteger(inputStr);
        cout << "The square of " << inputNum << " is " << inputNum * inputNum << "." << endl;
    }
    cout << "Done squaring numbers!" << endl;

    vectorGridExamples();

    Vector<int> nums = {1, -4, 18, -11};
    eliminateNegativity(nums);
    cout << nums << endl;

    return 0;
}

void eliminateNegativity(Vector<int>& v){
    for (int i = 0; i < v.size(); i++){
        if (v[i] < 0){
            v[i] = -1 * v[i];
        }
    }
}


void vectorGridExamples() {
    Vector<int> vec; // creates an empty vector that can be populated with ints.
    Vector<string> stringVec; // creates a vector for strings

    // slide 10
    Vector<int> magic;
    magic.add(4);
    magic.add(8);
    magic.add(15);
    magic.add(16);
    cout << magic[2] << endl; // prints 15

    // slide 11
    for(int i = 0; i < magic.size(); i++) {
        cout << magic[i] << endl;
    }

    // slide 12: a new type of for loop
    for(int value : magic) {
        cout << value << endl;
    }

    // slide 16
    Grid<int> matrix(2,2);
    matrix[0][0] = 42;
    matrix[0][1] = 6;
    matrix[1][0] = matrix[0][1];
    cout << matrix.numRows() << endl;
    cout << matrix[0][1] << endl;
    cout << matrix[1][1] << endl;
    // cout << matrix[2][3] << endl; // CRASH!! Out of bounds
    // instead:
    if (matrix.inBounds(2,3)) {
        cout << matrix[2][3] << endl; // won't make it here
    }

    const int NUM_COLUMNS = 2;
    Grid<char> alphaGrid(3, 2);
    for (char c = 'a'; c <= 'f'; c++) {
        int row = (c - 'a') / NUM_COLUMNS;
        int col = (c - 'a') % NUM_COLUMNS;
        alphaGrid[row][col] = c;
    }

    printGrid(alphaGrid);
}

// slide 18
void printGrid(Grid<char> &grid) {
    for(int r = 0; r < grid.numRows(); r++) {
        for(int c = 0; c < grid.numCols(); c++) {
            cout << grid[r][c];
        }
        cout << endl;
    }
}
