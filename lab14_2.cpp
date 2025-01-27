#include <iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);
void findLocalMax(const double [][N], bool [][N]);
void showMatrix(const bool [][N]);

int main() {
    double A[N][N];
    bool B[N][N];
    cout << "Input the matrix.....\n";
    inputMatrix(A);
    findLocalMax(A, B);
    cout << "Result is \n";
    showMatrix(B);
    return 0;
}

void inputMatrix(double matrix[][N]) {
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}

void findLocalMax(const double matrix[][N], bool result[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 or i == N - 1 or j == 0 or j == N - 1) {
                result[i][j] = false;
            } else {
                if (matrix[i][j] >= matrix[i - 1][j] &&
                    matrix[i][j] >= matrix[i + 1][j] &&
                    matrix[i][j] >= matrix[i][j - 1] &&
                    matrix[i][j] >= matrix[i][j + 1]) {
                    result[i][j] = true;
                } else {
                    result[i][j] = false;
                }
            }
        }
    }
}

void showMatrix(const bool A[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
