#include <iostream>
#include <string>
using namespace std;



void printBoard() {

}



int main() {
    string input;
    int width = 0;
    char current = ' ';
    int rows = 0;
    int height = 0;
    int cols = 0;


    // Take initial input, count width. Assume all consecutive rows will match
    cin >> input;
    while(current != '\0') {
        current = input[width];
        //cout << "current = " << current << endl;
        width++;
    }
    //cout << "input: " << input <<  endl;
    //cout << "width: " << width << endl;


    // Allocate space for row
    char **grid = new char*[width];
    cols = width;

    // Initialize size of columns to 2 and
    // add first input to grid
    for(int i = 0; i < width; ++i) {
        grid[i] = new char[2];
        rows = 1;
        height = 2;
        grid[0][i] = input[i];
        cout << grid[0][i];
    }


    /
    // Take all inputs after second, elements to column arrays in order
    while(cin >> input) {
        if (input == "x") break;
        
        if (rows == height) {
            for (int i = 0; i < width; ++i) {
                // = new char[2*rows];
                rows = 1;
                height = 2;
                grid[0][i] = input[i];
                cout << grid[0][i];
            }


        
            grid[cols] = input[i];
        }
        } else {
            for(int i = 0; i < width; ++i) {
            grid[cols] = input[i]
            }
            rows++;
        }

    }
    
    return 0;
}