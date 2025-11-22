#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    int row, col;
    vector<vector<double>> matric;

public:
    // Constructor: initializes matrix and takes input from user
    Matrix(int row, int col) : row(row), col(col), matric(row, vector<double>(col)) {
        if (row <= 0 || col <= 0) {
            throw invalid_argument("Matrix dimensions must be positive");
        }
        this->Input();
    }

    // Overloaded constructor: initializes with a fixed value
    Matrix(int row, int col, int value) : row(row), col(col), matric(row, vector<double>(col)) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matric[i][j] = value;
            }
        }
    }

    // Input function for filling matrix
    void Input() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << "Enter Element at subscript [" << i+1 << "][" << j+1 << "]: ";
                cin >> matric[i][j];
            }
        }
        cout << "Matrix Input operation successful\n";
    }

    // Display function
    void display() const {
        for (int i = 0; i < row; i++) {
            cout << "[ ";
            for (int j = 0; j < col; j++) {
                cout << matric[i][j] << " ";
            }
            cout << "]\n";
        }
    }

    // Swap two rows (1-based indexing for user, converted to 0-based internally)
    void swapRow(int row1, int row2) {
        row1--; row2--; // converting to 0-based indexing
        if (row1 < 0 || row2 < 0 || row1 >= row || row2 >= row) {
            cout << "Invalid row indices\n";
            return;
        }
        swap(matric[row1], matric[row2]);
        cout << "Row swap performed successfully\n";
    }

    // Scale a row by multiplying every element with a factor
    void scaleRow(int targetRow, double factor) {
        if (factor == 0) {
            cout << "Error: Cannot scale row by 0.\n";
            return;
        }
        targetRow--; 
        if (targetRow < 0 || targetRow >= row) {
            cout << "Invalid row index\n";
            return;
        }
        for (int i = 0; i < col; i++) {
            matric[targetRow][i] *= factor;
        }
        cout << "Row scaled successfully\n";
    }

    // Add multiple of one row to another (targetRow = targetRow + multiple * sourceRow)
    void addRowMultiple(int targetRow, int sourceRow, double multiple) {
        if (multiple == 0) {
            cout << "Error: Cannot scale row by 0.\n";
            return;
        }
        targetRow--; sourceRow--; 
        if (targetRow < 0 || sourceRow < 0 || targetRow >= row || sourceRow >= row) {
            cout << "Invalid row indices\n";
            return;
        }
        for (int i = 0; i < col; i++) {
            matric[targetRow][i] += multiple * matric[sourceRow][i];
        }
        cout << "Row addition operation successful\n";
    }

    // Function to convert matrix into Row Echelon Form (Gaussian elimination)
    void toRowEchelon() {
        int pivotRow = 0; // the row we are currently working on
        for (int j = 0; j < col && pivotRow < row; j++) {
            int pivot = pivotRow;
            while (pivot < row && matric[pivot][j] == 0) {
                pivot++;
            }
            if (pivot == row) continue; 
            if (pivot != pivotRow) {
                swap(matric[pivot], matric[pivotRow]);
            }
            double pivotVal = matric[pivotRow][j];
            if (pivotVal != 1) {
                for (int k = 0; k < col; k++) {
                    matric[pivotRow][k] /= pivotVal;
                }
            }
            for (int r = pivotRow + 1; r < row; r++) {
                double factor = -matric[r][j];
                if (factor != 0) {
                    for (int k = 0; k < col; k++) {
                        matric[r][k] += factor * matric[pivotRow][k];
                    }
                }
            }
            pivotRow++;
        }
    }

    // Function to compute and return the inverse of the matrix (if it exists)
    Matrix inverse() const {
        if (row != col) {
            throw runtime_error("Inverse only defined for square matrices.");
        }
        int n = row;
        // Create augmented matrix [A | I]
        vector<vector<double>> aug(n, vector<double>(2 * n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                aug[i][j] = matric[i][j];
            }
            for (int j = n; j < 2 * n; j++) {
                aug[i][j] = (i == (j - n)) ? 1.0 : 0.0;
            }
        }
        // Perform Gauss-Jordan elimination
        for (int i = 0; i < n; i++) {
            // Find the pivot
            int pivot = i;
            for (int j = i + 1; j < n; j++) {
                if (abs(aug[j][i]) > abs(aug[pivot][i])) {
                    pivot = j;
                }
            }
            if (abs(aug[pivot][i]) < 1e-12) {
                throw runtime_error("Matrix is singular and cannot be inverted.");
            }
            if (pivot != i) {
                swap(aug[i], aug[pivot]);
            }
            // Scale pivot row
            double pivotVal = aug[i][i];
            for (int j = 0; j < 2 * n; j++) {
                aug[i][j] /= pivotVal;
            }
            // Eliminate other rows
            for (int r = 0; r < n; r++) {
                if (r != i) {
                    double factor = aug[r][i];
                    for (int j = 0; j < 2 * n; j++) {
                        aug[r][j] -= factor * aug[i][j];
                    }
                }
            }
        }
        // Extract inverse from augmented matrix
        Matrix inv(n, n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                inv.matric[i][j] = aug[i][j + n];
            }
        }
        return inv;
    }
};

// Main function
int main() {
    cout<<"Enter Order of Matrix (rows cols): ";
    int r, c;
    cin >> r >> c;
    Matrix mat(r, c);
    cout << "Initial Matrix:\n";
    mat.display();
    Matrix inverseMat(r, c,0);
    inverseMat=mat.inverse();
    cout << "Inverse Matrix:\n";
    inverseMat.display();

char m;
cin>>m;}
