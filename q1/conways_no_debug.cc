#include <iostream>
#include <string>
using namespace std;


#define DEBUG (1)


void printGrid(char **grid, int rowCount, int colCount) {
    #if DEBUG == 1
    cout << "DEBUG: printGrid called" << endl;
    #endif
    for(int i = 0; i < colCount; ++i) cout << "|";
    cout << endl;
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    for(int i = 0; i < colCount; ++i) cout << "|";
    cout << endl;
}

void stepGrid(char **grid, int rowCount, int colCount) {
    #if DEBUG == 1
    cout << "DEBUG: stepGrid called" << endl;
    #endif

    int neighbors = 0;
    char newCell = '.'; 
    int hMin = 0; // horizontal min
    int hMax = 0; // horitzontal max
    int vMin = 0; // verticle min
    int vMax = 0; // verticle max

    //allocate new grid
    char **newGrid = new char*[rowCount];
    for(int i = 0; i < rowCount; ++i) {
        newGrid[i] = new char[colCount];
    }

    //iterate through each current cell, check if it should live or die
    //all changes are performed to newGrid
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {

            // NEW APPROACH: whether live or dead, count live neighbors
            // then, based on if it is live or dead, apply rules
            neighbors = 0;
            hMin = 0;
            hMax = 0;
            vMin = 0;
            vMax = 0;

            // count cells
            // first, determine the bounds to check for neighbors in (don't look out of bounds)
            // top row
            if(i == 0) vMin = 0;
            else vMin = -1;
            // bottom row
            if(i == rowCount-1) vMax = 0;
            else vMax = 1;
            // leftmost column
            if(j == 0) hMin = 0;
            else hMin = -1;
            // rightmost column
            if(j == colCount-1) hMax = 0;
            else hMax = 1;

            // count neighbors
            // note: if cell is live, it counts itself
            for(int a = vMin; a <= vMax; a++) {
                for(int b = hMin; b <= hMax; b++) {
                    if(grid[i+a][j+b] == 'O') neighbors++;
                }
            }
            
            // apply rules for live cells
            if(grid[i][j] == 'O') {
                neighbors--; //subtract self count
                // underpopulation and overpupulation
                if(neighbors < 2 || neighbors > 3) {
                    newCell = '.';
                }
                // 2 or 3 neighbors, cell lives
                else newCell = 'O';
            }

            // apply reproduction for dead cells
            if(grid[i][j] == '.') {
                if(neighbors == 3) {
                newCell = 'O';
                } else newCell = '.';
            }
            newGrid[i][j] = newCell;
            #if DEBUG == 1
            if(grid[i][j] != newCell) cout << "DEBUG: grid[" << i << "][" << j << "] is " << grid[i][j] << ", has neighbors = " << neighbors << " and is becoming " << newCell << endl;  
            cout << "DEBUG: newGrid[" << i << "][" << j << "] is " << newGrid[i][j] << endl;
            #endif
            
        }
    }

    // Free memory, make grid = newGrid
    /*
    for(int i = 0; i < rowCount; ++i) {
        delete[] grid[i]; 
    }
    delete[] grid;
    */
    grid = newGrid;
}

int main() {
    string input;
    int rowMax = 2;
    int rowCount = 0;
    int colCount = 0;
    char current = ' ';
 
    // Initial grid allocation
    char **grid = new char*[rowMax];

    // Initial input (determine grid width)
    cin >> input;
    while(current != '\0') {
        colCount++;
        current = input[colCount];
    }

    // Allocate memory for and store characters in first row
    grid[0] = new char[colCount];
    for(int i = 0; i < colCount; ++i) grid[0][i] = input[i];
    rowCount++;
    
    #if DEBUG == 1
    cout << "DEBUG: first allocation ran" << endl;
    cout << "DEBUG: rowCount = " << rowCount << endl;
    #endif

    // Build grid
    while(cin >> input) {
        if(input[0] == 'x') {
            #if DEBUG == 1
            cout << "DEBUG: x recieved, ending grid build" << endl;
            #endif
            break;
        }
        if(rowCount == rowMax) {
            #if DEBUG == 1
            cout << "DEBUG: grid growing..." << endl;
            cout << "DEBUG: rowCount = " << rowCount << endl;
            #endif
            rowMax = rowMax*2;
            char **newGrid = new char*[rowMax];
            for(int i = 0; i < rowCount; ++i) {
                newGrid[i] = grid[i]; 
            }
            #if DEBUG == 1
            cout << "DEBUG: elements finished copying" << endl;
            #endif
            delete[] grid;
            grid = newGrid;
            #if DEBUG == 1
            cout << "DEBUG: old grid deletion complete" << endl;
            cout << "DEBUG: rowCount = " << rowCount << endl;
            #endif
        }
        grid[rowCount] = new char[colCount];
        #if DEBUG == 1
        cout << "DEBUG: row allocated" << endl;
        #endif
        for(int i = 0; i < colCount; ++i) {
            #if DEBUG == 1
            //cout << "DEBUG: adding element " << i << " to grid" << endl;
            #endif
            grid[rowCount][i] = input[i];
        }
        rowCount++;
        #if DEBUG == 1
        cout << "DEBUG: rowCount = " << rowCount << endl;
        #endif
    }
    
    // Read p (print) and s (step)
    while(cin >> input) {
        int c = 0;
        while(input[c] != '\0') c++;
        for(int i = 0; i < c; i++) {
            if(input[i] == 'p') printGrid(grid, rowCount, colCount);
            if(input[i] == 's') stepGrid(grid, rowCount, colCount);
        }
    }
    return 0;
}