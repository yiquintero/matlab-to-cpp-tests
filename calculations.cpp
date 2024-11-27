#include <iostream>
#include <Eigen/Dense>
#include <fstream>

using namespace Eigen;
using namespace std;

// Function to write a matrix to a CSV file
void writeMatrixToCSV(const string& filename, const MatrixXd& matrix) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < matrix.rows(); ++i) {
            for (int j = 0; j < matrix.cols(); ++j) {
                file << matrix(i, j);
                if (j < matrix.cols() - 1) file << ","; // Separate values by commas
            }
            file << "\n"; // Newline after each row
        }
        file.close();
        cout << "Matrix saved to " << filename << endl;
    } else {
        cerr << "Error opening file " << filename << endl;
    }
}

int main() {
    // Define matrices A and B
    MatrixXd A(3, 3);
    MatrixXd B(3, 3);

    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    B << 9, 8, 7,
         6, 5, 4,
         3, 2, 1;

#ifdef TESTING
    // Write matrices A and B to CSV files
    writeMatrixToCSV("A_cpp.dat", A);
    writeMatrixToCSV("B_cpp.dat", B);
#endif

    // Compute the product of A and B
    MatrixXd C = A * B;

#ifdef TESTING
    // Write the resulting matrix C to a CSV file
    writeMatrixToCSV("C_cpp.dat", C);
#endif

    return 0;
}