#include <iostream>
#include <conio.h>
#include <climits>
using namespace std;

int get_val(int dataset[CHAR_MAX+1][CHAR_MAX+1], int n, int size) {
    int maxIndex = 0, maxValue = 0;
    for (int i = 0; i < size; i++) {
        if (dataset[n][i] > maxValue) {
            maxValue = dataset[n][i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void debug(int dataset[CHAR_MAX+1][CHAR_MAX+1], int size) {
    for (int i = 0; i < size; i++) {
        cout << i << " ";
        for (int j = 0; j < size; j++) {
            cout << dataset[i][j];
        }
        cout << endl;
    }
    cout << "\n";
}

int main() {
    int size = CHAR_MAX+1;
    int dataset[CHAR_MAX+1][CHAR_MAX+1] = {0};

    int past = 0;
    bool first = true;

    do {
        int n = getch();
        if (!first) dataset[past][n]++;  // perbaikan indexing
        first = false;
        past = n;
        cout << (char)n << " Next Char Prediction: " 
             << (char)get_val(dataset, n, size) << endl;
        //debug(dataset, size);
    } while (1);
}