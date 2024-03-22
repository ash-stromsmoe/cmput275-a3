#include <iostream>
#include <string>
using namespace std;





void printBoard() {

}



int main() {
    string input;
    int rowMax = 2;
    int rowCount = 0;
    char current = ' ';
    int height = 0;
    int cols = 0;


    
    // Initial grid allocation
    char **grid = new char*[rowMax];
    

    // Build grid
    while(cin >> input) {
        if(rowCount == rowMax) {
            rowMax = rowMax*2;
            char **newGrid = new char*[rowMax];
            for(int i = 0; i < rowCount; ++rowCount) {
                *newGrid[i] = grid[i][0]; 
            }
            delete[] grid;
            grid = newGrid;
        }
        int i = 0;
        while(current != '\0') {
            current = input[i];
            grid[rowCount][i] = input[i];
            i++;
        }

    }
    



    return 0;
}