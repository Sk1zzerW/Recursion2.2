#include <iostream>
using namespace std;

void shiftRight(int** arr, int rows, int cols, int shifts) {
    if (shifts == 0) return;

    int* lastCol = new int[rows];
    for (int i = 0; i < rows; i++) {
        lastCol[i] = arr[i][cols - 1];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = cols - 1; j > 0; j--) {
            arr[i][j] = arr[i][j - 1];
        }
        arr[i][0] = lastCol[i];
    }

    delete[] lastCol;
    shiftRight(arr, rows, cols, shifts - 1);
}

int main() {
    int rows = 3, cols = 4;
    int arr[3][4] = {
        {4, 5, 6, 7},
        {1, 2, 4, 1},
        {4, 5, 6, 9}
    };

    int* matrix[3];
    for (int i = 0; i < rows; i++) matrix[i] = arr[i];

    int shifts;
    cout << " количество сдвигов вправо ";
    cin >> shifts;

    shiftRight(matrix, rows, cols, shifts);

    cout << "матрица после сдвига вправо:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
